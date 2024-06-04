
# Funtional Tests

Feel free to use this dir as a template for functional tests. 


## Usage:

1) Copy the directory into somewhere that makes sense
2) Update the `dff` part of each file to an appropraite name.
3) Update the name of the file to the SAME name you chose in 2) 
4) Update all configs, directories, etc in \<name\>_test.py
5) Update the \<name\>_dut.py wrapper class with whatever functionality you find useful. Update its name as well
6) Finally, write your tests in the \<name\>_cocotb.py file. 
7) Run `python3 import_tests.py` to copy your cocotb tests into the <name>_tests.py file automatically
8) Run `pytest` to run all tests or `pytest \<name\>_test.py::\<testname\>` to run a specific test


### Note: 
ALL cocotb tests MUST start with test_\<testname\>, ex:

```
@cocotb.test()
async def test_passthrough(dut):
    assert 1==1, "Error"
```
