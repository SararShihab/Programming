#include<stdio.h>
int main()
{
    int n;
    do
    {
        printf("n = ");
        scanf("%d", &n);
        printf("You entered: %d\n", n);
        if (n%2 != 0)
        {
            break;
        }
        
    } while (1);
    printf("Thank You!!");
    
}