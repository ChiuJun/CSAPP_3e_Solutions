.section .text
.global cread_alt
;尝试了其他版本的gcc以及其他的优化等级，无法生成条件传送指令
;把这个手写的链接以后运行会报 Segmentation fault (core dumped)
;真是奇怪
cread_alt:
  movl $0,%eax
  testq %rdi,%rdi
  cmovne (%rdi),%rax
  
  ret
  