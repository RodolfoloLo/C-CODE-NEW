#include<stdio.h>
#include<ctype.h>
//来学乖了！！！
int main() {
    int digit_count[10] = {0};  // 统计0-9数字出现次数
    int letter_count[26] = {0}; // 统计A-Z字母出现次数（不区分大小写）
    int others_count = 0;       // 统计其他字符
    char ch;
    
    // 读取输入直到回车符
    while((ch = getchar()) != '\n') {
        if(ch >= '0' && ch <= '9') {
            // 数字字符
            digit_count[ch - '0']++;
        } else if((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
            // 英文字母，转换为大写后统计
            char upper_ch = toupper(ch);
            letter_count[upper_ch - 'A']++;
        } else {
            // 其他字符
            others_count++;
        }
    }
    
    // 输出数字字符的统计结果
    for(int i = 0; i < 10; i++) {
        if(digit_count[i] > 0) {
            printf("%d:%d\n", i, digit_count[i]);
        }
    }
    
    // 输出字母字符的统计结果（按字母顺序）
    for(int i = 0; i < 26; i++) {
        if(letter_count[i] > 0) {
            printf("%c:%d\n", 'A' + i, letter_count[i]);
        }
    }
    
    // 输出其他字符的统计结果
    if(others_count > 0) {
        printf("others:%d\n", others_count);
    }
    
    return 0;
}