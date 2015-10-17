/*
第五题：解方程（20 分）
求方程 ax^2+bx+c=0 的实数根。a,  b,  c 由键盘输入，-1000=<a,b,c<=1000 且
a!=0。若有两个实数根（b^2-4ac>0） ，则输出时大的实数根在前，小的在后；若只
有一个实数根（b^2-4ac=0） ，则只输出一个解；若无实数根（b^2-4ac<0） ，则输
出”Error”。 （注：结果保留小数点后 6 位）
样例输入 1：
2.5 7.5 1.0
样例输出 1（注意大的实数根在前，小的在后） ：
-0.139853
-2.860147
样例输入 2：
1.0 4.0 4.0
样例输出 2：
-2.000000
样例输入 3：
1.0 2.0 3.0
样例输出 3：
Error
*/ 
#include <stdio.h>
#include <math.h>
int main(){
	double a,b,c;
	scanf("%lf %lf %lf",&a,&b,&c);
	double delta=b*b-4*a*c;
	if(delta<0){
		printf("Error\n");
		return 0;
	}
	double sqrt_delta=sqrt(delta);
	double x1=(-b+sqrt_delta)/(2*a);
	if(delta==0){
		printf("%.6lf\n",x1);
		return 0;
	}
	double x2=(-b-sqrt_delta)/(2*a);
	/*保证x1>x2*/
	if(a<0){
		double x_temp;
		x_temp=x1,x1=x2,x2=x_temp;
	}
	printf("%.6lf\n%.6lf\n",x1,x2);
	return 0;
}
		

