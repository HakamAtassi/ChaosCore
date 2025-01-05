riscv32-unknown-elf-gcc -fno-common -fno-builtin-printf  -specs=htif_nano.specs -c hello.c -march=rv32im_zicsr -mabi=ilp32
riscv32-unknown-elf-gcc -static hello.o -o hello.riscv  -specs=htif_nano.specs -march=rv32im_zicsr -mabi=ilp32
riscv32-unknown-elf-objdump -d hello.riscv > hello.riscv.dump

#spike --isa=rv32im_zicsr hello.riscv --log-commits --isa=rv32im_zicntr

spike --log=test.txt --log-commits --isa=rv32im_zicsr  hello.riscv




#riscv64-unknown-elf-gcc -fno-common -fno-builtin-printf -specs=htif_nano.specs -c hello.c
#riscv64-unknown-elf-gcc -static -specs=htif_nano.specs hello.o -o hello.riscv
#spike hello.riscv



#${rvdir}/riscv32-unknown-elf-gcc -march=rv32im_zicsr -nostartfiles -std=gnu99 startup0.S "C/$name.c"  -O2 -ffreestanding -Wl,-Bstatic -o "elf/$name.elf"  -T $linker_script -Wextra -Wshadow -Wundef -Wpointer-arith -Wcast-qual -Wcast-align -Wwrite-strings -Wredundant-decls -Wpedantic -Wcast-qual -g -pedantic  -ffreestanding -Wcast-qual 
## Disassemble the ELF file to TXT
#${rvdir}/riscv32-unknown-elf-objdump -d -Mnumeric "elf/$name.elf" > "txt/$name.txt"
## Assemble the ELF file to binary
#${rvdir}/riscv32-unknown-elf-objcopy "elf/$name.elf" -O binary "bin/$name.bin"

#riscv64-unknown-elf-gcc -fno-common -fno-builtin-printf -specs=htif_nano.specs -c hello.c
#riscv64-unknown-elf-gcc -static -specs=htif_nano.specs hello.o -o hello.riscv
#spike hello.riscv