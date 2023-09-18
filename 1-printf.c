#include <stdio.h>


void printSum(int a, int b) 
{
    int sum = a + b;

    printf("Sum using %%d: %d\n", sum);
    printf("Sum using %%i: %i\n", sum);
}

int main() {
    int num1 = 10;
    int num2 = 20;

    // Call the function to calculate and print the sum
    printSum(num1, num2);

    return 0;
}
