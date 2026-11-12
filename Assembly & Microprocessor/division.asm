
; You may customize this and other start-up templates; 
; The location of this template is c:\emu8086\inc\0_com_template.txt

.model small
.stack 100h
.data

.code
.startup
    mov ax, 9h;
    mov cl, 2h;
    div cl;
.exit
end




