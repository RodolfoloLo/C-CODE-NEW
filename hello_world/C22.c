#include<stdio.h>
#include<string.h>
#define SIZE 100
int isPalindrome(char arr[],int len){
    int count=0;
    if(len%2==0){
        for(int i=0;i<len/2;i++){
            if(arr[i]==arr[len-i-1]){
                count++;
            }else{
                break;
            }
        }
        if(count==len/2){
            return 1;
        }else{
            return 0;
        }
    }else{
        for(int j=0;j<(len-1)/2;j++){
            if(arr[j]==arr[len-j-1]){
                count++;
            }else{
                break;
            }
        }
        if(count==(len-1)/2){
            return 1;
        }else{
            return 0;
        }
    }
}
int main(){
    char arr[SIZE];
    fgets(arr,sizeof(arr),stdin);
    int len=strlen(arr);
    if(len>0&&arr[len-1]=='\n'){
        arr[len-1]='\0';
        len--;
    }
    if(isPalindrome(arr,len)){
        printf("Yes");
    }else{
        printf("No");
    }
    return 0;
}