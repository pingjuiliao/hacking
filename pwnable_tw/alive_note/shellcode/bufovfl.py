#!/usr/bin/env python3
from pwn import *

p = process("./shellcode.exe")
context.arch = "i386"
context.terminal = ["tmux", "splitw", "-h"]

gdb.attach(p)
p.sendline(cyclic(0x200))
p.interactive()

