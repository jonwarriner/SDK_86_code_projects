%define(controls)(module=msDelay fixedparams %controls)
%'      environment symbols

%*define(embedded)      (%set(HOSTED, 0)%set(MS_DOS,0)%set(RMX, 0))

%*define(em)	(%embedded)


$include(:include:util.ah)

; function to generate a delay in ms
; use the macro in msDealy.h to calculate the number of
; loop iteration for the desired delay.  
; each iteration of the loop takes 21 clock cycles

%function(msDelay)
%param(word, cnt)
	%prolog(bx)					; bx will only be preserved if required by the calling convention
	
	mov		bx, %cnt
; just some test code to make sure cnt is passed correctly
; ouput count on P2A and P1A as a 16-bit value
;	mov		dx, 0FFF8H
;	mov		ax, bx
;	out		dx, ax
L1:
;	dec		bx					; 2 clocks
;	nop							; 3 clocks
	nop							; 3 clocks
	dec		bx					; 2 clocks
	jnz		L1					; 16 clocks if true, 4 clocks if false
	
	%epilog
	%ret
%endf(msDelay)
	end