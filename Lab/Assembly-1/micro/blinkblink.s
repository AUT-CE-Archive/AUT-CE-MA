PIO_PER EQU 0x400E0E00
PIO_OER EQU 0x400E0E10
PIO_SODR EQU 0x400E0E30
PIO_CODR EQU 0x400E0E34
PIO_ISR EQU  0x400E0E4C

	AREA myCode, CODE, READONLY
	EXPORT __main
	ENTRY

__main
	BL enable_pio1
	BL enable_pio2
	BL enable_pio3

loop
	
	LDR r1, =PIO_ISR
	LDR r2, [r1]
	CMP r2, #2_1000000
	BEQ over

	; LED 1
	BL led_on1		; On
	BL delay		; Delay
	BL led_off1		; Off
	BL delay		; Delay	
	
	LDR r1, =PIO_ISR
	LDR r2, [r1]
	CMP r2, #2_1000000
	BEQ over
	
	; LED 2
	BL led_on2		; On
	BL delay		; Delay
	BL led_off2		; Off
	BL delay		; Delay	
	
	LDR r1, =PIO_ISR
	LDR r2, [r1]
	CMP r2, #2_1000000
	BEQ over
	
	; LED 3
	BL led_on3		; On
	BL delay		; Delay
	BL led_off3		; Off
	BL delay		; Delay	
	
	B loop			; Repeat

hold
	LDR r1, =PIO_ISR
	LDR r2, [r1]
	CMP r2, #2_100000
	BEQ loop
	B hold

over
	BL led_off1
	BL led_off2
	BL led_off3
	B hold

enable_pio1
	MOV R4, #2_1	
	LDR R5, =PIO_PER
	STR R4, [R5]	
	LDR R5, =PIO_OER
	STR R4, [R5]	
	BX LR

enable_pio2
	MOV R4, #2_10
	LDR R5, =PIO_PER
	STR R4, [R5]	
	LDR R5, =PIO_OER
	STR R4, [R5]	
	BX LR

enable_pio3
	MOV R4, #2_100
	LDR R5, =PIO_PER
	STR R4, [R5]	
	LDR R5, =PIO_OER
	STR R4, [R5]	
	BX LR

led_on1
	MOV R4, #2_1
	LDR R5, =PIO_SODR
	STR R4, [R5]
	BX LR

led_on2
	MOV R4, #2_10
	LDR R5, =PIO_SODR
	STR R4, [R5]
	BX LR

led_on3
	MOV R4, #2_100
	LDR R5, =PIO_SODR
	STR R4, [R5]
	BX LR

led_off1
	MOV R4, #2_1
	LDR R5, =PIO_CODR
	STR R4, [R5]	
	BX LR

led_off2
	MOV R4, #2_10
	LDR R5, =PIO_CODR
	STR R4, [R5]	
	BX LR

led_off3
	MOV R4, #2_100
	LDR R5, =PIO_CODR
	STR R4, [R5]	
	BX LR

delay
	MOV R4, #0
	LDR R5, =0x00A0000

delay_loop
	ADD R4, R4, #1
	CMP R4, R5
	BNE delay_loop
	BX LR	
	END		