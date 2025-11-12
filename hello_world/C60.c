#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare_asc(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int compare_desc(const void *a, const void *b) {
    return (*(int*)b - *(int*)a);
}

int main(int argc, char *argv[]) {
    printf("程序开始运行\n");
    fflush(stdout);  // 强制刷新输出缓冲区
    
    // 检查参数
    if (argc < 2) {
        printf("使用方法: %s 数量 [-d]\n", argv[0]);
        return 1;
    }
    
    int n = atoi(argv[1]);
    printf("需要输入 %d 个数字\n", n);
    fflush(stdout);
    
    int *arr = (int*)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("内存分配失败\n");
        return 1;
    }
    
    // 输入数字
    printf("请输入 %d 个数字: ", n);
    fflush(stdout);  // 重要：确保提示信息显示出来
    
    for(int i = 0; i < n; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            printf("输入错误\n");
            free(arr);
            return 1;
        }
    }
    
    printf("输入完成，开始排序...\n");
    
    // 排序
    if (argc == 3 && strcmp(argv[2], "-d") == 0) {
        qsort(arr, n, sizeof(int), compare_desc);
    } else {
        qsort(arr, n, sizeof(int), compare_asc);
    }
    
    // 输出结果
    for(int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) printf(" ");
    }
    printf("\n");
    
    free(arr);
    printf("程序结束\n");
    return 0;
}