#include<stdio.h>
double sum(double x,int n);
double mulx(double x,int n);
long fac(int n);

double sum(double x,int n){
    if(n==1){
        return x+1;
    }else{
        return sum(x,n-1)+mulx(x,n)/fac(n);
    }
}
double mulx(double x,int n){
	int i;
	double z=1.0;
	for(i=0;i<n;i++)
	{
		z=z*x;
	}
	return z;
}
long fac(int n){
    if(n==1)
        return 1;
    else
        return n*fac(n-1);
	
}

int main()
{
	double x;
	int n;
	scanf("%lf%d",&x,&n);
	printf("The result is %lf",sum(x,n));
	return 0;
} 