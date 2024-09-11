for elffile in elf/*.elf;
do
    filename=$(basename -- "$elffile")
    name="${filename%.*}"
    echo "Generating spike trace for $name"

    # Run spike with a 10-second timeout
    timeout 10s spike -m0x80000000:0x90000000,0x80000:0x90000 --log=spike_traces/$name.log --log-commits --isa=rv32i elf/$name.elf

    # Check if spike was terminated by timeout
    if [ $? -eq 124 ]; then
        echo "Spike timed out for $name after 10 seconds"
    fi
done