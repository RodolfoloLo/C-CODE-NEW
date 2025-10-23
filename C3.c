#include<stdio.h>

int main()
{
    char input;
    printf("input:");
    scanf("%c",&input);

    int target=input-'A';

    for(int row=0;row<=target;row++){
        for(int j=0;j<target-row;j++){
        printf(" ");
        
    }
    for(int j=0;j<=row;j++){
        printf("%c",'A'+j);
    }
    for(int j=row-1;j>=0;j--){
        printf("%c",'A'+j);
    }
    printf("\n");
}
return 0;


}