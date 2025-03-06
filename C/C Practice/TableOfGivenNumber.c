#include<stdio.h>
int main()
{
    int n;
    printf("Enter the number: ");
    scanf("%d", &n);
    for (int i = 1; i <= 10; i++)
    {
        int temp = n*i;
        printf("%d * %d = %d\n", n, i, temp);
    }
    return 0;
}