#include <stdio.h>
#include <string.h>

//DOUBLE SLASH
/*In MULTI_COMMENT*/
enum State {
    NORMAL,
    SINGLE_SLASH,
    DOUBLE_SLASH, //print nothing
    MULTI_COMMENT_START 
};

//void delete_comment();

int main() {
    int State=NORMAL;
    int c, prev_c='\0';
    while ((c = getchar()) != 'Q'){

        if(State==NORMAL){
            if(c=='/'){
                State=SINGLE_SLASH;
            } else {
                putchar(c);
            }
        } else if (State==SINGLE_SLASH){
            if(c=='/'&& prev_c=='/') {
                State=DOUBLE_SLASH;
            } else if (c=='*' && prev_c=='/') {
                State=MULTI_COMMENT_START;
            } else {
                //If a single slash followed by other chars, print both slash and the char out.
                putchar(prev_c);
                putchar(c);
                State=NORMAL;
            }
        } else if (State==DOUBLE_SLASH) {
            if(c=='\n'){
                State=NORMAL;
                putchar(c);
            }
        } else if (State==MULTI_COMMENT_START) {
            if(c=='/' && prev_c=='*'){
                State=NORMAL;
            }
        }

        prev_c=c;
    }
    return 0;
}

