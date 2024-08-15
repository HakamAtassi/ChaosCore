import os
import glob

def generate_typedef():
    """"""
    struct_name = "Test"
    print("typedef struct{")
    # type definitions here
    print("}")
    print(f"{struct_name};")

class chisel_repo:
    """Convert chisel bundles and enums to verilog """
    def __init__(self, src_dir):
        self.src_dir = src_dir
        self.scala_files = self.get_scala_files()

    def get_scala_files(self):
        """glob for all .scala files"""
        scala_files = []
        for root, dirs, files in os.walk(self.src_dir):
            for file in files:
                if file.endswith('.scala'):
                    scala_files.append(os.path.join(root, file))
        return scala_files


