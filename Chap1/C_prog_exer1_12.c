#include <stdio.h>
#include <ctype.h>

#define IN 1  /* inside a word */
#define OUT 0 /* outside a word */

/* count lines, words, and characters in input */
int main() 
{
    int c, nl, nw, nc, state;
    char word[100]; // buffer to hold the current word
    int word_index = 0; // index for the word buffer
    
    state = OUT;
    nl = nw = nc = 0; //Values are assigned from right to left
    
    while ((c = getchar()) != 'Q') {
        ++nc;
        if (c == '\n') 
            ++nl;
        if (c == ' ' || c == '\n' || c == '\t') {
            if (state == IN) {
                // End of a word
                word[word_index] = '\0'; // null-terminate the word
                printf("Word: %s\n", word); // print the word
                word_index = 0; // reset the word buffer index
            }
            state = OUT;
        } 
        else if (state == OUT) {
            state = IN;
            ++nw;
            word[word_index++] = c; // start a new word
        } 
        else {
            word[word_index++] = c; // continue the current word
        }
    }
    
    // Check if the last word was not printed
    if (state == IN) {
        word[word_index] = '\0';
        printf("Word: %s\n", word);
    }

    printf("Lines: %d, Words: %d, Characters: %d\n", nl, nw, nc);
    
    return 0;
}