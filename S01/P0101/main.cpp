/*
第一题：计算税额（20 分）
税务局希望你帮他们编写征税程序，该程序的功能是：首先输入某公司的年
销售额 sale 和税率 rate，然后程序将计算出相应的税额 tax，并把他显示在屏幕
上。计算公式是：tax=sale*rate，结果保留小数点后两位。 （注：出自课本第三章
第 3 题）。
样例输入：
500000 0.1
样例输出：
50000.00
*/ 
#include <stdio.h>
int main(){
float  rate, sale, tax;
	scanf("%f %f",&sale,&rate);
	tax=sale*rate;
	printf("%.2f\n",tax);
	return 0;
}
