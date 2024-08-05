#include <stdio.h>
#include <string.h>

unsigned invert(unsigned x, int p, int n);

int main(){
    unsigned x=42;
    int p=4;
    int n=3;
    unsigned result=invert(x,p,n);
    printf("The final result was:%u",result);
}

unsigned invert(unsigned x, int p, int n){
    unsigned flag=~(~0<<n)<<(p-n+1);
    return flag^x;
}