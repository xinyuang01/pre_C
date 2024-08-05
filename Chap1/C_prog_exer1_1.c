#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define THRE_LEN 80

void print_long_line(char s[]) 
{ 
    int c;
    int i=0;  

    while((c=getchar())!='Q'){
        if(c=='\n'){
            s[i]=c;
            ++i;
            s[i]='\0';
            if(i>THRE_LEN-1){
                printf("The word is longer than 80 chars:%s",s);
            }

            //Initialize the string and count
            i=0;
            memset(s, '\0', 200);
        }
        else{
            s[i]=c;
            ++i;
        } 
    }

    //The edge case in which the last word before Q was typed also had a length larger than 80 chars.
    if(i>THRE_LEN-1){
        printf("The last word before Q was typed is also longer than 80 chars:%s",s);
    }
}

int main() 
{
    char string[200];
    print_long_line(string);
}