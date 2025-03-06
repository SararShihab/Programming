#include<stdio.h>
int main()
{
    int m, n;
    printf("Starting from: ");
    scanf("%d", &m);
    printf("End at: ");
    scanf("%d", &n);
    for (int i = m; i <= n; i++)
    {
        if (i%2==0)
        {
            continue;
        }
        printf("%d ", i);
        
    }
    return 0;
    
}