/*
第二题：字符串排序（25 分）
编写一个程序，从键盘输入一个字符串（长度不超过 100 个字符），然后将该
字符串按如下要求处理：
a)  将大于原首字符的各字符按原来相互间的顺序关系都集中保存在原首字
符的左边；
b)  将小于等于原首字符的各字符（按 ASCII 码值）升序都集中保存在原首
字符的右边。
经过上述处理之后，将会得到一个新的字符串，然后将该字符串打印出来。
说明：
a)  可以使用字符数组存储输入的字符串；
b)  由于输入的字符串当中可能包含有空白字符（如空格、Tab 键），所以应
该使用 gets 函数来读取这个字符串，不要用 scanf 函数；
c)  输入的字符可能包含大小写或标点符号；
d)  提示：可以使用 gets、puts、strcpy、strcat 等字符串处理函数。
样例输入：
abcdABCD1234
样例输出：
bcda1234ABCD
*/
#include <stdio.h>
#include <string.h>
void sort(char a[],int n)
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
int main()
{
	char strin[101]={0};
	char strout[101]={0};
	char strbig[101]={0}; int ibig=0;
	char strsmall[101]={0}; int ismall=0;
	gets(strin);
	char mid=strin[0];
	char strmid[2]={mid,0};
	int len=strlen(strin);
	int i;
	for(i=1;i<len;i++)
	{
		if(strin[i]>mid)
		{
			strbig[ibig++]=strin[i];
		}
		else if (strin[i]<=mid)
		{
			strsmall[ismall++]=strin[i];
		}

	}
	sort(strsmall,ismall);
	strsmall[ismall]=0;
	strbig[ibig]=0;
	strcat(strout, strbig);
	strcat(strout, strmid);
	strcat(strout, strsmall);
	puts(strout);
	return 0;
}
