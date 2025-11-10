#include<stdio.h>
#include<stdlib.h>
void dicegame(int randseed){
    srand(randseed);//用于设置随机数 初始化随机数生成器 相同种子 相同随机数列
    int a,b,goal=0;
    int i=1;//i表示轮次
    a=rand()%6+1;//生成1-6的随机数
    b=rand()%6+1;//生成的是伪随机数，看起来随机，但实际上可预测
    if(a+b==7||a+b==11){
        printf("'Round 1: Score:%d Success!'\n",a+b);
    }else if(a+b==2||a+b==3||a+b==12){
        printf("'Round 1: Score:%d Failed!'\n",a+b);
    }else{
        while(1!=2){
            if(a+b==goal){
                printf("'Round %d: Score:%d Success!'\n",i,a+b);
                break;
            }else if(a+b==7){
                printf("'Round %d: Score:%d Failed!'\n",i,a+b);
                break;
            }else{
                printf("'Round %d: Score:%d Continue!'\n",i,a+b);
                if(i==1){
                    goal=a+b;
                    printf("'Next rounds: Score %d:Success, Score 7:Failed, Others:Continue'\n",goal);
                }
                i++;
                a=rand()%6+1;
                b=rand()%6+1;
            }
        }
    }
}
int main(){
    int randseed;
    scanf("%d",&randseed);
    dicegame(randseed);
    return 0;
}