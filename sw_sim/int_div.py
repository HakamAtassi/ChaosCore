import random

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

def restoringDiv(dividend, divisor):
 
    partialRemainder=0
    initialValue=dividend
    quotient = 0b0

    for _ in range(32):
        partialRemainder, initialValue = shiftIn(partialRemainder, initialValue)
        partialRemainder = partialRemainder - divisor

        if(partialRemainder >= 0):
            quotient <<= 1
            quotient |= 0b1
        else:
            partialRemainder = partialRemainder + divisor
            quotient <<= 1
            quotient |= 0b0

    return quotient

def intToBin(val):
    result = val + 2**32 if val<0 else val
    return result & 0xFFFF_FFFF

def nonRestoringDiv(dividend, divisor, signed = True):
    partialRemainder = 0
    initialValue = dividend
    quotient = 0b0

    for _ in range(32):
        partialRemainderMSB = getMSB(partialRemainder)

        if partialRemainderMSB == 0:     # positive
            partialRemainder, initialValue = shiftIn(partialRemainder, initialValue)
            partialRemainder = ((partialRemainder & 0xFFFF_FFFF) - (divisor & 0xFFFF_FFFF)) 
        else:                            # negative
            partialRemainder, initialValue = shiftIn(partialRemainder, initialValue)
            partialRemainder = ((partialRemainder & 0xFFFF_FFFF) + (divisor & 0xFFFF_FFFF))


        partialRemainder = intToBin(partialRemainder)
        partialRemainderMSB = getMSB(partialRemainder)
        #print(hex(partialRemainder))

        if(partialRemainderMSB): # negative
            quotient <<= 1
            quotient |= 0b0
        else:                   # positive
            quotient <<= 1
            quotient |= 0b1

        #print(hex(partialRemainder))
    
    partialRemainder = intToBin(partialRemainder)
    partialRemainderMSB = getMSB(partialRemainder)

    if(partialRemainderMSB): # negative
        partialRemainder = partialRemainder + divisor

    return quotient

def hexToSigned(val):
    if (val >> 31) & 0x1 == 0x1:  # Check if the sign bit is 1
        return -((~val & 0xFFFFFFFF) + 1)  # Mask to 32 bits before adding 1
    return val & 0xFFFFFFFF  # Mask to 32 bits for positive numbers as well

if __name__ == "__main__":

    print("Running restoring Div")

    random.seed(0x42)

    for i in range(20000):

        op1 = random.randint(1,(2<<31)-1)
        op2 = random.randint(1,(2<<31)-1)

        result = restoringDiv(op1, op2)
        assert result == (op1//op2), f"Operation not valid for {op1} / {op2}. expected {op1//op2} ({op1/op2}) got {result} at iter {i}"

    print("Success!")

    print("Running Non-restoring Div")


    op2 = 0xFFFF_FFFD   #
    op1 = 0x0000_0064   #



    result = nonRestoringDiv(op1, op2)
    print(f"{int(hexToSigned(op1))}/{int(hexToSigned(op2))}: {hex(result)}")

    #assert result == (op1//op2), f"Operation not valid for {hex(op1)} / {hex(op2)}. expected {op1//op2} ({op1/op2}) got {result} at iter {0}"


    #for i in range(20000):

    #    op1 = random.randint(1,(2<<31)-1) 
    #    op2 = random.randint(1,(2<<31)-1) >>1

    #    result = nonRestoringDiv(op1, op2)
    #    assert result == (op1//op2), f"Operation not valid for {hex(op1)} / {hex(op2)}. expected {op1//op2} ({op1/op2}) got {result} at iter {0}"

    #print("nonRestoring Success!")
