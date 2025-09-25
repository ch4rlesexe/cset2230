#include <stdio.h>

int main() {
    int n = 5;  // Change this to test with different values
    unsigned int factorial = 1;

    // C for-loop to calculate factorial
    for (int i = 1; i <= n; i++) {
        factorial *= i;
    }
    printf("C for-loop: %d! = %u\n", n, factorial);

    __asm {
        mov ecx, n           // Move n into ECX (counter)
        mov eax, 1           // Initialize EAX to 1 (factorial)

        loop_start:
        imul ecx            // Multiply EAX by ECX (EAX = EAX * ECX)
        dec ecx              // Decrement ECX (ECX = ECX - 1)
        jnz loop_start       // Jump if ECX is not zero (continue the loop)

        mov factorial, eax   // Store the result from EAX into factorial variable
    }

    printf("Inline ASM: %d! = %d\n", n, factorial);

    return 0;
}
