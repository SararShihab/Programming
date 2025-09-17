#include<stdio.h>

void printHW(int count);

int main()
{
    int n;
    printf("Enter how many times you want to print: ");
    scanf("%d", &n);
    printHW(n);
    return 0;
}

void printHW(int count){
    if(count == 0){
        return;
    }
    printf("Hellow World!\n");
    printHW(count -1);
}