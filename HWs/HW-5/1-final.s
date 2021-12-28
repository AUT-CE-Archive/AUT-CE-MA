	area mycode, code, readonly
	export __main
	;entry

__main	
	MOV R2, #32			; 32 iterations	
	MOV R1, #0			; init result
	MOV R0, #113		; Our number
	MOV R3, R0			; Make a copy of our number
	MOV R4, #0			; Default is not palindrome
loop	
	LSLS R0, R0, #1	; copy R0[31] into C and shift R0 left
	RRX  R1, R1		; shift R1 right and copy C into R1[31]
	
	SUBS R2, #1		; decrement loop counter
	BNE  loop
	
	; Compare the two
	CMP R1, R3
	BEQ palindrome

palindrome MOV R4, #1	
	
HERE B HERE
	END