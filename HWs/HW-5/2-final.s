	area mycode, code, readonly
	export __main
	;entry

__main
	MOV R0, #0x34
	MOV R1, #0x36
	AND R0, R0, #0x0F 			; Mask 3
	AND R1, R1, #0x0F			; Mast 3
	ORR R2, R0, R1, LSL #4		; Left-shift r1 4 bits

HERE B HERE
	END