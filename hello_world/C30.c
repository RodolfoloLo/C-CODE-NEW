#include<stdio.h>
int judge(int count[10]) {
    for(int i = 0; i < 10; i++) {
        if(count[i] > 1) {  // 应该是>1，因为每个数字最多出现一次
            return 0;
        }
    }
    return 1;
}
// 将数字分解为数组
void numberToArray(int num, int arr[5]) {
    for(int i = 4; i >= 0; i--) {
        arr[i] = num % 10;
        num /= 10;
    }
}
int main() {
    int result;
    scanf("%d", &result);
    for(int x_ = 1234; x_ <= 98765; x_++) {  // 从最小的5位数开始
        for(int y_ = 1234; y_ <= 98765; y_++) {
            // 检查除法结果
            if(y_ != 0 && x_ / y_ == result && x_ % y_ == 0) {
                int x_arr[5], y_arr[5];
                int count[10] = {0};
                // 将数字转换为数组
                numberToArray(x_, x_arr);
                numberToArray(y_, y_arr);
                // 统计数字出现次数
                for(int i = 0; i < 5; i++) {
                    count[x_arr[i]]++;
                    count[y_arr[i]]++;
                }
                // 检查是否有重复数字（0-9每个最多出现1次）
                int valid = 1;
                for(int i = 0; i < 10; i++) {
                    if(count[i] > 1) {
                        valid = 0;
                        break;
                    }
                }
                if(valid) {
                    if(x_arr[0] != 0 && y_arr[0] != 0) { 
                        printf("%d / %d = %d\n", x_, y_, result); // 排除前导零的情况
                    }else{
                        printf("%05d / %05d = %d\n", x_, y_, result);
                    }
                }
            }
        }
    }
    return 0;
}