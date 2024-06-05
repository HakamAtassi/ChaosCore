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


async def functionalTest0(dut, dividend, divisor):

    #dividend = 20
    #divisor = 1

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

    await RisingEdge(dut.clock) # updated stage 0 regs
    dut.io_dividend_valid.value = 0
    dut.io_divisor_valid.value = 0


    # Test stage 2-31
    prevExpectedQuotient=0
    for stage in range(0, 32):
        await FallingEdge(dut.clock)

        prevExpectedQuotient = expectedQuotient
        expectedQuotient, expectedPartialRemainder, expectedWorkingDividend = nonRestoringDiv(divisor, expectedQuotient, expectedPartialRemainder, expectedWorkingDividend)

        if stage >=1:
            pass
            quotientRegsStage=getattr(dut, f"quotient_regs_{stage-1}")
            assert quotientRegsStage==prevExpectedQuotient, f"quotient Reg incorrect. Expected {int(expectedQuotient)} Got {int(quotientRegsStage)}"
            #print(f"{hex(int(quotientRegsStage))}, {hex(int(prevExpectedQuotient))}")

        partialRemainderStageOutputs=getattr(dut, f"partial_remainder_outputs_{stage}")
        #print(f"{stage}: {hex(int(partialRemainderStageOutputs))}, {hex(int(expectedPartialRemainder))}")
        assert partialRemainderStageOutputs==expectedPartialRemainder, f"Partial Remainder Wire incorrect. Expected {hex(int(expectedPartialRemainder))} Got {hex(int(partialRemainderStageOutputs))} on Wire {stage}"
        
        await RisingEdge(dut.clock)

    await FallingEdge(dut.clock)

    print(f"{dividend}/{divisor}={int(dut.io_quotient_bits)}")
    
    assert int(dut.io_quotient_valid) == 1, "Divider output not valid"
    assert int(dut.io_quotient_bits) == (dividend // divisor), "Divisor output not correct"

    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)

@cocotb.test()
async def testDividerRandom(dut):
    random.seed(0x42)

    #Note: Divider does not handle */0 internally

    await functionalTest0(dut, 0x8000_0000, 0x8000_0000)
    await functionalTest0(dut, 0x0000_0000, 0x7FFF_FFFF)
    await functionalTest0(dut, 0x0000_000F, 0x7FFF_FFFF)
    await functionalTest0(dut, 0x0000_0000, 0x3FFF_FFFF)
    await functionalTest0(dut, 0x0000_0000, 0x1FFF_FFFF)
    await functionalTest0(dut, 0x0000_0000, 0x0FFF_FFFF)
    await functionalTest0(dut, 0x0000_0001, 0x0FFF_FFFF)
    await functionalTest0(dut, 0, 0x01)
    await functionalTest0(dut, 0x0000_8000, 0x0000_8000)
    await functionalTest0(dut, 0x0001_0000, 0x0001_0000)
    await functionalTest0(dut, 0x0002_0000, 0x0002_0000)
    await functionalTest0(dut, 0x0100_0000, 0x0100_0000)
    await functionalTest0(dut, 0x1000_0000, 0x1000_0000)
    await functionalTest0(dut, 0x0000_0010, 0x0000_0010)
    await functionalTest0(dut, 0x0000_1000, 0x0000_1000)
    await functionalTest0(dut, 0x0000_0010, 0x0000_0001)
    await functionalTest0(dut, 0x0000_0042, 0x0000_0042)
    await functionalTest0(dut, 0xfff0_0042, 0x2)
    await functionalTest0(dut, 0xfff0_0042, 0x42)
    await functionalTest0(dut, 931, 7)
    await functionalTest0(dut, 15, 3)

    for i in range(100):
        divisor = random.randint(1,30)
        dividend = random.randint(divisor,10000)
        await functionalTest0(dut, dividend, divisor)
