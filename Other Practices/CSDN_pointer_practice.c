#include <stdio.h>
#include <string.h>

int main(){
    // char a[20]="cehiknqtw";
    // char *s="fbla",*p;
    // int i, j;
    // for(p=s; *p; p++) {
    //     j=0;
    //     while (*p>=a[j] && a[j]!='\0') j++;
    //     for(i=strlen(a); i>=j; i--) a[i+1] = a[i];
    //     a[j]=*p;
    // }
    // printf("%s", a);
    long sum = 0;
    long i;
    for (i = 0; i < 10; i++) {
        if (i & 1)
            continue;
        sum += i;
    }
    printf("The sum is:%d",sum);
}