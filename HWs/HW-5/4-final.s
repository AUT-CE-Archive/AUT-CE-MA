	area mycode, code, readonly
	export __main
	;entry

__main
	; Original values
	MOV R0, #2
	MOV R1, #6
	MUL R4, R0, R1
	
	; Make a copy	
	MOV R2, R0		; GCD
	MOV R3, R1		; LCM
	
	; LCM	
	UDIV R3, R4, R2	; stored at R3

gcd
	CMP r3, r2
	BLT less
	SUB r3, r3, r2
	B gcd
less
	SUB r2, r2, r3
	B gcd



HERE B HERE
	END