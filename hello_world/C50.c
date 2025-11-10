#include <stdio.h>
#include <string.h>

int deleteSubstring(char str[], char substr[]) {
    int deleted = 0;
    int subLen = strlen(substr);
    int strLen = strlen(str);
    
    if (subLen == 0) return 0;
    
    char result[1000] = "";  // 用于存储结果
    int resultIndex = 0;
    int i = 0;
    
    while (i < strLen) {
        // 检查从当前位置开始是否匹配子串
        int match = 1;
        if (i + subLen <= strLen) {
            for (int j = 0; j < subLen; j++) {
                if (str[i + j] != substr[j]) {
                    match = 0;
                    break;
                }
            }
        } else {
            match = 0;
        }
        
        if (match) {
            // 找到子串，跳过不复制
            deleted = 1;
            i += subLen;  // 跳过子串长度
        } else {
            // 不匹配，复制当前字符
            result[resultIndex++] = str[i++];
        }
    }
    result[resultIndex] = '\0';  // 结束字符串
    
    // 将结果复制回原字符串
    strcpy(str, result);
    
    return deleted;
}

int main() {
    char str[1000], substr[1000];
    
    // 输入字符串
    fgets(str, sizeof(str), stdin);
    fgets(substr, sizeof(substr), stdin);
    
    // 去除换行符
    str[strcspn(str, "\n")] = '\0';
    substr[strcspn(substr, "\n")] = '\0';
    
    // 删除子串并获取返回值
    int result = deleteSubstring(str, substr);
    
    // 输出结果
    printf("%s\n", str);
    printf("%d\n", result);
    
    return 0;
}
//深刻理解指针与数组的密切联系