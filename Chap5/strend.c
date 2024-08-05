#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int str_end(char *s, char *t);

int main(){
    char s[]="deep dark fantasy";
    char t[]="fantasy";
    int bool=str_end(s,t);
    printf("Is it true: %d",bool);
}

int str_end(char *s, char *t){
    size_t len_s = strlen(s);
    size_t len_t = strlen(t);

    // If t is longer than s, it can't be at the end
    if (len_t > len_s) {
        return 0;
    }

    // Compare the end of s with t
    return strcmp(s + len_s - len_t, t) == 0;
}