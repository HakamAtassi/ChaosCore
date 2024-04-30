
import pytest
from SimpleDRAM import *

@pytest.fixture
def dram():
    return SimpleDRAM()

def test_initialization():
    dram = SimpleDRAM()
    assert len(dram.memory) == 16<<10

def test_write_and_read(dram):
    address = 0
    data = 123

    dram.write(address, data, 1)
    assert dram.read(address, 1) == data  # Check if data read is the same as data written

def test_write_out_of_bounds(dram):
    address = 20<<10
    data = 123  # Byte to write
    size = 10

    with pytest.raises(ValueError):
        dram.write(address, data, size)

def test_read_out_of_bounds(dram):
    address = 20<<10
    size = 10
    with pytest.raises(ValueError):
        dram.read(address, size)

def test_write_read_4_bytes_all_addr(dram):
    for address in range(len(dram.memory)-4):
        data=0xdead_beef
        dram.write(address,size=4,data=data)
        read_data=dram.read(address, size=4)
        assert read_data == data

def test_write_data_manual(dram):
    dram.write(0, size=1, data=0x42)
    dram.write(2, size=1, data=0x77)
    assert dram.memory[0] == 0x42
    assert dram.memory[2] == 0x77


def test_write_data_manual(dram):
    dram.write(0, size=1, data=0x42)
    dram.write(2, size=1, data=0x77)
    assert dram.memory[0] == 0x42
    assert dram.memory[2] == 0x77


def test_overwrite_read(dram):
    dram.write(0, 0x99, 1)
    dram.write(0, 0xdeadbeef, 4)
    assert dram.read(0, 4) == 0xdeadbeef  # Check if data read is the same as data written


def test_randomize(dram):
    dram0 = SimpleDRAM()
    dram0.randomize()

    dram1 = SimpleDRAM()
    dram1.randomize()

    for i in range(1024):
        assert dram0.read(address=i, size=32) == dram1.read(address=i, size=32)

