# FIXME: TOS does not wrap around

class RAS:

    def __init__(self, entries):
        self.entires = entries
        self.TOS = 0
        self.NEXT = 0

        self.addr_mem = [0]*entries
        self.NOS_mem = [0]*entries

    def increment_NEXT(self):
        self.NEXT = self.NEXT + 1
        self.NEXT = self.NEXT % self.entires

    def push(self, addr):
        self.addr_mem[self.NEXT] = addr
        self.NOS_mem[self.NEXT] = self.TOS
        self.TOS = self.NEXT
        self.increment_NEXT()

    def pop(self):
        ret_addr = self.addr_mem[self.TOS]
        self.TOS = self.NOS_mem[self.TOS]
        return ret_addr

    def revert(self, NEXT, TOS):
        self.NEXT = NEXT
        self.TOS = TOS

    def tos(self):
        return self.addr_mem[self.TOS]