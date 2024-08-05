#include <stdio.h>
#include <ctype.h>

/* count lines, words, and characters in input */
int main() 
{
    int c;
    int last_c='a';

    while ((c = getchar()) != 'Q') {
        if(c!=' ' || last_c!=' '){
            putchar(c);
        }
        last_c=c;
    }
    return 0;
}