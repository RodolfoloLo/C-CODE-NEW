#include <stdio.h>
#include <ctype.h>

int main() {
    int ch, prev = ' ';
    int char_count = 0, word_count = 0, line_count = 1;//记得要初始化！！！
    
    while ((ch = getchar()) != EOF) {
        // 检查中文字符（UTF-8首字节）
        if (ch & 0x80) {
            // 跳过中文字符的另外2个字节
            getchar();
            getchar();
            
            char_count++;
            // 如果前一个字符是空白符，开始新字
            if (isspace(prev)) {
                word_count++;
            }
            prev = 'a';  // 设置为非空白符
        } else {
            // 西文字符处理
            if (ch == '\n') {
                line_count++;
            }
            
            if (!isspace(ch)) {
                char_count++;
                if (isspace(prev)) {
                    word_count++;
                }
            }
            prev = ch;
        }
    }
    
    printf("字数 %d\n", word_count);
    printf("字符数 %d\n", char_count);
    printf("行数 %d\n", line_count);
    
    return 0;
}