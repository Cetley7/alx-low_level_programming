; Program: Hello Holberton (64-bit Assembly)

extern printf  ; Declare the external printf function

section .data
    msg db "Hello, Holberton", 0   ; Message to be printed
    fmt db "%s", 10, 0             ; Format string for printf

section .text
global main
main:
    push rbp          ; Save the base pointer
    mov rdi, fmt      ; Load format string into rdi
    mov rsi, msg      ; Load message into rsi
    mov rax, 0        ; Clear rax to indicate no floating-point args
    call printf       ; Call the printf function

    pop rbp           ; Restore the base pointer
    mov rax, 0        ; Return 0 from the main function
    ret               ; Return to the calling code

