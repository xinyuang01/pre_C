#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char s[],char s_reversed[]);

int main(){
    char s[]="ZHURU";
    char *s_reversed = (char *)calloc(strlen(s), sizeof(char));
    reverse(s,s_reversed);
    printf("The reversed string is:%s",s_reversed);
    return 0;
}

void reverse(char s[],char s_reversed[]){
    int i=0;
    int j=0;
    if(s[0]=='\0') return;
    while(s[i]!='\0') ++i;
    while(s_reversed[j]!='\0') ++j;

    s_reversed[j]=s[i-1];
    s[i-1]='\0';

    reverse(s,s_reversed);
}