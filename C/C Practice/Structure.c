#include<stdio.h>
#include<string.h>

struct student{
    char name[100];
    int roll;
    float cgpa;
};

int main(){
    struct student st = {"SHIHAB", 859, 3.56};


    printf("%s %d %0.3f", st.name, st.roll, st.cgpa);

    return 0;
}