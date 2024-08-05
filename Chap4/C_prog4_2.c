#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define INT 0
#define DEC 1
#define SCI 2

double atof_scientific(char s[]);

int main(){
    char string[10]="-123.45e-4";
    double result=atof_scientific(string);
    printf("The final answer is:%f",result);
}

double atof_scientific(char s[]){
    double integer,dec=0.0,sci=0.0,dec_digit=10;
    int i,sign_num=1,sign_sci=1;
    int STATE=INT;

    for(i=0,integer=0.0;s[i]!='\0';++i){
        if(s[i]=='.'){
            STATE=DEC;
            continue;
        }
        else if(s[i]=='e'||s[i]=='E'){
            STATE=SCI;
            continue;
        }
        

        switch(STATE){
            case INT:
                if(s[i]=='-'){
                    sign_num=-1;
                    continue;
                }
                else integer=10.0*integer+s[i]-'0';
                break;
            case DEC:
                dec=dec+(s[i]-'0')/dec_digit;
                dec_digit*=10;
                break;
            case SCI:
                if(s[i]=='-'){
                    sign_sci=-1;
                    printf("The i now is:%d\n",i);
                    break;
                }
                else if(s[i] >= '0' && s[i] <= '9'){
                    printf("When printing SCI nums, the i is:%d\n",i);
                    sci = 10.0 * sci + (s[i] - '0');
                }
                break;
        }
    }
    sci=pow(10,sign_sci*sci);
    printf("The sign_sci=%d, sign_num=%d, sci=%f\n",sign_sci,sign_num, sci);
    return sign_num*(integer+dec)*sci;

}