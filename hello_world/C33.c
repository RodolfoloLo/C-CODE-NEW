#include <stdio.h>
#include <assert.h>
#include <math.h>
#define R
// 函数声明
int integer_fraction(float x);

int main(void)
{
    float r, s;
    int s_integer = 0;
    
    printf("Input a number: ");
    scanf("%f", &r);

// 条件编译
#ifdef R
    s = 3.14159 * r * r;
    printf("Area of round is: %f\n", s);
    
    s_integer = integer_fraction(s);
    
    // 断言：检查小数部分是否小于0.5（用于四舍五入验证）
    assert(fabs(s - s_integer) < 0.5);
    
    printf("The integer fraction of area is %d\n", s_integer);
#endif

    return 0;
}

// 改进的整数转换函数（真正的四舍五入）
int integer_fraction(float x)
{
    // 方法1：直接四舍五入
    return (int)(x + 0.5);
    
    // 方法2：如果需要更精确的处理，可以用这个：
    // return (int)roundf(x);
}