.globl _start

.section .text

_start:
  movq $60, %rax

loop_start:
  movq $8, %rdi
  
  jmp loop_start

  # This is never executed
  syscall
