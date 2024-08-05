#include <stdio.h>
#include <string.h>

int htoi(char s_hex[]){
    int i,n;

    n=0;
    for(i=0;s_hex[i]!='\0';++i){
        int conv;
        switch(s_hex[i]){
            case 'a':
            case 'A': 
                conv=10;
                break;
            case 'b':
            case 'B': 
                conv=11;
                break;
            case 'c':
            case 'C':
                conv=12;
                break;
            case 'd':
            case 'D': 
                conv=13;
                break;
            case 'e':
            case 'E':
                conv=14;
                break; 
            case 'f':
            case 'F':
                conv=15;
                break;
            default: conv=s_hex[i]-'0';
        }
        n=n*16+conv;
    }
    return n;
}

int main(){
    char s_hex[5]="aaa";
    int ans=htoi(s_hex);
    printf("The converted hex num:%d",ans);
}