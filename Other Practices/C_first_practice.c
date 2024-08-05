#include <stdio.h>
#define MAX 10000
#include <stdbool.h>

//正确的使用enum

enum State
{
    //枚举常量！
    state_a,
    state_b,
    state_c
};

// int main()
// {
//     enum State b=state_b;
//     printf("Hello World!");

//     size_t i=0;
//     i--;
//     printf("The value of i: %d",i);
// }

//b站练习题： C语言经典100题 第 30 题
//Given num is a 5 digit dec find if it is 回文数.


// Function to check if a number is a palindrome
int isPalindrome(int number) {
    // Ensure the number is a 5-digit number
    if (number < 10000 || number > 99999) {
        return 0;
    }

    // Array to store the digits of the number
    int digits[5];
    
    // Extract digits and store them in the array
    for (int i = 4; i >= 0; i--) {
        digits[i] = number % 10;
        number /= 10;
    }

    // Check if the number is a palindrome
    for (int i = 0; i < 2; i++) {
        if (digits[i] != digits[4 - i]) {
            return 0;
        }
    }

    return 1;
}

int main() {
    int number=98989;

    // Prompt the user to enter a 5-digit number
    // printf("Enter a 5-digit number: ");
    // scanf("%d", &number);

    // Check if the number is a palindrome and print the result
    if (isPalindrome(number)) {
        printf("%d is a palindrome.\n", number);
    } else {
        printf("%d is not a palindrome.\n", number);
    }

    return 0;
}


