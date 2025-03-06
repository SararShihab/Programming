#include<stdio.h>
#include<math.h>
int main(){
    int a, b, c;
    float d, x1, x2;
    scanf("%d %d %d", &a, &b, &c);
    d = b*b - 4*a*c;
    if (d>=0)
    {
        x1 = (-b + sqrt(d))/(2*a);
        x2 = (-b - sqrt(d))/(2*a);
        printf("Root 1: %0.3f and Root 2: %0.3f", x1, x2);
    }
    else
    {
        printf("Imaginary");
    }
    return 0;
}