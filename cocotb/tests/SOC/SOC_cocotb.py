import sys
import random
import numpy as np
from cocotb.clock import Clock
import cocotb
from cocotb.triggers import RisingEdge, FallingEdge, ReadOnly, ReadWrite, Timer
from pathlib import Path
import os

from cocotb_utils import *
from SOC_TB import *
from L1_caches import instruction_cache_dut

import logging
import glob


async def test_riscv_tests(dut, riscv_test):
    # Set seed
    random.seed(0x42)

    # Start clock generation
    await cocotb.start(generateClock(dut))

    # Path to binaries
    binary_path = f"/home/hakam/Repos/ChaosCore/binaries/bin/{riscv_test}"

    SOC = SOC_TB(dut, binary=binary_path)  # Construct testbench
    await SOC.reset()                         # Reset

    # Simulate for 5000 clock cycles
    for _ in range(3000):
        await SOC.clock()

    # Check if the test passed and print result
    if SOC.riscv_test_pass():
        print(f"RISCV test {os.path.basename(riscv_test)} passed")
    else:
        print(f"RISCV test {os.path.basename(riscv_test)} failed")



#@cocotb.test()
#async def test_add(dut):
    #await test_riscv_tests(dut, "rv32ui-p-add.bin") # good

#@cocotb.test()
#async def test_addi(dut):
    #await test_riscv_tests(dut, "rv32ui-p-addi.bin") # good

#@cocotb.test()
#async def test_and(dut):
    #await test_riscv_tests(dut, "rv32ui-p-and.bin") # good

#@cocotb.test()
#async def test_andi(dut):
    #await test_riscv_tests(dut, "rv32ui-p-andi.bin") # good

#@cocotb.test()
#async def test_auipc(dut):
    #await test_riscv_tests(dut, "rv32ui-p-auipc.bin") # good

#@cocotb.test()
#async def test_beq(dut):
    #await test_riscv_tests(dut, "rv32ui-p-beq.bin") # good

#@cocotb.test()
#async def test_bge(dut):
    #await test_riscv_tests(dut, "rv32ui-p-bge.bin") # good

#@cocotb.test()
#async def test_bgeu(dut):
    #await test_riscv_tests(dut, "rv32ui-p-bgeu.bin") # good

#@cocotb.test()
#async def test_blt(dut):
    #await test_riscv_tests(dut, "rv32ui-p-blt.bin") # good

#@cocotb.test()
#async def test_bltu(dut):
    #await test_riscv_tests(dut, "rv32ui-p-bltu.bin") # good

#@cocotb.test()
#async def test_bne(dut):
    #await test_riscv_tests(dut, "rv32ui-p-bne.bin") # good

#@cocotb.test()
#async def test_fence_i(dut):
    #await test_riscv_tests(dut, "rv32ui-p-fence_i.bin") # failed

#@cocotb.test()
#async def test_jal(dut):
    #await test_riscv_tests(dut, "rv32ui-p-jal.bin") # good

#@cocotb.test()
#async def test_jalr(dut):
    #await test_riscv_tests(dut, "rv32ui-p-jalr.bin") # good

#@cocotb.test()
#async def test_lb(dut):
    #await test_riscv_tests(dut, "rv32ui-p-lb.bin") # good

#@cocotb.test()
#async def test_lbu(dut):
    #await test_riscv_tests(dut, "rv32ui-p-lbu.bin") # good

#@cocotb.test()
#async def test_lh(dut):
    #await test_riscv_tests(dut, "rv32ui-p-lh.bin") # good

#@cocotb.test()
#async def test_lhu(dut):
    #await test_riscv_tests(dut, "rv32ui-p-lhu.bin") # good

#@cocotb.test()
#async def test_lui(dut):
    #await test_riscv_tests(dut, "rv32ui-p-lui.bin") # good

#@cocotb.test()
#async def test_lw(dut):
    #await test_riscv_tests(dut, "rv32ui-p-lw.bin") # good

#@cocotb.test()
#async def test_ma_data(dut):
    #await test_riscv_tests(dut, "rv32ui-p-ma_data.bin") # failed

#@cocotb.test()
#async def test_or(dut):
    #await test_riscv_tests(dut, "rv32ui-p-or.bin") # good

#@cocotb.test()
#async def test_ori(dut):
    #await test_riscv_tests(dut, "rv32ui-p-ori.bin") # good

#@cocotb.test()
#async def test_sb(dut):
    #await test_riscv_tests(dut, "rv32ui-p-sb.bin") # good

#@cocotb.test()
#async def test_sh(dut):
    #await test_riscv_tests(dut, "rv32ui-p-sh.bin") # good

#@cocotb.test()
#async def test_simple(dut):
    #await test_riscv_tests(dut, "rv32ui-p-simple.bin") # good

#@cocotb.test()
#async def test_sll(dut):
    #await test_riscv_tests(dut, "rv32ui-p-sll.bin") # good

#@cocotb.test()
#async def test_slli(dut):
    #await test_riscv_tests(dut, "rv32ui-p-slli.bin") # good

#@cocotb.test()
#async def test_slt(dut):
    #await test_riscv_tests(dut, "rv32ui-p-slt.bin") # good

#@cocotb.test()
#async def test_slti(dut):
    #await test_riscv_tests(dut, "rv32ui-p-slti.bin") # good

#@cocotb.test()
#async def test_sltiu(dut):
    #await test_riscv_tests(dut, "rv32ui-p-sltiu.bin") # good

#@cocotb.test()
#async def test_sltu(dut):
    #await test_riscv_tests(dut, "rv32ui-p-sltu.bin") # good

#@cocotb.test()
#async def test_sra(dut):
    #await test_riscv_tests(dut, "rv32ui-p-sra.bin") # good

#@cocotb.test()
#async def test_srai(dut):
    #await test_riscv_tests(dut, "rv32ui-p-srai.bin") # good

#@cocotb.test()
#async def test_srl(dut):
    #await test_riscv_tests(dut, "rv32ui-p-srl.bin") # good

#@cocotb.test()
#async def test_srli(dut):
    #await test_riscv_tests(dut, "rv32ui-p-srli.bin") # good

#@cocotb.test()
#async def test_sub(dut):
    #await test_riscv_tests(dut, "rv32ui-p-sub.bin") # good

#@cocotb.test()
#async def test_sw(dut):
    #await test_riscv_tests(dut, "rv32ui-p-sw.bin") # good

#@cocotb.test()
#async def test_xor(dut):
    #await test_riscv_tests(dut, "rv32ui-p-xor.bin") # good

#@cocotb.test()
#async def test_xori(dut):
    #await test_riscv_tests(dut, "rv32ui-p-xori.bin") # good



@cocotb.test()
async def test_riscv_tests(dut):
    # Set seed
    random.seed(0x42)

    # Start clock generation
    await cocotb.start(generateClock(dut))

    # Path to binaries
    binary_path = "/home/hakam/Repos/ChaosCore/binaries/bin/"

    # Iterate over all rv32ui-p *.bin files
    for riscv_test_bin in glob.glob(os.path.join(binary_path, "rv32ui-p*.bin")):
        SOC = SOC_TB(dut, binary=riscv_test_bin)  # Construct testbench
        await SOC.reset()                         # Reset

        # Simulate for 5000 clock cycles
        for _ in range(7000):
            await SOC.clock()

        # Check if the test passed and print result
        if SOC.riscv_test_pass():
            print(f"RISCV test {os.path.basename(riscv_test_bin)} passed")
        else:
            print(f"RISCV test {os.path.basename(riscv_test_bin)} failed")



@cocotb.test()
async def test_reset(dut):
    # Set seed
    random.seed(0x42)

    # Start lock
    await cocotb.start(generateClock(dut))

    # Bring up TB
    #SOC = SOC_TB(dut, binary="/home/hakam/Repos/ChaosCore/binaries/bin/vec_add.bin")     # construct TB
    #SOC = SOC_TB(dut, binary="/home/hakam/Repos/ChaosCore/binaries/bin/if.bin")     # construct TB
    #SOC = SOC_TB(dut, binary="/home/hakam/Repos/ChaosCore/binaries/bin/hello_world.bin")     # construct TB
    #SOC = SOC_TB(dut, binary="/home/hakam/Repos/ChaosCore/binaries/bin/bubble_sort.bin")     # construct TB
    #SOC = SOC_TB(dut, binary="/home/hakam/Repos/ChaosCore/binaries/bin/qsort.bin")     # construct TB
    SOC = SOC_TB(dut, binary="/home/hakam/Repos/ChaosCore/binaries/bin/towers.bin")     # construct TB
    #SOC = SOC_TB(dut, binary="/home/hakam/Repos/ChaosCore/binaries/bin/printf.bin")     # construct TB
    #SOC = SOC_TB(dut, binary="/home/hakam/Repos/ChaosCore/binaries/bin/multiply.bin")     # construct TB
    #SOC = SOC_TB(dut, binary="/home/hakam/Repos/ChaosCore/binaries/bin/test.bin")     # construct TB
    #SOC = SOC_TB(dut, binary="/home/hakam/Repos/ChaosCore/binaries/bin/branch_test.bin")     # construct TB

    #SOC = SOC_TB(dut, binary="/home/hakam/Repos/ChaosCore/binaries/bin/beq.bin")     # construct TB
    #SOC = SOC_TB(dut, binary="/home/hakam/Repos/ChaosCore/binaries/bin/instret.bin")     # construct TB

    #SOC = SOC_TB(dut, binary="/home/hakam/Repos/ChaosCore/binaries/bin/rv32ui-p-srai.bin")     # construct TB
    #SOC = SOC_TB(dut, binary="/home/hakam/Repos/ChaosCore/binaries/bin/rv32ui-p-xori.bin")     # construct TB
    await SOC.reset()                      # Reset

    for _ in range(1_000_000):
    #while 1:
        await SOC.clock()

    assert False

    

