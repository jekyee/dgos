.section .text, "ax", @progbits

//scp_t syscall2(scp_t p0, scp_t p1, scn_t num);
.balign 16
.type syscall2,@function
.global syscall2
syscall2:
	.cfi_startproc

#ifdef __x86_64__

	mov %edx,%eax

#else

	mov 4+8*2(%esp),%eax

	movq 4+8*1(%esp),%xmm1
	movq 4+8*0(%esp),%xmm0

#endif

	syscall
	ret

	.cfi_endproc
