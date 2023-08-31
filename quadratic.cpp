#include <stdio.h>
#include <math.h>
int main() {
    int a, b, c;
    int discriminant, root1, root2;
    printf("Enter the coefficients a, b, and c: ");
    scanf("%lf %lf %lf", &a, &b, &c);
    discriminant = b * b - 4 * a * c;
    if (discriminant > 0) {
        root1=(-b + sqrt(discriminant)/(2*a));
        root2=(-b - sqrt(discriminant)/(2*a));
        printf("Two distinct real roots: root1 = %lf\n and root2 = %lf\n", root1, root2);
    } else if (discriminant == 0) {
        root1 = -b / (2 * a);
        printf("One real root: root1 = root2 = %lf\n", root1);
    } else {
        int realPart = -b / (2 * a);
        int imaginaryPart = sqrt(-discriminant) / (2*a);
          printf("Complex roots: root1 = %lf + %lfi and root2 = %lf - %lfi\n", realPart, imaginaryPart, realPart, imaginaryPart);
    }

    return 0;
}
        
    

