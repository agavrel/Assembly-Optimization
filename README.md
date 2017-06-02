# Assembly_Optimization
Repository to compare speed performance of c code

int a = 42;
'''
xorl%eax, %eax
movl$0, -4(%rbp)
movl$42, -8(%rbp)
'''

a = 0;
'''
movl$0, -8(%rbp)
'''

a ^= a;
'''
movl-8(%rbp), %ecx
xorl-8(%rbp), %ecx
movl%ecx, -8(%rbp)
'''

return (0);
'''
popq%rbp
'''

## Conclusion
While a xor a is indeed faster in assembly (proof : used at assembly level with xorl%eax, %eax)
it is slower if used in C.
