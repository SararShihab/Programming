#include<stdio.h>
int main()
{
    int n, i, j, sum = 0;
    printf("n = ");
    scanf("%d", &n);
    for (i = 1, j = n; i <= n, j>=1; i++, j--)
    {
        printf("%d\n", j);
        sum+=i;
        
    }
    printf("sum = %d", sum);
    return 0;

}