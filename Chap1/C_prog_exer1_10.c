#include <stdio.h>
#include <ctype.h>

/* count lines, words, and characters in input */
int main() 
{
    int c;
    char word[100]; // buffer to hold the current word
    int word_index = 0; // index for the word buffer
    
    while ((c = getchar()) != 'Q') {
        if(c=='\t'){
            word[word_index]='\\';
            word[word_index+1]='t';
            word_index=word_index+2;
        }
        else if(c=='\b'){
            word[word_index]='\\';
            word[word_index+1]='b';
            word_index=word_index+2;
        } 
        else if(c=='\\'){
            word[word_index]=word[word_index+1]='\\';
            word_index=word_index+2;
        }
        else{
            word[word_index]=c;
            word_index++;
        }   
    }
    word[word_index]='\0';
    printf("Word: %s\n", word);
    
    return 0;
}