#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define TAB_WIDTH 8

//WTF原来tab每次都是跳8个字节吗

void detab(char s[]) {
    // Detab each line of input. The output should look the same.
    // Detab: replace tab with space
    int c, currPos, blanks;
    
    while((c=getchar())!='Q'){
        if(c=='\n'){
            s[currPos]='\0';                    
            printf("%s\n",s);   //Terminates the word and prints 
            memset(s,'\0',200);
            currPos=0;                              //Resets the pointer
        }
        else if(c=='\t'){
            blanks=TAB_WIDTH-(currPos%TAB_WIDTH);
            while(blanks>0){
                s[currPos]='#';
                --blanks;
                ++currPos;
            }
        }
        else{
            s[currPos]=c;
            ++currPos;
        }
    }
}

int main() {
    char string[200];
    detab(string);
}