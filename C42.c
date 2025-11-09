#include<stdio.h>
int main(){
    int m,n;
    scanf("%d %d",&m,&n);
    int in[m];
    int out_number[m-1]={0};  
    int count=0;
    int j=0;
    
    for(int i=0;i<m;i++) in[i]=1;
    
    for(int i=1;count<m-1;){  
        if(in[j]==1&&i!=n){
            i++;
            j=(j+1)%m;
            continue;
        }
        if(!in[j]){
            j=(j+1)%m;
            continue;
        }
        if(i==n){
            in[j]=0;
            out_number[count]=j+1;
            count++;
            i=1;
            j=(j+1)%m;
        }
    }
    
    for(int i=0;i<m-1;i++){  
        printf("%6d",out_number[i]);
    }
    printf("\n");
    for(int i=0;i<m;i++){
        if(in[i]){
            printf("%6d",i+1);
        }
    }
    return 0;
}//解决约瑟夫问题