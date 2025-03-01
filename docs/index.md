---
title: ChaosCore
layout: home
nav_order: 1
has_children: true
---


# ChaosCore


<div style="display: flex; align-items: flex-start;">
  <div style="flex: 1; padding-right: 20px;">
    <p>ChoasCore is a security oriented RV32GC core implemented in Chisel. It is aggressively parameterizable, Out-of-Order, superscalar, and synthesizeable. Beyond it's parameterizability, ChaosCore places an emphasis on demonstrating the impacts security features may have on the performance of a real Out-of-Order processor. </p>

    <h3>Overview</h3> 
    <ul>
      <li>Passes RISCV isa tests</li>
      <li>Runs RISCV benchmarks (dhrystone, qsort, etc...)</li>
      <li>Supports Machine, Supervisor and User privileges levels</li>
      <li>Integrates with Chipyard CLINT/PLIC interrupt controllers</li>
    </ul>



<!---
    <h3>Security Features:</h3>
    <ul>
      <li>This is needed</li>
    </ul>

    <h3>Performance optimizations:</h3>
    <ul>
      <li>do we need this?</li>
    </ul>
-->

  </div>

  <div style="max-width: 40%;">
    <img src="drawio/Core.drawio.svg" style="max-width: 100%;"/>
  </div>
</div>


# Setup
ChaosCore depends on a fork of the Chipyard Ecosystem. If already familiar with Chipyard, the setup process should seem very familiar. 



## Pre-requisites

Chipyard uses Conda to manage its many dependencies and packages. The first steps to get set-up involve installing Miniforge (a minimal installer for conda) and libmamba (a fast dependency solver for conda).

To install Miniforge, follow the instructions [here](https://github.com/conda-forge/miniforge/#download). Then, install libmamba by running the following commands: 

```
conda install -n base conda-libmamba-solver
conda config --set solver libmamba
```

With Conda and Libmamba installed, run the following commands:
```
conda install -n base conda-lock==1.4.0
conda activate base
```

## ChaosCore-Chipyard & ChaosCore

{: .important }
> This fork of Chipyard adds configuration specific to ChaosCore. As such, it will not work standalone (i.e., without ChaosCore).

ChaosCore depends on a fork of Chipyard. Chipyard provides a variety of useful IP for RISCV related development, including interconnects, periphirals, interrupt controllers, and more. Chipyard also provides RISCV GNU, Spike, and Verilator. In other words, installing Chipyard's packages should (for the most part) bootstrap a development environment for ChaosCore and other RISCV Cores. To get started, clone the ChaosCore-chipyard fork.

```
git clone https://github.com/HakamAtassi/ChaosCore-chipyard.git
cd ChaosCore-chipyard
git clone https://github.com/HakamAtassi/ChaosCore.git generators/ChaosCore # Add ChaosCore to generators
```

Next, install the Chipyard packages. This process may take ~10-20 minutes. 
```
./build-setup.sh -s 6 -s 7 -s 8 -s 9  # Skip firemarshal and linux stuff
source env.sh # Don't forget to source!
```

# Running a Simulation!
The combination of Chipyard and ChaosCore provides everything you need to run a workload on the core. A set of pre-compiled binaries are provided in `toolchains/riscv-tools/ChaosCore-riscv-tests`. To run a workload on ChaosCore:

```
cd sims/verilator
make run-binary-debug CONFIG=ChaosCoreConfig BINARY=$CY_DIR/toolchains/riscv-tools/ChaosCore-riscv-tests/benchmarks/dhrystone.riscv LOADMEM=1 -j 16
```


# Need Help?

* For issues in the setup process, check the chipyard [chipyard mailing list](https://groups.google.com/g/chipyard). For further help, general inquires, or suggestions, please [open an issue](https://github.com/HakamAtassi/ChaosCore/issues).