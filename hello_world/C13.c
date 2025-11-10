#include <stdio.h>

int main() {
    int ch;
    int last_char = 'a';  // 初始化为非空格字符
    
    while ((ch = getchar()) != EOF) {
        // 如果当前字符是空格，且上一个字符也是空格，就跳过
        if (ch == ' ' && last_char == ' ') {
            continue;  // 跳过连续的空格
        }
        
        // 输出字符
        putchar(ch);
        
        // 更新上一个字符
        last_char = ch;
    }
    
    return 0;
} //非常巧妙的构思呢！！！单个单个判断，借助上一个字符