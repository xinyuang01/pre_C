#define VTAB '\013'

// int main() {
//     printf("Line 1%cLine 2\n", VTAB); // This will print "Line 1", then a vertical tab, then "Line 2"
//     return 0;
// }

#include <stdio.h>
#include <string.h>

#define CHAR_SET_SIZE 256

typedef unsigned char *byte_pointer;

void squeeze(char s1[],char s2[]);
int any(char s1[], char s2[]);
unsigned getbits(unsigned x, int p, int n);
unsigned setbits(unsigned x, int p, int n, unsigned y);

int main() {
    /*Exercise 2-4

    char s1[] = "hello world";
    char s2[] = "aeiou";
    squeeze(s1, s2);
    printf("Result: %s\n", s1);  // Output should be "hll wrld" */
    // char stest[]={'h','\0','l','l','\0'}; 
    // printf("What would happen if there are 0s inside the string:\n %s",stest);
    // You cannot assign \0 s to a string cuz it ignores the components after it

    //______________________________________________________________________________//

    //Exercise 2.5
    /*char s1[] = "muddy";
    char s2[] = "abcdef";
    int index=any(s1, s2);
    printf("The index that any char of s2 first appearing in s1 was: %d",index);
    return 0;*/

    //______________________________________________________________________________//

    //Exercise 2.6
    int p=4;
    int n=3;
    unsigned x=57;
    unsigned y=12;
    // unsigned x_masked=getbits(x,p,n);
    // printf("The result of x_masked:%u",x_masked);
    unsigned x_masked=setbits(x,p,n,y);
    printf("The result of x_masked:%u",x_masked);
}

//Exercise 2-4
void squeeze(char s1[], char s2[]) {
    int i, j;
    int to_delete[CHAR_SET_SIZE] = {0};

    // Mark characters in s2 as to be deleted
    for (i = 0; s2[i] != '\0'; i++) {
        to_delete[(unsigned char)s2[i]] = 1;
    }

    // Traverse s1 and remove characters marked for deletion
    for (i = 0, j = 0; s1[i] != '\0'; i++) {
        //If not equal, choose to copy it.
        if (!to_delete[(unsigned char)s1[i]]) {
            s1[j++] = s1[i];
        }
    }
    s1[j] = '\0';
}

//Exercise 2-5
int any(char s1[], char s2[]){
    int i, j;
    int char_list[CHAR_SET_SIZE] = {0};

    // Mark characters in s2 as to be deleted
    for (i = 0; s2[i] != '\0'; i++) {
        char_list[(unsigned char)s2[i]] = 1;
    }

    for (i = 0, j = 0; s1[i] != '\0'; i++) {
        //If not equal, choose to copy it.
        if (char_list[(unsigned char)s1[i]]) {
            return i;
        }
    }
    return -1;
}

//Exercise 2-6
unsigned getbits(unsigned x, int p, int n) { 
    return (x >> (p+1-n)) & ~(~0 << n); 
}

unsigned setbits(unsigned x, int p, int n, unsigned y){
    unsigned bitmask = ~(~0<<n); 
    unsigned y_masked= (y&bitmask)<<(p+1-n);                //Moving the mask to the bits we want to modify in x.
    unsigned x_masked= x&(~(bitmask<<(p+1-n))) | y_masked;  
    //get a mask like 111000111 that preserves all x you don't want to modify, only resetting those you wanted to.
    //Then add it with the y_masked that has already been shifted.
    return x_masked;
}
