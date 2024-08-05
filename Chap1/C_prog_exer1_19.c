#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define THRE_LEN 80

void reverse(char s[]) 
{ 
    int c;
    int start=0;
    int end=0;
    while((c=getchar())!='Q'){
        if(c=='\n'){
            if(end==0 || end==1){
                s[end]='\0';
                printf("The string has a length lower than 2. Its output is:%s\n",s);
            }
            else{
                s[end]='\0';
                end--;
                while(start<end){
                    int temp=s[end];
                    s[end]=s[start];
                    s[start]=temp;
                    end--;
                    start++;
                }
                printf("The string has been reversed. Its output is:%s\n",s);    
            }
            start=end=0;
            memset(s,'\0',200);
        }
        else{
            s[end]=c;
            ++end;
        }
    }
}

int main() 
{
    char string[200];
    reverse(string);
    return 0;
}