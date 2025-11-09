#include <stdio.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    int board[n][m];
    int mark[n][m];  // 标记是否消除，1 表示消除，0 表示保留
    
    // 初始化标记数组
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            mark[i][j] = 0;
        }
    }
    
    // 读入棋盘
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &board[i][j]);
        }
    }
    
    // 检查每一行
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; ) {
            int color = board[i][j];
            int count = 1;
            int k = j + 1;
            // 计算连续相同颜色的长度
            while (k < m && board[i][k] == color) {
                count++;
                k++;
            }
            // 如果连续长度 >= 3，标记这些位置
            if (count >= 3) {
                for (int t = j; t < j + count; t++) {
                    mark[i][t] = 1;
                }
            }
            j = k;  // 跳到下一段不同颜色的起始位置
        }
    }
    
    // 检查每一列
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; ) {
            int color = board[i][j];
            int count = 1;
            int k = i + 1;
            // 计算连续相同颜色的长度
            while (k < n && board[k][j] == color) {
                count++;
                k++;
            }
            // 如果连续长度 >= 3，标记这些位置
            if (count >= 3) {
                for (int t = i; t < i + count; t++) {
                    mark[t][j] = 1;
                }
            }
            i = k;  // 跳到下一段不同颜色的起始位置
        }
    }
    
    // 消除：被标记的位置设为 0
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mark[i][j] == 1) {
                board[i][j] = 0;
            }
        }
    }
    
    // 输出结果
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d", board[i][j]);
            if (j < m - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }
    
    return 0;
}