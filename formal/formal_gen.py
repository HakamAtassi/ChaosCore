import os

# Paths to the relevant files
filelist_path = '../hw/verilog/filelist.f'
verilog_dir = '../hw/verilog/'

# Read the contents of the filelist and append the directory path to each line
with open(filelist_path, 'r') as filelist_file:
    filelist_lines = [os.path.join(verilog_dir, line.strip()) for line in filelist_file if line.strip()]

# Get a list of all .sby files in the current directory
sby_files = [f for f in os.listdir('.') if f.endswith('.sby')]

for config_file_path in sby_files:
    # Read the contents of the configuration file
    with open(config_file_path, 'r') as config_file:
        config_lines = config_file.readlines()

    # Find the index of the [files] section
    files_section_index = None
    for index, line in enumerate(config_lines):
        if line.strip() == '[files]':
            files_section_index = index
            break

    # Prepare the new config lines with the updated [files] section
    if files_section_index is not None:
        new_config_lines = config_lines[:files_section_index + 1] + [line + '\n' for line in filelist_lines]
    else:
        new_config_lines = config_lines + ['\n[files]\n'] + [line + '\n' for line in filelist_lines]

    # Write the modified contents back to the configuration file
    with open(config_file_path, 'w') as config_file:
        config_file.writelines(new_config_lines)

    print(f"Successfully updated the configuration file: {config_file_path}")
