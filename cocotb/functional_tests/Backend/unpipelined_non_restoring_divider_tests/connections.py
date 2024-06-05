import random
import cocotb
from cocotb.triggers import Timer
from cocotb.triggers import RisingEdge, FallingEdge, Timer

async def generateClock(dut):
    while(1):
        dut.clock.value = 0
        await Timer(1, units="ns")
        dut.clock.value = 1
        await Timer(1, units="ns")


async def reset(dut):
    dut.reset.value = 0
    await RisingEdge(dut.clock)
    dut.reset.value = 1
    await RisingEdge(dut.clock)
    dut.reset.value = 0
    await RisingEdge(dut.clock)

def getBit(signal, bit):
    signal=int(signal)
    result= ((signal & (0b1<<bit)) >> bit)
    return result

def getTop32(val):
    return (val>>32) & 0xFFFF_FFFF

def getMSB(val):
    return (val & 0x8000_0000) > 0

def shiftIn(val1, val2):
    shiftInValue = getMSB(val2)
    val2 <<= 1
    val2 &= (0xFFFF_FFFF)

    val1 <<= 1
    val1 |= shiftInValue
    val1 &= (0xFFFF_FFFF)

    return val1,val2

def intToBin(val):
    result = val + 2**32 if val<0 else val
    return result & 0xFFFF_FFFF


def nonRestoringDiv(divisor, expectedQuotient, partialRemainder, workingDividend):
    # a complete calculation involves calling this function 32 times
    partialRemainderMSB = getMSB(partialRemainder)
    if partialRemainderMSB == 0:     # positive
        partialRemainder, workingDividend = shiftIn(partialRemainder, workingDividend)
        partialRemainder = partialRemainder - divisor
    else:                            # negative
        partialRemainder, workingDividend = shiftIn(partialRemainder, workingDividend)
        partialRemainder = partialRemainder + divisor

    partialRemainder = intToBin(partialRemainder)
    partialRemainderMSB = getMSB(partialRemainder)

    if(partialRemainderMSB): # negative
        expectedQuotient <<= 1
        expectedQuotient |= 0b0
    else:                   # positive
        expectedQuotient <<= 1
        expectedQuotient |= 0b1
    
    return expectedQuotient, partialRemainder, workingDividend


async def functionalTest0(dut, dividend, divisor, signed=0):

    expectedPartialRemainder=0
    expectedQuotient=0
    expectedWorkingDividend = dividend

    await cocotb.start(generateClock(dut)) 

    await RisingEdge(dut.clock)
    await reset(dut)

    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)

    dut.io_dividend_valid.value = 1
    dut.io_dividend_bits.value = dividend

    dut.io_divisor_valid.value = 1
    dut.io_divisor_bits.value = divisor
    
    dut.io_signed_valid.value = 1
    dut.io_signed_bits.value = signed

    await RisingEdge(dut.clock)
    dut.io_dividend_valid.value = 0
    dut.io_divisor_valid.value = 0


    await RisingEdge(dut.clock)

    for step in range(32):
        expectedQuotient, expectedPartialRemainder, expectedWorkingDividend = nonRestoringDiv(divisor, expectedQuotient, expectedPartialRemainder, expectedWorkingDividend)
        await FallingEdge(dut.clock)
        #print(f"expectedPartialRemainder {hex(expectedPartialRemainder)}")
        #assert int(dut.partial_remainder) == expectedPartialRemainder, f"Partial Remainder Invalid. Expected {hex(expectedPartialRemainder)}, got {hex(int(dut.partial_remainder))}"
        #assert int(dut.quotient) == expectedQuotient, f"Quotient Invalid. Expected {hex(expectedQuotient)}, got {hex(int(dut.quotient))}"
        #print(f"{hex(expectedPartialRemainder)}=={hex(int(dut.partial_remainder))}")
        #print(f"{hex(int(dut.quotient))}")
        #print(f"{hex(int(expectedQuotient))}=={hex(int(dut.quotient))}")


    #print(f"Quotient {expectedQuotient}")

    
    #print(f"{hex(int(expectedQuotient))}=={hex(int(dut.quotient))}")

    #print(f"{dividend}/{divisor}=={int(dut.io_quotient_bits)}")
    assert dut.io_quotient_valid == 1, "Output not valid"
    print(f"result: {hexToSigned(int(dut.io_quotient_bits))}")
    
    if(signed==False):
        assert int(dut.io_quotient_bits) == dividend//divisor, "Quotient incorrect"
    else:

        dividend=hexToSigned(dividend)
        divisor=hexToSigned(divisor)
        #print(int(dut.io_quotient_bits))
        #print(intToBin(dividend//divisor))
        
        sign=-1 if (divisor*dividend) < 1 else 1
        dividend=abs(dividend)
        divisor=abs(divisor)

        assert int(dut.io_quotient_bits) == intToBin((dividend//divisor)*sign), "Quotient incorrect"



def hexToSigned(val):
    if (val >> 31) & 0x1 == 0x1:  # Check if the sign bit is 1
        return -((~val & 0xFFFFFFFF) + 1)  # Mask to 32 bits before adding 1
    return val & 0xFFFFFFFF  # Mask to 32 bits for positive numbers as well

@cocotb.test()
async def testDividerRandom(dut):
    random.seed(0x42)

    #Note: Divider does not handle */0 internally


    print(f" {-1//10}: {-intToBin(1//10)}")

    await functionalTest0(dut, 10, 2)
    await functionalTest0(dut, 10, 10)
    await functionalTest0(dut, 42, 42)
    await functionalTest0(dut, 500, 41)
    await functionalTest0(dut, 4000, 41)
    await functionalTest0(dut, 4000, 5000)
    await functionalTest0(dut, 10000, 5000)
    await functionalTest0(dut, 10, 15)
    await functionalTest0(dut, 0x10, 0x10)
    await functionalTest0(dut, 0x0000_0001, 0x0000_0001)
    await functionalTest0(dut, 0x0000_1000, 0x0000_1000)
    await functionalTest0(dut, 0x1000_0000, 0x1000_0000)
    await functionalTest0(dut, 0x0001_0000, 0x0000_1000)
    await functionalTest0(dut, 0x8000_0000, 0x8000_0000)  
    await functionalTest0(dut, 0x8000_0001, 0x8000_0001)
    await functionalTest0(dut, 0x8000_0001, 0x8000_0000)
    await functionalTest0(dut, 0x8000_0000, 0x8000_0001)
    await functionalTest0(dut, 0xffff_ffff, 0xffff_ffff)
    await functionalTest0(dut, 0xffff_ffff, 0xffff_ffff)
    await functionalTest0(dut, 0x9000_0000, 0x9000_0000)
    await functionalTest0(dut, 0x3000_0001, 0x3000_0000)
    await functionalTest0(dut, 0xF000_0001, 0xF000_0000)

    # Test signed inputs
    await functionalTest0(dut, 0x8000_0001, 0x8000_0001, 1)
    await functionalTest0(dut, 0x7000_0001, 0x8000_0001, 1)
    await functionalTest0(dut, 0x8000_0000, 0x8000_0001, 1)
    await functionalTest0(dut, 0xfffffff6, 0x1, 1)
    await functionalTest0(dut, 0xfffffff6, 0xfffffff6, 1)
    await functionalTest0(dut, 0xfffffff6, 0xfffffff5, 1)
    await functionalTest0(dut, 0xfffffff3, 0x3, 1)
    await functionalTest0(dut, 1, 0xfffffff6, 1)
    await functionalTest0(dut, 0x464e4ebc, 0x3e1004b4, 0)



    #for i in range(100):
        #divisor = random.randint(1,(1<<31)-1)
        #dividend = random.randint(divisor,(1<<31)-1)
        #sign = random.randint(0,1)
        #await functionalTest0(dut, dividend, divisor, sign)
