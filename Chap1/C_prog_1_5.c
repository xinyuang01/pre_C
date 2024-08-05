#include <stdio.h> 

/* Copy input to output; 1st version */
int main() {
    int choice=1; //0 for program 1 and 1 for program 2

    int c1; // Variable to store each character from input
    if(!choice){
    // Read the first character
        c1 = getchar();

        // Continue until end-of-file (EOF) is reached
        while (c1 != 'q') {
            putchar(c1);  // Output the character
            c1 = getchar();  // Read the next character
        }
    }

    else{
        int c2, nl; 
        nl = 0; 
        while ((c2 = getchar()) != 'g') 
            if (c2 == '\t') ++nl; 
        printf("%d\n", nl);
    }
}