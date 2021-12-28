	area mycode, code, readonly
	export __main
	;entry

__main
	MOV R0, #0	; First Fib number
	MOV R1, #1	; Second Fib number
	MOV R2, #1	; Third Fib number
	MOV R3, #6	; n
	
	SUB R3, R3, #3
Fib	CMP R3, #0
	
	MOV R4, R2
	ADD R2, R2, R1
	MOV R0, R1
	MOV R1, R4
	
	SUBS R3, R3, #1	; Decrement
	BNE Fib		; Repeat until R3=0

HERE B HERE
	END