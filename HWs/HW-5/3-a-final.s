	area mycode, code, readonly
	export __main
	;entry

OUR_DATA DCB +1, -1, +2

__main
	LDR R0, =OUR_DATA
	LDRSB R4, [R0]
	LDRSB R5, [R0, #4]
	LDRSB R6, [R0, #8]
	MOV R4, #3
	MOV R5, #5
	MOV R6, #1
	
L1	CMP R5, R4
	BLS OVER			; If (#0<=R7) Break
	ADD R1, R4, R5
	CMP R1, #0
	BHI First
	SMULL R8, R5, R5, R6
	MOV R3, #2
	SUB R4, R3, R5

First
	SUB R6, R6, R4
	SUB R4, R4, R4
	SUB R4, R4, R4
	
OVER

HERE B HERE
	END