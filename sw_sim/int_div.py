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

def nonRestoringDiv(dividend, divisor):
    partialRemainder = 0
    initialValue = dividend
    quotient = 0b0

    for _ in range(32):
        partialRemainderMSB = getMSB(partialRemainder)

        print(hex(partialRemainder))

        if partialRemainderMSB == 0:     # positive
            partialRemainder, initialValue = shiftIn(partialRemainder, initialValue)
            partialRemainder = partialRemainder - divisor
        else:                            # negative
            partialRemainder, initialValue = shiftIn(partialRemainder, initialValue)
            partialRemainder = partialRemainder + divisor


        partialRemainder = intToBin(partialRemainder)
        partialRemainderMSB = getMSB(partialRemainder)
        print(hex(partialRemainder))

        if(partialRemainderMSB): # negative
            quotient <<= 1
            quotient |= 0b0
        else:                   # positive
            quotient <<= 1
            quotient |= 0b1

        print(hex(partialRemainder))
    
    partialRemainder = intToBin(partialRemainder)
    partialRemainderMSB = getMSB(partialRemainder)

    if(partialRemainderMSB): # negative
        partialRemainder = partialRemainder + divisor

    return quotient



if __name__ == "__main__":

    print("Running restoring Div")

    for i in range(20000):

        op1 = random.randint(1,(2<<31)-1)
        op2 = random.randint(1,(2<<31)-1)

        result = restoringDiv(op1, op2)
        assert result == (op1//op2), f"Operation not valid for {op1} / {op2}. expected {op1//op2} ({op1/op2}) got {result} at iter {i}"

    print("Success!")

    print("Running Non-restoring Div")


    for i in range(20000):

        op1 = random.randint(1,(2<<31)-1) // 2
        op2 = random.randint(1,(2<<31)-1) // 2

    op1 = 0
    op2 = 0x7FFF_FFFF

    result = nonRestoringDiv(op1, op2)
    assert result == (op1//op2), f"Operation not valid for {op1} / {op2}. expected {op1//op2} ({op1/op2}) got {result} at iter {0}"

    print("nonRestoring Success!")
