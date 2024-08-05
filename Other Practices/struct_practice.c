#include <stdio.h>

int main(){
    /*Method 1
    struct key {
        char* name;
        int number;
    } keytab[5]={
        {"LuoDing",0},
        {"Yossi",0},
        {"Otto",0},
        {"James",0},
        {"Van",0}
    };//在C语言里面你只能一开始就定义好，后面就不要改了 */

    /*Method 2*/
    // key is the struct type name, while keytab is the variable name.
    // 
    struct key {
        char* name;
        int number;
    };

    struct key keytab[5]={
        {"LuoDing",0},
        {"Yossi",0},
        {"Otto",0},
        {"James",0},
        {"Van",0}
    };

    //Creating a rectangle
    //一定要用；
    struct point {
        int x;
        int y;
    };

    struct rectangle {
        struct point botleft;
        struct point topright;
    } rectangle1;

    struct rectangle *rect_pointer;
    rectangle1.botleft.x=rectangle1.botleft.y=5;

    rect_pointer->topright.x=rect_pointer->topright.y=3;
    
    keytab[0].number=7;
    printf("The name is:%s, and his number is: %d",keytab[0].name,keytab[0].number);

    return 0;
}