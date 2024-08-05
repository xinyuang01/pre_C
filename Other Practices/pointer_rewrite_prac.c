//Chap 1 rewrite to pointers.

#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 1000 /* maximum input line length */ 
#define MAX_LINE_LEN 500

//itoa

//Chapter 1 getline
/*
int getline(char* s, int lim);
void copy(char* to, char* from);

int main(){
    int len; // current line length 
    int max; // maximum length seen so far 
    char line[MAXLINE]; // current input line 
    char longest[MAXLINE]; // longest line saved here 
    max = 0; 
    while ((len = getline(line, MAXLINE)) > 0) { 
        if (len > max) { 
            max = len; 
            copy(longest, line); 
        } 
    }
    if (max > 0) printf("%s", longest); 
    return 0;
}

// getline: read a line into s, return length
int getline(char* s,int lim) { 
    
    int c, i; 
    for (i=0; i < lim-1 && (c=getchar())!='Q' && c!='\n'; ++i) { 
        *(s+i) = c; 
    }
    if (c == '\n') { 
        *(s+i) = c; 
        ++i; 
    } 
    *(s+i) = '\0'; 
    return i; 
}

void copy(char* to, char* from) { 
    int i; 
    i = 0; 
    while ((*(to+i) = *(from+i)) != '\0') ++i; 
}*/

// void itoa(int n, char* s) 
// { 
//     int i, sign;
//     if ((sign = n) < 0)  n = -n; 
//     i = 0; 
//     do { 
//         *(s+i++) = n % 10 + '0'; 
//     } while ((n /= 10) > 0); 
//     if (sign < 0) 
//         *(s+i++) = '-'; 
//     *(s+i) = '\0'; 
// }

void tail(char* lines[], int n) {
    int i,j;
    char c='\0';

    for (i = 0; i < MAXLINE; ++i) {
        *(lines+i) = (char *)calloc(MAX_LINE_LEN, sizeof(char));  // Allocate memory for each line
    }

    for (i=0;i < MAXLINE-1 && c!='Q';++i) {
        for (j=0;j<MAX_LINE_LEN-1 && (c=getchar())!='Q' && c!='\n'; ++j) { 
            *(*(lines+i)+j) = c;
        }
        if (c == '\n') { 
            *(*(lines+i)+j) = c; 
            ++j; 
        }
        *(*(lines+i)+j)='\0';
    }
    
    //print the last n lines
    int start = (i - n < 0) ? 0 : i - n;
    for (int print_index = start; print_index < i; ++print_index) {
        printf("The current line index is: %d, the current string is: %s\n", print_index, *(lines + print_index));
    }

}
 
int main() {
    char **lines = (char **)calloc(MAXLINE, sizeof(char *));  // Allocate an array of pointers
    tail(lines,10);
    free(lines);
    return 0;
}