//高精度计算
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//反转字符串
void reverse(char *str){
    int len=strlen(str);
    for(int i=0;i<len/2;i++){
        char temp=str[i];
        str[i]=str[len-i-1];
        str[len-i-1]=temp;
    }
}
//高精度乘法
void multiply(char *num1,char *num2,char *result){
    int len1=strlen(num1);
    int len2=strlen(num2);
    int *res=(int*)calloc(len1+len2,sizeof(int));
    //反转数字以便从低位开始运算
    reverse(num1);
    reverse(num2);
    //逐位相乘
    for(int i=0;i<len1;i++){
        for(int j=0;j<len2;j++){
            res[i+j]+=(num1[i]-'0')*(num2[j]-'0');
        }
    }
    //处理进位
    for(int i=0;i<len1+len2;i++){
        if(res[i]>=10){
            res[i+1]+=res[i]/10;
            res[i]%=10;
        }
    }
    //找到结果的有效起始位置
    int pos=len1+len2-1;
    while(pos>0&&res[pos]==0){
        pos--;
    }
    //将结果转化为字符串
    int index=0;
    for(int i=pos;i>=0;i--){
        result[index++]=res[i]+'0';//
    }
    result[index]='\0';
    if(result[0]=='\0'){
        strcpy(result,"0");//考虑周全！极端情况
    }
    free(res);
}
int main(){
    char num1[100];
    char num2[100];
    char result[200];
    fgets(num1,100,stdin);
    fgets(num2,100,stdin);
    num1[strcspn(num1,"\n")]='\0';
    num2[strcspn(num2,"\n")]='\0';
    //处理可能的空输入！
    if(strlen(num1)==0||strlen(num2)==0){
        printf("0\n");
        return 0;//
    }
    multiply(num1,num2,result);
    printf("%s\n",result);
    return 0;
}