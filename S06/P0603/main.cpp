/*
第三题：整数循环（25 分）
编写一个程序，输入一个 4 位的正整数，将组成该数的各位数字重新排列，
形成一个最大数和一个最小数，之后用最大数减去最小数，得到一个新的正整数
（该数一定大于 1000）。然后对于这个新的正整数，重复上述步骤，直到该正整
数的值不再发生变化。
例如，假设用户输入的正整数为 1001，那么由它所形成的最大数为 1100，最
小数为 11，因此新的正整数为 1089。对于 1089，由它形成的最大数为 9810，最
小数为 189，因此新的正整数为 9621。9621 的最大数为 9621，最小数为 1269，
结果为 8352,。8352 的最大数为 8532，最小数为 2358，结果为 6174。6174 的最
大数为 7641，最小数为 1467，结果仍为 6174，因此程序结束。 （注： 出自课本第
六章第 22 题）
样例输入：
1001
样例输出：
6174
*/

#include <stdio.h>
//{4,3,2,1} -> 4321 的因子
int power10(int position)
{
	int val[4]={1000,100,10,1};
	return val[position];
}
//{4,3,2,1} -> 4321
int digstoval(int * digits)
{
	int i;
	int sum=0;
	for(i=0; i<4; i++)
		sum += digits[i] * power10(i);
	return sum;
}
//4321 -> {4,3,2,1}
void valtodigs(int val, int * digits)
{
	int i;
	for(i=3; i>=0; i--)
	{
		digits[i] = val % 10;
		val /= 10;
	}
}
//冒泡法，升序排列
void sort(int * a)
{
	int n = 4;
	{
		int i,j,temp;
		for(i=0;i<n-1;i++)
		{
			for(j=i+1;j<n;j++)
			{
				if(a[i]>a[j])
				{
					temp=a[i];
					a[i]=a[j];
					a[j]=temp; 
				} 
			} 
		} 
	}
}
//用指针交换两个变量的值
void exchange(int * val1, int * val2)
{
	int temp;
	temp = *val1;
	*val1 = *val2;
	*val2 = temp;
}
//反转，和sort配合，进行降序排列
void reverse(int * digits)
{
	exchange(&digits[1],&digits[2]);
	exchange(&digits[0],&digits[3]);
}
//按规则由一个整数生成下一个整数
int diff(int val)
{
	//将 4321 转换成 {4,3,2,1} 处理，便于排序
	int digits[4];
	valtodigs(val, digits);

	int max, min;
	sort(digits);
	min = digstoval(digits);
	reverse(digits);
	max = digstoval(digits);
	return max - min;
}

int main()
{
	int original;
	scanf("%d", &original);
	//输入结束

	int last = original, current;
	while(1)
	{
		current = diff(last);
		if(current==last)
		{
			printf("%d", current);
			return 0;
		}
		last = current;
	}
	return 0;
}
