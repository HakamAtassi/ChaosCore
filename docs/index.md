---
title: ChaosCore
layout: home
nav_order: 1
has_children: true
---


# ChaosCore

<div style="display: flex; align-items: flex-start;">
  <div style="flex: 1; padding-right: 20px;">
    <p>ChoasCore is a security oriented RV32GC core implemented in Chisel. It is aggressively parameterizeable, Out-of-Order, superscalar, and synthesizeable.  ChaosCore can be parametrized to generate verilog targeting either FPGAs or ASICs.</p>

    <p>Beyond being able to adjust basic core parameters such as the core's fetch width, execution engine, and branch predictors, ChaosCore more importantly places an emphasis on demonstrating the impacts security features may have on the performance of a real Out-of-Order processor.</p>

    <h3>What is done:</h3>
    <ul>
      <li>Dhrystone runs succesfully.</li>
      <li>Riscv-tests passed.</li>
      <li>Prediction accuracy of >90% (Workload?)</li>
      <li>Exceptions, interrupts, & privilage.</li>
    </ul>

    <h3>What is to be done:</h3>
    <ul>
      <li>Float & Double extensions</li>
      <li>Compressed instructions</li>
      <li>Virtual Memory</li>
    </ul>

  </div>

  <div style="max-width: 40%;">
    <img src="drawio/Core.drawio.svg" style="max-width: 100%;"/>
  </div>
</div>



# Setup
The ChaosCore repository attempts to be as lean as possible to keep the setup process smooth. As part of this effort, this repository provides three streams for new users:

1. Profile Pre-built configurations.
2. Build, simulate, and synthesize custom configurations.
3. Develop. 


### 1. Profile Pre-Built Configurations

{: .note }
> This process should take less than 3 minutes. We recommend all prospective users go through this stream.

This option is for those interested in quickly seeing the core in action. It runs a series of pre-built, pre-verilated, and pre-compiled core configurations against similarly pre-built binaries to showcase the core's features and performance. There's little to no setup required.

### 2. Build, Simulate, and Synthesize Custom Configurations

This option is for users who want to tweak the core's parameters, run it with custom binaries, or even deploy it on an FPGA. It’s more involved than the first stream but still relatively lightweight.

### 3. Develop

This option is aimed at developers and provides a deep dive into the core from both architectural and implementation perspectives.


# Setup (All Streams)

This repository contains several external dependencies. Currently, these are riscv-tests and verilog-axi. Also, this repository uses python for interconnect generation, simulation, and module modeling. To manage these dependencies, we will assume the use of a python venv. Run:

```
git submodule update --init --recursive
python3 -m venv venv
source venv/bin/activate
pip3 install -r requirements.txt
```




# Profile Pre-Built Configurations

Once the ChaosCore has been recursively cloned, the different versions of ChaosCore can be either tested or profiled. 

## Test Pre-Build Configurations

To run tests on the Pre-Built ChaosCore configurations, run: 

```
source venv/bin/activate  # source the python venv
cd cocotb/prebuilt        # cd into the simulation env
./profile test          
```

Here, the command `./profile` command is a bash script that ???


Alternatively, running `./profile profile` will run the same prebuilt verilator executables but against profiling benchmarks as opposed to community self-checking tests. 


### TODO: 

what should these profiling scripts be?


Maybe one that profiles the ROB size, one that determines the cache sizes, one that tests the BP, etc...







# Requirements 

It is assumed that the following tools have already been installed. The versions for Verilator and Chisel are a requirement.

1. Verilator 5.024
2. Chisel 6.0
3. Python3

All other requirements are included as part of the setup process for this repository.


## Python venv

This repo uses python for generating interconnect and simulation, among other things. Consequenrly, a Python venv is used to contain and manage dependancies. 

To setup a python venv, run:

```
python3 -m venv venv
```

Then install the required libraries in this venv:

```
pip3 install -r requirements.txt
```

# Installing RISCV GNU:

This repository provides pre-compiled binaries to run a simulation of the SoC without the overhead of setting up and installing a RISCV toolchain. Feel free to skip this step if you do not anticipate compiling custom binaries for ChaosCore.

To build RISCV-GNU, run the following commands: 
```
sudo apt-get install autoconf automake autotools-dev curl python3 python3-pip libmpc-dev libmpfr-dev libgmp-dev gawk build-essential bison flex texinfo gperf libtool patchutils bc zlib1g-dev libexpat-dev ninja-build git cmake libglib2.0-dev libslirp-dev

git clone https://github.com/riscv-collab/riscv-gnu-toolchain
cd riscv-gnu-toolchain
./configure --prefix=/opt/riscv --with-arch=rv32gc_zicsr_zifencei --with-abi=ilp32 --enable-multilib
sudo make -j12
```
then add 
```
export PATH="$PATH:/opt/riscv/bin"
```
to your .bashrc

# Installing SPIKE

TODO


# Generating ChaosCore

1) generating the core itself based on params

2) Generating the interconnect (fix?)

3) Generating the SoC


# Running a Simulation


...



# Suggestions to Devs
1) Set vscode to ignore everything in .gitignore (way too many junk files are generated by all the tools for the repo to be managable without hiding some)



