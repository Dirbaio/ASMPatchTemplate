@ Disable Overlay signature checking.
@ This should allow us to use ASM hacks freely in Download Play.
@ Hook address is NSMB-specific but it can be changed for all games.
@ It simply hooks FS_CompareDigest to return always true.

nsub_0206AE18:
	mov r0, #1
	bx lr
