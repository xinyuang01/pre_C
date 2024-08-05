#include <stdio.h>
#include <ctype.h>

#define IN 1  /* inside a word */
#define OUT 0 /* outside a word */

/* count lines, words, and characters in input */
int main() 
{
    int c, state;
    char word[100]; // buffer to hold the current word
    char length_arr[30]={0}; //要初始化数组！！！
    int word_index = 0; // index for the word buffer
    
    state = OUT;
    
    while ((c = getchar()) != 'Q') {
        if (c == ' ' || c == '\n' || c == '\t') {
            if (state == IN) {
                // End of a word
                word[word_index] = '\0'; // null-terminate the word
                printf("Word: %s and its length: %d\n", word,word_index); // print the word as well as its wordlength
                length_arr[word_index]++;
                word_index = 0; // reset the word buffer index
            }
            state = OUT;
        } 
        else if (state == OUT) {
            state = IN;
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

    int index;
    for (index=0;index<30;index++){
        if(length_arr[index]!=0){
            printf("Word of length %d:",index);
            while(length_arr[index]>0){
                printf("*");
                length_arr[index]--;
            }
            printf("\n");
        }
    }

    
    return 0;
}