/*
第一题：奇数字符（25 分）
编写一个程序，输入一组字符（只包含字母，且长度小于 100，回车结束输
入） ，该字符数组中只有一个字符出现的次数为奇数，其他字符出现的次数均为
偶数，输出出现次数为奇数的字符。
样例输入：
abbcacdddad
样例输出：
a
*/
#include <stdio.h>
#include <string.h>
int main()
{
	char str[101]={0};
	//为每个字符建立计数器，数组下标即ascii
	int lettercount[128]={0};
	gets(str);
	int len = strlen(str);
	int i;
	//遍历输入字符串的每一个字符
	for(i=0;i<=len;i++)
		lettercount[(str[i])]++;
	//下面遍历查找哪个计数器的值是奇数
	for(i=1;i<=127;i++)
	{
		if( (lettercount[i]%2) ==1)
		{
			printf("%c\n",i);
			return 0;
		}
	}
}
