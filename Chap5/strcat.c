#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void str_cat(char *s, char *t);
void str_ncat(char *s, char *t, int n);

int main(){
    char s1[20]="dick";
    char s2[]="headache";
    int n=0;
    
    //str_cat(s1,s2);
    str_ncat(s1,s2,n);

    printf("The concatenated string is: %s",s1);

    return 0;
}

void str_cat(char *s, char *t){
    int i=0,j=0;
    while(*(t+j)!='\0'){
        while(*(s+i)!='\0') ++i;
        *(s+i++)=*(t+j++);
    }
}

void str_ncat(char *s, char *t, int n){
    int i=0,j=0;
    int flag=1;
    while(j<n){
        while(*(s+i)!='\0') ++i;
        if(flag){
            *(s+i++)=*(t+j++);
            flag=(*(t+j)!='\0');
        } else {
            //padding with '/0'
            *(s+i++)='\0';
            j++; 
        }
    }
}