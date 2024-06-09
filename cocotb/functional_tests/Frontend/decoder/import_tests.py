import os
import subprocess
import re
import importlib

module = os.path.basename(os.getcwd())

full_module_name = f"{module}_test"
configs = importlib.import_module(f"{full_module_name}").configs

print("Importing tests...")

def get_cocotb_testlist(cocotb_file):
    # read cocotb_file and return a list of all functions decorated with @cocotb.test()
    tests = []
    pattern = re.compile(r'@cocotb\.test\s*\(\s*\)\s*async def\s+(\w+)\s*\(dut\):')
    with open(cocotb_file, 'r') as file:
        content = file.read()
    matches = pattern.findall(content)
    tests.extend(matches)
    return tests

def generate_test_call(test):
    template = f"""def {test}():
        configs["testcase"] = "{test}"
        run(**configs)\n\n"""
    return template

def test_generate_test_list():
    file_name = f"{module}_test.py"
    with open(file_name, 'r') as file:
        lines = file.readlines()
    for i, line in enumerate(lines, start=1):
        if "# DO NOT MODIFY ANYTHING INCLUDING AND AFTER THIS LINE #\n" == line:
            line_number = i
            break

    lines=lines[:line_number]
    lines.append("\n")
    testlist = get_cocotb_testlist(configs["module"] + ".py")

    for test in testlist:
        lines.append(generate_test_call(test))

    with open(file_name, 'w') as file:
        file.writelines(lines)
    
test_generate_test_list()

print("Importing tests complete")