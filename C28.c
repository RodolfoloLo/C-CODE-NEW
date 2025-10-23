#include<stdio.h>
struct DATE{
    int year;
    int month;
    int day;
}date;
int main(){
    scanf("%d %d %d",&date.year,&date.month,&date.day);
    int leap;
    if((date.year%4==0&&date.year%100!=0)||date.year%400==0){
        leap=1;
    }else{
        leap=0;
    }
    int monthday[13]={0,31,0,31,30,31,30,31,31,30,31,30,31};
    if(leap){
        monthday[2]=29;
    }else{
        monthday[2]=28;
    }
    int yearday=0;
    if(date.month!=1){
        for(int i=0;i<=date.month;i++){
            yearday+=monthday[i];
        }
    }
    yearday+=date.day;
    if(date.day>monthday[date.month]){
        printf("不存在这样的日期");
    }else{
        printf("%d",yearday);
    }
    return 0;
}