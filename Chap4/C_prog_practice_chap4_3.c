/**
 * Adding the Modulus operator and provision for negative numbers
 * Program is given the input in a single and and it print the output upon
 * getting a \n character. For e.g: 10 10 + 100 + 2 * 240
 *
 **/

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXOP 100
#define NUMBER '0'

#define BUFSIZE 100

#define MAXVAL 100

int sp = 0;
int bufp = 0;

double val[MAXVAL];
char buf[BUFSIZE];

int getch(void);

void ungetch(int);

int getop(char[]);

void push(double);

double pop(void);

/* reverse polish calculator */

int main(void) {
    int type,var;
    double op2;
    char s[MAXOP];
    double variable[26];

    memset(variable,0,sizeof(variable));

    while ((type = getop(s)) != 'Q') {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error:zero divisor\n");
                break;
            case '%':
                op2 = pop();
                if (op2 != 0.0)
                    push(fmod(pop(), op2));
                else
                    printf("error:zero divisor\n");
                break;
            case 's':
                push(sin(pop()));
                break;
            case 'e':
                push(exp(pop()));
                break;
            case 'p':
                op2 = pop();
                push(pow(pop(),op2));
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
             case '=':
                op2 = pop();  // Pop the value to be assigned
                if (var >= 'A' && var <= 'Z') {
                    variable[var - 'A'] = op2;
                    push(op2);  // Push the value back to stack for further use
                } else {
                    printf("error: no variable name\n");
                }
                break;
            default:
                if(type>='A' && type<='Z'){
                    push(variable[type-'A']);
                    var=type;
                }
                else
                    printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}

void push(double f) {
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error:stack full, cant push %g\n", f);
}

double pop(void) {
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

int getop(char s[]) {
    int i, c;
    while ((s[0] = c = getch()) == ' ' || c == '\t'); //First skips white spaces
    s[1] = '\0';
    if (!isdigit(c) && c != '.' && c != '-')
        return c; // not a number
    i = 0;
    if (c == '-' || isdigit(c)) // collect integer part along with '-'
        while (isdigit(s[++i] = c = getch()));
    if (c == '.') // collect fraction part
        while (isdigit(s[++i] = c = getch()));
    s[i] = '\0';
    if (c != 'Q')
        ungetch(c);
    if (strcmp(s, "-") == 0)
        return '-';
    return NUMBER;
}

void ungetch(int c) {
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

int getch(void) { return (bufp > 0) ? buf[--bufp] : getchar(); }