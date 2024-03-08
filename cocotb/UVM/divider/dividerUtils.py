

def getMSB(A):
    return (A>>31) & 0b1

def intToHex(A):
    if (A<0):
        return (0xFFFF_FFFF+A+1)&0xFFFF_FFFF
    else: 
        return A & 0xFFFF_FFFF

def hexToInt(A):
    if(getMSB(A)):
        return -(0xFFFF_FFFF - A + 1)
    else: 
        return A


def divisionPrediction(A, B, signed):
    if(signed):
        if(getMSB(A)):
            A=hexToInt(A)
        if(getMSB(B)):
            B=hexToInt(B)
    return _divisionPrediction(A, B)


def _divisionPrediction(A, B): # Inputs to this function are decimal
    
    ASign = (-1)**(A<0)
    BSign = (-1)**(B<0)

    # Flip signs since A//B doesnt work with negative values
    if(A<0):
        A=A*(-1)
    if(B<0):
        B=B*(-1)

    quotient = A//B
    quotient = quotient * (ASign*BSign)
    remainder = (A % B) * ASign

    return quotient, remainder

