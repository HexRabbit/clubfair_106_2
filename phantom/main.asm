section .text
global _start   ;must be declared for linker (ld)
_start:             ;tells linker entry point
push 0x00000000
push 0xabcdd6fe
push 0xc692cfa3
push 0x9aabf4b9
push 0x9ba3f4a9
push 0x9aa9f4b8
push 0x9bb4f4fe
push 0xc6b89ef8
push 0xca92e2b6
push 0xf883e88e
mov edx,48      ;message length
mov ecx,esp     ;message to write
mov ebx,1       ;file descriptor (stdout)
mov eax,4       ;system call number (sys_write)
int 0x80        ;call kernel

mov eax,1       ;system call number (sys_exit)
int 0x80        ;call kernel
