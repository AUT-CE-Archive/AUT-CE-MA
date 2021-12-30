	area mycode, code, readonly
	export __main
	;entry

__main
	MOV R0, #1
	MOV R1, #1
	MOV R2, #2
	MOV R3, #2
	MOV R4, #0
	
	CMP   R0, R1	; R0 == R1
    CMPEQ R2, R3	; (R0 == R1) && (R2 == R3)
	ADDEQ R4, #1	; R4++

HERE B HERE
	END