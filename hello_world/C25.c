#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern char *p;  // 外部指针，用于存储连接后的字符串

int main0(int argc, char *argv[]) {
    /********** Begin **********/
    
    // 计算所有字符串的总长度
    int total_length = 0;
    for (int i = 1; i < argc; i++) {
        total_length += strlen(argv[i]);
    }
    
    // 为连接后的字符串分配内存（+1 用于存放 '\0'）
    p = (char *)malloc(total_length + 1);
    if (p == NULL) {
        return -1;  // 内存分配失败
    }
    
    // 连接所有字符串
    p[0] = '\0';  // 初始化为空字符串
    for (int i = 1; i < argc; i++) {
        strcat(p, argv[i]);
    }
    
    /********** End **********/
    return 0;
}
// 平台测试用的main函数
int main() {
    // 模拟命令行参数
    char *test_argv[] = {"struct", "abc", "def", "p"};
    int test_argc = 4;
    
    // 调用学生实现的函数
    main0(test_argc, test_argv);
    
    // 输出结果
    if (p != NULL) {
        printf("%s\n", p);
        free(p);  // 释放内存
    }
    
    return 0;
}