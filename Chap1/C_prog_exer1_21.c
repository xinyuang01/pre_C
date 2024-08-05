#include <stdio.h>
#include <string.h>

#define TAB_WIDTH 8
#define IN_BLANK 1
#define OUT_OF_BLANK 0

void entab() {
    int c, currPos, state, blankBegin;

    currPos = 0;
    state = OUT_OF_BLANK;
    while ((c = getchar()) != 'Q') {
        if (c == '\n') {
            printf("\n");
            currPos = 0;
        } else if (c == '\t') {
            if (state == OUT_OF_BLANK) {
                state = IN_BLANK;
                blankBegin = currPos;
            }
            currPos = currPos + (TAB_WIDTH - currPos % TAB_WIDTH);
        } else if (c == ' ') {
            if (state == OUT_OF_BLANK) {
                state = IN_BLANK;
                blankBegin = currPos;
            }
            ++currPos;
        } else if (c != ' ') {
            if (state == IN_BLANK) {
                
                state = OUT_OF_BLANK;

                int i;

                for (i = blankBegin;
                     i + (TAB_WIDTH - i % TAB_WIDTH) <= currPos;
                     i = i + (TAB_WIDTH - i % TAB_WIDTH)) {
                    printf("\t");
                }

                if (i < currPos) {
                    for (int j = i; j < currPos; ++j) {
                        printf("*");
                    }
                }
            }
            printf("%c", c);
            ++currPos;
        }
    }
}

int main() {
    entab();
}