#include <stdio.h>
#include <string.h>

void escape(char s[],char t[]);
void unescape(char s[],char t[]);

typedef enum {false=0, true} boolean;

int main(){
    char s[300];
    char t[300];
    //escape(s,t);
    unescape(s,t);
    return 0;
}

void escape(char s[],char t[]){
    int c;
    int index1=0, index2=0;
    while((c=getchar())!='Q' && index1<300 && index2<300){
        switch (c){
            case '\n':
                s[index1++]=c;
                t[index2++]='\\';
                t[index2++]='n';
                break;
            case '\t':
                s[index1++]=c;
                t[index2++]='\\';
                t[index2++]='t';
                break;
            case '\r':
                s[index1]=c;
                t[index2++]='\\';
                t[index2++]='r';
                break;
            default:
                s[index1++]=t[index2++]=c;
                break;
        }
    }
    //Ensure that both strings are null terminated.
    s[index1] = '\0';
    t[index2] = '\0';
    printf("The copied string is:%s",t);
}

void unescape(char s[],char t[]){
    int c;
    boolean isSlash=false;
    int index1=0, index2=0;
    while((c=getchar())!='Q' && index1<300 && index2<300){
        if(isSlash){
            switch(c){
                case 'n':
                    t[index2++]='\n';
                    isSlash=false;
                    break;

                case 't':
                    t[index2++]='\t';
                    isSlash=false;
                    break;

                case '\\':
                    t[index2++]='\\';
                    isSlash=true;
                    break;
                
                default:
                    t[index2++]=c;
                    isSlash=false;
                    break;
            }
        }
        else{
            if(c=='\\'){
                isSlash=true;
            }
            else t[index2++]=c;
        }
        s[index1++]=c;
    }
    //Ensure that both strings are null terminated.
    s[index1] = '\0';
    t[index2] = '\0';
    printf("The copied string is:\n%s",t);
}