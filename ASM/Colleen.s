;colleen comment outside

section .text
global main
extern printf

print:
    push rbp
    mov rbp, rsp
    mov rdi, format
    mov rsi, format
    mov rdx, 10
    mov rcx, 34
    call printf
    mov rsp, rbp
    pop rbp
    ret

main:     ;comment in main
    push rbp
    mov rbp, rsp
    call print
    xor rax, rax
    pop rbp
    ret

section .data
format:
db ";colleen comment outside%2$c%2$csection .text%2$cglobal main%2$cextern printf%2$c%2$cprint:%2$c    push rbp%2$c    mov rbp, rsp%2$c    mov rdi, format%2$c    mov rsi, format%2$c    mov rdx, 10%2$c    mov rcx, 34%2$c    call printf%2$c    mov rsp, rbp%2$c    pop rbp%2$c    ret%2$c%2$cmain:     ;comment in main%2$c    push rbp%2$c    mov rbp, rsp%2$c    call print%2$c    xor rax, rax%2$c    pop rbp%2$c    ret%2$c%2$csection .data%2$cformat:%2$cdb %3$c%1$s%3$c, 0", 0