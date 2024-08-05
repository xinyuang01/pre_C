// C program to implement
// typedef with structures
#include <stdio.h>
#include <string.h>
 
// using typedef to define an alias for structure
// typedef <var> <new var name>
typedef struct students {
    char name[50];
    char branch[50];
    int ID_no;
} stu;
 
// Driver code
int main()
{
    stu st;
    //This is how you init a string in C
    char thisname[]={'A','L','A','N','\0'};
    strcpy(st.name, thisname);
    strcpy(st.branch, "Computer Science And Engineering");
    st.ID_no = 108;
 
    printf("Name: %s\n", st.name);
    printf("Branch: %s\n", st.branch);
    printf("ID_no: %d\n", st.ID_no);
    return 0;
}