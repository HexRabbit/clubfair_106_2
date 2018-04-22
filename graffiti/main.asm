section .text
global _start   ;must be declared for linker (ld)
_start:             ;tells linker entry point
push 0x00007d65
push 0x72753534
push 0x3372745f
push 0x7433675f
push 0x646e345f
push 0x73336365
push 0x31705f67
push 0x6e317373
push 0x316d5f65
push 0x68745f64
push 0x6e31667b
push 0x534e4343
mov edx,48      ;message length
mov ecx,esp     ;message to write
mov ebx,1       ;file descriptor (stdout)
mov eax,4       ;system call number (sys_write)
int 0x80        ;call kernel

mov eax,1       ;system call number (sys_exit)
int 0x80        ;call kernel
