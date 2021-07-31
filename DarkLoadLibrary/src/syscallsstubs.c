/* Ported syscallsstubs.asm to inline C syntax */

__asm__(
    ".intel_syntax\n"
    "NtProtectVirtualMemory:\n"
    "mov [rsp +8], rcx\n" // Save registers.
    "mov [rsp+16], rdx\n" 
    "mov [rsp+24], r8\n" 
    "mov [rsp+32], r9\n" 
    "sub rsp, 0x28\n" 
    "mov ecx, 0x0079D1B09\n" // Load function hash into ECX.
    "call SW2_GetSyscallNumber\n" // Resolve function hash into syscall number.
    "add rsp, 0x28\n" 
    "mov rcx, [rsp +8]\n" // Restore registers.
    "mov rdx, [rsp+16]\n" 
    "mov r8, [rsp+24]\n" 
    "mov r9, [rsp+32]\n" 
    "mov r10, rcx\n" 
    "syscall\n" // Invoke system call.
    "ret\n" 
);

__asm__(
    ".intel_syntax\n"
    "NtAllocateVirtualMemory:\n"
    "mov [rsp +8], rcx\n" // Save registers.
    "mov [rsp+16], rdx\n"
    "mov [rsp+24], r8\n"
    "mov [rsp+32], r9\n"
    "sub rsp, 0x28\n"
    "mov ecx, 0x00B9D010F\n" // Load function hash into ECX.
    "call SW2_GetSyscallNumber\n" // Resolve function hash into syscall number.
    "add rsp, 0x28\n"
    "mov rcx, [rsp +8]\n" // Restore registers.
    "mov rdx, [rsp+16]\n"
    "mov r8, [rsp+24]\n"
    "mov r9, [rsp+32]\n"
    "mov r10, rcx\n"
    "syscall\n" // Invoke system call.
    "ret\n"
);