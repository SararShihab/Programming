#include <stdio.h>
#include<math.h>
int main()
{
    double x, y;
read:
    scanf("%lf", &x);
    if (x < 0)
        goto read;
    y = sqrt(x);
    printf("%0.4lf", y);
}