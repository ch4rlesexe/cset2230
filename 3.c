/*
The program does the following:
Accepts two integers as inputs from the user using C.
Calculates addition, subtraction, and multiplication of the two integers using C.
Calculates addition, subtraction, and multiplication of the two integers using assembly as shown in class.
Displays the results of each operation using C.
*/
#include <stdio.h>

int main(void) {
    int iOne; // first input
    int iTwo; // seocnd input !!!
    int sC; // sum of values in C
    int dC; // differencec of values in C !!
    int pC; // product of values in C
    int sASM; // same thing but in asm
    int dASM; // same thing but in asm
    int pASM; // same thing but in asm

    printf("Enter your first input: ");
    scanf_s("%d", &iOne); // get user's first input
    printf("Enter another input: ");
    scanf_s("%d", &iTwo); // get user's second input

    sC = iOne + iTwo; // add in c
    dC = iOne - iTwo; // subtract in c
    pC = iOne * iTwo; // multiply in c
    __asm {
        // addition in asm
        mov eax, iOne // move first input to eax
        add eax, iTwo // add second input to eax
        mov sASM, eax // move eax to sASM variable

        // subtraction in asm
        mov eax, iOne // move first input to eax
        sub eax, iTwo // subtract second input from eax
        mov dASM, eax // move eax to dASM variable

        // multiplication in asm
        mov eax, iOne // move first input to eax !!!
        imul eax, iTwo // multiply eax by rthe second input
        mov pASM, eax // move eax to pASM variable
    }

    printf("Values in C: \n Sum: %d, Diff: %d, Prod: %d\n", sC, dC, pC); // print out c values
    printf("Values in ASM: \n Sum: %d, Diff: %d, Prod: %d\n", sASM, dASM, pASM); // print out asm values
    // baboosh
}
