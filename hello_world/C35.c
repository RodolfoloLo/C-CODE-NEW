#include<stdio.h>
long long factorial(int n){
    if(n==1){
        return 1;
    }
    return n*factorial(n-1);
}
long long sum_fac(int n){
    if(n==1){
        return 1;
    }
    long long sum=sum_fac(n-1)+factorial(n);
    return sum;
}
int main(void)
{
	int k;
	for(k=1; k<=20; k++)
		printf("k=%d the sum is %lld\n",k,sum_fac(k));
	return 0;
}
