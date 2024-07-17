//P1024 [NOIP2001 提高组] 一元三次方程求解
//好像会了 不确定 再看看
//感谢深入浅出喵！
//一定记得都改double…… 
//#include <iostream>
#include <cstdio>
#include <cmath> 
//using namespace std;
double a, b, c, d;
int cnt;
double calc(double x);

int main(void){
	scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
	for(int i = -100; i < 100; i++){
		double l = i;
		double r = l+1;
		double x1 = calc(l);
		double x2 = calc(r);
		if(x1 == 0){
			printf("%.2lf ", l);
			cnt++;
		}
		else if(x1*x2<0){
			while(r-l >= 0.0001){
				double mid = (r+l)/2;
				if(calc(l)*calc(mid) < 0)	r = mid;
				else	l = mid;
			}
			printf("%.2lf ", r);
			cnt++;
		}
	}
	return 0;
}

double calc(double x){
	return a*x*x*x + b*x*x + c*x + d;
}
