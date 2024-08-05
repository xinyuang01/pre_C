#include <stdio.h> 

/* echo command-line arguments; 2nd version */ 
void echo(int argc, char *argv[]);

int main() {
    char *string[2] = {"Hello,", "World!"}; // Correct the size and add NULL terminator
    int numchar = 2; // Number of command-line arguments
    echo(numchar, string);
    return 0;
}

void echo(int argc, char *argv[]) { 
    while (argc-- > 0) 
        printf("%s%s", *argv++, (argc > 1) ? " " : ""); 
    printf("\n");  
}