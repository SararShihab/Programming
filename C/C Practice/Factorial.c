#include<stdio.h>
int main()
{
    int n, fact = 1;
    printf("Enter the number: ");
    scanf("%d", &n);
    
    if (n==0)
    {
        printf("Factorial of %d is %d", n, fact);
    }
    
    else
    {
    for (int i = 1; i <= n; i++)
    {
        fact *= i;
    }

    printf("Factorial of %d is %d", n, fact);
    }

    return 0;
    
}