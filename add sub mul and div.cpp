#include <stdio.h>
int main() {
    double num1, num2;
    printf("Enter two numbers: ");
    scanf("%lf %lf", &num1, &num2);
    printf("Addition: %.2f + %.2f = %.2f\n", num1, num2, num1 + num2);
    printf("Subtraction: %.2lf - %.2lf = %.2f\n", num1, num2, num1 - num2);
    printf("Multiplication: %.2f * %.2f = %.2f\n", num1, num2, num1 * num2);
    if (num2 != 0) {
        printf("Division: %.2f / %.2f = %.2f\n", num1, num2, num1 / num2);
    } else {
        printf("Division by zero is undefined.\n");
    }
    
    return 0;
}

