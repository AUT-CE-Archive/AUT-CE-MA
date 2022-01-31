PIO_PER EQU 0x400E0E00
PIO_OER EQU 0x400E0E10
PIO_SODR EQU 0x400E0E30
PIO_CODR EQU 0x400E0E34
PIO_ISR EQU  0x400E0E4C

	AREA myCode, CODE, READONLY
	EXPORT __main
	ENTRY

__main
	MOV R8, #0		; 1th counter
	MOV R9, #2_00000000		; 2th counter
	
	; enable sengemnt pins
	BL enable_first_segment_pins
	BL enable_second_segment_pins

loop
	; 0
	BL pin_off1
	BL pin_off2
	BL pin_off3
	BL pin_off4
	BL delay
	BL pulling
	
	; 1
	BL pin_on1
	BL pin_off2
	BL pin_off3
	BL pin_off4
	BL delay
	BL pulling
	
	; 2	
	BL pin_off1
	BL pin_on2
	BL pin_off3
	BL pin_off4
	BL delay
	BL pulling
	
	; 2	
	BL pin_on1
	BL pin_on2
	BL pin_off3
	BL pin_off4
	BL delay
	BL pulling
	
	; 4
	BL pin_off1
	BL pin_off2
	BL pin_on3
	BL pin_off4
	BL delay
	BL pulling
	
	; 5
	BL pin_on1
	BL pin_off2
	BL pin_on3
	BL pin_off4
	BL delay
	BL pulling
	
	; 6
	BL pin_off1
	BL pin_on2
	BL pin_on3
	BL pin_off4
	BL delay
	BL pulling
	
	; 7
	BL pin_on1
	BL pin_on2
	BL pin_on3
	BL pin_off4
	BL delay
	BL pulling
	
	; 8
	BL pin_off1
	BL pin_off2
	BL pin_off3
	BL pin_on4
	BL delay
	BL pulling
	
	; 9
	BL pin_on1
	BL pin_off2
	BL pin_off3
	BL pin_on4
	BL delay
	BL pulling

	ADD R9, R9, #2_00010000;
	MOV R4, R9
	LDR R5, =PIO_SODR
	STR R4, [R5]
	BL delay
	
	B loop			; Repeat

pulling
	; Pulling for Reset
	LDR r1, =PIO_ISR
	LDR r2, [r1]
	CMP r2, #2_1000000
	BEQ over
	BX LR

hold
	LDR r1, =PIO_ISR
	LDR r2, [r1]
	CMP r2, #2_100000
	BEQ loop
	B hold

over
	BL pin_off1
	BL pin_off2
	BL pin_off3
	BL pin_off4
	BL pin_off5
	BL pin_off6
	BL pin_off7
	BL pin_off8
	B hold

enable_first_segment_pins
	; 36
	MOV R4, #2_1
	LDR R5, =PIO_PER
	STR R4, [R5]
	LDR R5, =PIO_OER
	STR R4, [R5]
	; 35
	MOV R4, #2_10
	LDR R5, =PIO_PER
	STR R4, [R5]
	LDR R5, =PIO_OER
	STR R4, [R5]
	; 32
	MOV R4, #2_100
	LDR R5, =PIO_PER
	STR R4, [R5]
	LDR R5, =PIO_OER
	STR R4, [R5]
	; 31
	MOV R4, #2_1000
	LDR R5, =PIO_PER
	STR R4, [R5]
	LDR R5, =PIO_OER
	STR R4, [R5]	
	BX LR

enable_second_segment_pins
	; 28
	MOV R4, #2_10000
	LDR R5, =PIO_PER
	STR R4, [R5]
	LDR R5, =PIO_OER
	STR R4, [R5]
	; 27
	MOV R4, #2_100000
	LDR R5, =PIO_PER
	STR R4, [R5]
	LDR R5, =PIO_OER
	STR R4, [R5]
	; 26
	MOV R4, #2_1000000
	LDR R5, =PIO_PER
	STR R4, [R5]
	LDR R5, =PIO_OER
	STR R4, [R5]
	; 24
	MOV R4, #2_10000000
	LDR R5, =PIO_PER
	STR R4, [R5]
	LDR R5, =PIO_OER
	STR R4, [R5]	
	BX LR

pin_on1
	MOV R4, #2_1		; 36
	LDR R5, =PIO_SODR
	STR R4, [R5]
	BX LR

pin_on2
	MOV R4, #2_10		; 35
	LDR R5, =PIO_SODR
	STR R4, [R5]
	BX LR

pin_on3
	MOV R4, #2_100		; 32
	LDR R5, =PIO_SODR
	STR R4, [R5]
	BX LR

pin_on4
	MOV R4, #2_1000		; 31
	LDR R5, =PIO_SODR
	STR R4, [R5]
	BX LR

pin_on5
	MOV R4, #2_10000	; 28
	LDR R5, =PIO_SODR
	STR R4, [R5]
	BX LR

pin_on6
	MOV R4, #2_100000	; 27
	LDR R5, =PIO_SODR
	STR R4, [R5]
	BX LR

pin_on7
	MOV R4, #2_1000000	; 26
	LDR R5, =PIO_SODR
	STR R4, [R5]
	BX LR

pin_on8
	MOV R4, #2_10000000	; 24
	LDR R5, =PIO_SODR
	STR R4, [R5]
	BX LR

pin_off1
	MOV R4, #2_1		; 36
	LDR R5, =PIO_CODR
	STR R4, [R5]
	BX LR

pin_off2
	MOV R4, #2_10		; 35
	LDR R5, =PIO_CODR
	STR R4, [R5]
	BX LR

pin_off3
	MOV R4, #2_100		; 32
	LDR R5, =PIO_CODR
	STR R4, [R5]	
	BX LR

pin_off4
	MOV R4, #2_1000		; 31
	LDR R5, =PIO_CODR
	STR R4, [R5]	
	BX LR

pin_off5
	MOV R4, #2_10000	; 28
	LDR R5, =PIO_CODR
	STR R4, [R5]
	BX LR

pin_off6
	MOV R4, #2_100000	; 27
	LDR R5, =PIO_CODR
	STR R4, [R5]
	BX LR

pin_off7
	MOV R4, #2_1000000	; 26
	LDR R5, =PIO_CODR
	STR R4, [R5]
	BX LR

pin_off8
	MOV R4, #2_10000000	; 24
	LDR R5, =PIO_CODR
	STR R4, [R5]
	BX LR

delay
	MOV R4, #0
	MOV R5, #0x000F0000	; Delay

delay_loop
	ADD R4, R4, #1
	CMP R4, R5
	BNE delay_loop
	BX LR	
	END