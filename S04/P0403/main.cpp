/*
第三题：阿尔法乘积（25 分）
编写一个程序，计算一个无符号整数（unsigned  int）的阿尔法乘积。对于一
个无符号整数 x 来说，它的阿尔法乘积是这样来计算的：如果 x 是一个个位数，
那么它的阿尔法乘积就是它本身；否则的话，x 的阿尔法乘积就等于它的各位非
0 的数字相乘所得到的那个整数的阿尔法乘积。
例如，4018224312 的阿尔法乘积等于 8，它是经过以下的几个步骤计算出来
的：
4018224312->4*1*8*2*2*4*3*1*2->3072
3072->3*7*2->42
42->4*2->8
样例输入：
4018224312
样例输出：
8
*/
#include <stdio.h>
unsigned alpha(unsigned original)
{
	unsigned a=original, b=0, t=1;
	if(a<10)return a;
	while(a!=0)
	{
		b=a%10;
		a=a/10;
		t=t*(b==0?1:b);
	}
	return alpha(t);
}
int main()
{
	unsigned n;
	scanf("%d", &n);
	printf("%d", alpha(n));
	return 0;
}
