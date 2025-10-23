#include <stdio.h>

// 加密单个字节
unsigned char encrypt_byte(unsigned char b) {
    // 步骤1：提取位
    int bit0 = (b >> 0) & 1;
    int bit1 = (b >> 1) & 1;
    int bit2 = (b >> 2) & 1;
    int bit3 = (b >> 3) & 1;
    int bit4 = (b >> 4) & 1;
    int bit5 = (b >> 5) & 1;
    
    // 步骤1：交换位
    b = (b & ~0x03) | (bit1 << 0) | (bit0 << 1);
    b = (b & ~0x0C) | (bit3 << 2) | (bit2 << 3);
    b = (b & ~0x30) | (bit5 << 4) | (bit4 << 5);
    
    // 步骤2：循环左移低6位
    int rotate_count = (b >> 6) & 0x03;
    unsigned char low6 = b & 0x3F;
    low6 = ((low6 << rotate_count) | (low6 >> (6 - rotate_count))) & 0x3F;
    
    // 合并结果
    b = (b & 0xC0) | low6;
    
    return b;
}

int main() {
    char input[100];
    
    fgets(input, sizeof(input), stdin);
    
    for (int i = 0; input[i] != '\0' && input[i] != '\n'; i++) {
        unsigned char encrypted = encrypt_byte(input[i]);
        printf("%c", encrypted);
    }
    printf("\n");
    
    return 0;
}
/*位运算的一些技巧：

*/