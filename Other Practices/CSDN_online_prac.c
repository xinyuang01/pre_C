# include <stdio.h>
# define dprint(expr) printf(#expr " = %d\n", expr)
#define swap(t, x, y) do { t = x; x = y; y = t; } while(0)

int main(){
    int t;
    int x = 25;
    int y = 5;
    dprint(x / y);
    //Here expr replaces the string you typed in, # means it will be evaluated.
    swap(t,x,y);
    printf("x=%d",x);
    return 0;
}

/* 28题宏定义

#define F1(var) printf("var=%d",var)
#define F0(var) F1((var)*(var))

int main(){
    F0(3+5);
    return 0;
}

*/