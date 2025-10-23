#include<stdio.h>

int main()
{
    int i;
    int j;

    for(i=1;i<=9;i++){
        for(j=1;j<=i;j++){
            int result;
            result=i*j;
            printf("%d*%d=%d  ",i,j,result);
        }
        printf("\n");
    }
    return 0;
}