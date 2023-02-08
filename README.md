# pwnables
A repo of solving pwnables.  
Making the challegnes self-explained by the script is my goal


## file structures
Each challenge resides in its own directory
```
\workdir
|-\given        # challenge given
| |-pwnable.exe
| |-libc-2.31.so
| |-Dockerfile
| |-...
|
|-exploit.py    # exploit script
|-flag.txt      # flag file for testing
|
|-\shellcode    # shellcoding
| |-shellcode.S
| |-Makefile
```

## setup
This repo uses python3 pwntools 
```
pip3 install pwn
```

## CLI-Tools cheatsheets

### ROPgadgets
```
ROPgadget --binary ./main.exe | grep ret
ROPgadget --binary ./libc.so.6 | grep ret
ROPgadget --binary ./libc.so.6 --opcode 0f05c3 # syscall; ret;
```

### pwninit
TODO

### docker
TODO

### ghidra
TODO

### gdb
finding PIE starting address
```
gdb-peda$ b *0x1337
# it will failed
gdb-peda$ info proc mapping
gdb-peda$ b *0x5655xxx + 0x1337
```
