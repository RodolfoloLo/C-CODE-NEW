#include<stdio.h>
#include<string.h>
#define MAX 100
long long int memo[MAX];
void init_memory(){ 
    memset(memo, -1, sizeof(memo));
    memo[0] = 0;
    memo[1] = 1;
}
long long int fabonacci_memory(int n){
    if(memo[n] != -1){
        return memo[n];
    }
    memo[n] = fabonacci_memory(n-1) + fabonacci_memory(n-2);
    return memo[n];
}
int main(){
    int n;
    scanf("%d", &n);
    init_memory();
    long long int result = 0;
    for(int i = 0; i <= n; i++){
        result+=fabonacci_memory(i);
    }
    printf("%lld\n", result);
    return 0;
}//斐波那契数列求和，使用记忆化递归优化计算过程，避免重复计算，提高效率，学会来，记忆化递归是一种常用的动态规划技术。