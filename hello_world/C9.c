#include <stdio.h>
//杨辉三角，困难题，
int main() {
    int n;
    scanf("%d", &n);
    
    int triangle[10][10] = {0}; // 初始化为0
    
    // 生成杨辉三角
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i) {
                triangle[i][j] = 1;  // 每行的第一个和最后一个数为1
            } else {
                triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j];
            }
        }
    }
    
    // 打印杨辉三角
    for (int i = 0; i <= n; i++) {
        // 打印前导空格实现居中对齐
        for (int k = 0; k <= n - i ; k++) {
            printf("00");
        }
        
        // 打印数字
        for (int j = 0; j <= i; j++) {
            printf("%03d ", triangle[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}