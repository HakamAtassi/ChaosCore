# ChaosCore


### What is ChaosCore?

ChaosCore is a Speculative Out-of-Order RV32G core aimed at exploring the tradeoffs resulting from various security and performance considerations. ChaosCore is also designed to run out of the box and includes a slew of benchmarks and tests for demonstration and analysis. 

### Docker

You may have noticed the existence of a Dockerfile. This is because this entire repository is designed to be packaged into a system that can be run in a containerized environment deployable on any system. See [Running ChaosCore](#running-chaoscore) for detailed information on running ChaosCore. 

### Directories

```cocotb``` contains all hardware tests. In this folder exist two sub-dirs. ``` functional_tests ``` contains basic tests for various parts of the design. These
tests do not have any particular structure. ```UVM``` tests contain more rigorous tests for the various modules. System level tests, for instance, would exist there. These tests use PyUVM + Cocotb for the test 'front-end' and Verilator V5.006 for the 'back-end'.

```doc``` contains important details about various aspects of the design. It includes, for instance, details about the architecture as well as the naming conventions used throughout the various design files. It also includes some information about test strategies used to verify the design. 

```hw``` contains the design files. The ```chisel``` sub-folder contains the chisel code. The ```verilog``` sub-folder contains both the auto-generated verilog files as well as custom (and possibly recycled) hand written verilog files. 

```py``` contains related python files, libraries, models, and utils used for both the design and verification. 


### Running ChaosCore

- TODO: 