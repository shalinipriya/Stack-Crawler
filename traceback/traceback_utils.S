.global get_frame_pointer
.global get_stack_pointer

get_frame_pointer:
	pushl %ebp
	movl %esp, %ebp
	movl (%ebp), %eax
	movl %ebp, %esp
	popl %ebp
	ret
get_stack_pointer:
	pushl %ebp
	movl %esp, %ebp
	movl %esp, %eax
	movl %ebp, %esp
	popl %ebp
	ret
