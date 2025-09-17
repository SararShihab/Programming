#include <stdio.h>
int main()
{
    int n;
    printf("n = ");
    scanf("%d", &n);
    if (n == 1)
    {
        printf("%d is not a prime number.", n);
    }

    else
    {
        for (int i = 2; i <= n / 2; i++)
        {
            if (n % i == 0)
            {
                printf("%d is not a prime number.", n);
                break;
            }
            else
            {
                printf("%d is a prime number.", n);
                break;
            }
        }
    }

    return 0;
}