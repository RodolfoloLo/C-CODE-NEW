#include<stdio.h>

struct student{
    int num;
    char name[12];
    double score;
};

void scan(struct student *p, int n){
    for(int i = 0; i < n; i++){
        scanf("%d %s %lf", &p[i].num, p[i].name, &p[i].score);
    }
}

void print(struct student *p, int n){
    for(int i = 0; i < n; i++){
        printf("%d %s %.1f\n", p[i].num, p[i].name, p[i].score);
    }
}

int main(){
    int n = 3;
    struct student students[n];
    struct student *p = students;  // p指向students数组
    
    scan(p, n);
    print(p, n);
    return 0;
}