.globl _start

  # This program raises %rbx to the power of %rcx

.section .text

_start:
  # %rbx will hold the base
  movq $2, %rbx

  # %rcx will hold the exponent count
  movq $3, %rcx

  # Store the accumulated value in %rax
  movq $1, %rax

mainloop:
  # See if the exponent counter is zero. If so, jump to the end
  cmp $0, %rcx
  je complete

  # Multiply the accumulated value by the base
  mulq %rbx

  # Decrement the exponent counter
  decq %rcx

  # Loop back around
  jmp mainloop

complete:
  # Move the accumulated value to %rdi so we can return it
  movq %rax, %rdi

  # Call the "exit" system call
  movq $60, %rax
  syscall

