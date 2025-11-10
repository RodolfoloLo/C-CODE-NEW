#include<stdio.h>
#include<string.h>

int main(){
   char str[200];
   printf("Input strings, end of Ctrl+z\n");
   while(fgets(str, 200, stdin) != NULL){
   		RemoveDuplicate(str);
      printf("%s", str);
   }
   return 0;
}

void RemoveDuplicate(char *s){
    int len = strlen(s);
    if(len == 0) return;
    int index = 0; //新字符串的索引
    for(int i = 0; i < len; i++){//遍历每个字符
        int j;
        for(j = 0; j < i; j++){//在前面字符中查找是否有重复
            if(s[i] == s[j]){
                break;
            }
        }
        if(j == i){//没有重复
            s[index++] = s[i];//保留该字符
        }
    }
    s[index] = '\0';//字符串结束符
}
