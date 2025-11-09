#include<stdio.h>
#include<math.h>
#define S(a,b,c) ((a+b+c))/2.0
#define AREA(a,b,c) sqrt(S(a,b,c)*(S(a,b,c)-a)*(S(a,b,c)-b)*(S(a,b,c)-c))
//适合使用宏的情况：简单的数学运算，常量定义，调试和日志，
int main(){
    double a,b,c;
    scanf("%lf %lf %lf",&a,&b,&c);
    if(a+b>c&&a+c>b&&b+c>a){
        printf("Area=%.2lf",AREA(a,b,c));
    }else{
        printf("Input error");
    }
    return 0;
}