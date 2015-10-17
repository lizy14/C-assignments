/*
第四题：大数乘法（25分）
当两个比较大的整数相乘时，可能会出现数据溢出的情形。为避免溢出，可
以采用字符串的方法来实现两个大数之间的乘法。具体来说，首先以字符串的形
式输入两个整数，每个整数的长度不超过10位，然后把它们相乘的结果存储在
另一个字符串当中（长度不会超过20位），最后把这个字符串打印出来。
例如，假设用户输入为：9999999999 和1000000000，则输出结果为：
9999999999000000000。
编写程序，在程序中实现函数 void multiply(char* s1, char* s2, char* 
result)，其中参数s1和s2为输入的两个数，result = s1 * s2。
样例输入：
9999999999 1000000000
样例输出：
9999999999000000000
*/

#define _CRT_SECURE_NO_WARNINGS

//#define DEBUGING

#include <stdio.h>
#include <string.h>
#define for_(i,x,y) for(i=x; i<=y; i++)
#define chartoint(x) (x - '0')
#define inttochar(x) (x + '0')
#define ext 0

void multiply(char* s1, char* s2, char* result)
{
	int i, j;
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	int val[20 + ext + ext] = {0};
	int x1[10 + ext]={0};
	int x2[10 + ext]={0};

	//"2048" --> {8,4,0,2}
	for_(i, 0, len1 - 1)
		x1[i] = chartoint(s1[len1 -1 - i]);
	for_(i, 0, len2 - 1)
		x2[i] = chartoint(s2[len2 -1 - i]);
#ifdef DEBUGING
	for_(i, 0 , 9 + ext)
		printf("%d ", x1[i]);
	putchar('\n');
	for_(i, 0 , 9 + ext)
		printf("%d ", x2[i]);
	putchar('\n');
#endif



	for_(i, 0, len1 - 1)
	{
		for_(j, 0, len2 - 1)
		{
			val[i+j] += x1[i] * x2[j];
		}
	}
#ifdef DEBUGING
	for_(i, 0 , 19 + ext)
		printf("%d ", val[i]);
	putchar('\n');
#endif
	
	//进位
	for_(i, 0 , 18 + ext)
	{
		val[i+1] += val[i] / 10;
		val [i] %= 10;
	}
#ifdef DEBUGING
	for_(i, 0 , 19 + ext)
		printf("%d ", val[i]);
	putchar('\n');
#endif


	//数字串转字符串
	
	int h;//最高位
	for(i = 19 + ext; i>=0; i--)
	{
		if(val[i] != 0)
		{
			h=i;
			break;
		}
	}
	j = 0;
	for(i = h; i>=0; i--)
	{
		result[j] = inttochar(val[i]);
		j++;		
	}
	result[j] = 0;
	return;
}
int main()
{
	char x[11 + ext], y[11 + ext];
	char result[21 + ext + ext];
	scanf("%s %s", x ,y);
	multiply(x, y, result);
	puts(result);
	return 0;
} 