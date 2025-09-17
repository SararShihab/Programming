#include <stdio.h>


int sum(int count)
{
    if (count == 0)
    {
        return 0;
    }

    
    return count + sum(count - 1);
}
int main()
{
    int n, x;
    printf("Enter the highest number: ");
    scanf("%d", &n);
    x = sum(n);
    printf("%d", x);
    return 0;
}