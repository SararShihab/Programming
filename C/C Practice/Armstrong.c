#include<stdio.h>
#include<math.h>

int main()
{
    int n, a;
    printf("n = ");
    scanf("%d", &n);
    int m=n;
    int j=m;
    int sum = 0, count = 0;
    
    while (n!=0)
    {
        n = n/10;
        count ++;
    }
    while (j!=0)
    {
        a = j%10;
        j = j/10;
        sum += pow(a, count);
    }

    if(m==sum)
    {
        printf("The number is an armstrong number");
    }
    else
    {
        printf("The number is not an armstron number");
    }
    
    
    return 0;
}
