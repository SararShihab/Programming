/*This is a Program that finds 
the area of a circle using it's radius*/

#include<stdio.h>

#define PI 3.1416

void area(int);

int main()
{
    int radius;
    printf("Enter the the radius: ");
    scanf("%d", &radius);
    area(radius);
}

void area(int r)
{
    float area;
    area = PI * r * r;
    printf("The area is %0.3f", area);
}