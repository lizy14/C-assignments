/*
第四题：Runaround 数（25 分）
编写一个程序，输入一个 2~7 位的整数，然后判断它是否是一个 runaround
数。若是则输出 yes,  否则输出 no。一个 N 位的 runaround 数具有以下的特点。
a)  该整数有 N 位，每一位数字在 1~9 之间。
b)  这些数字构成了一个序列，序列中每位数字的值指明了下一个序列数所
在的位置。例如，假设当前数字为 2，则往右走 2 步，即到达下一个序列
数。若在此过程中到达了该整数的右边界，则返回到它的最左边。
c)  序列起始于该整数最左边的数字，并且在遍历该整数的所有数字各一次
后，又回到了起始位置。
d)  该整数的各位数字各不相同，没有重复。
例如，对于整数 81362，可以通过以下步骤来验证它是否是一个 runaround
数。
a)  从最左边的数字（即 8）开始：8 1 3 6 2。
b)  往右走 8 步，停在 6 上面（走到右边界时要返回到最左边）：8 1 3 6 2
c)  往右走 6 步，停在 2 上面：8 1 3 6 2
d)  往右走 2 步，停在 1 上面：8 1 3 6 2
e)  往右走 1 步，停在 3 上面：8 1 3 6 2
f)  往右走 3 步，即回到了起始位置：8 1 3 6 2
（注：出自课本第六章第 26 题）
样例输入：
81362
样例输出：
yes
*/
#include <stdio.h>
#include <string.h>
int valofchar(char chr)
{
	return chr - '0';
}
int main()
{
	char str[7]={0};
	int val[7]={0};
	int visited[7]={0};
	gets(str);
	int len=strlen(str);
	int i;
	//获得每一位数值
	for(i=0;i<=len-1;i++)
		val[i]=valofchar(str[i]);
	int crtpst=0;

	do
	{
		crtpst += val[crtpst];
		crtpst %= len;
		visited[crtpst]++;
		if(visited[crtpst]>1) break;
	}while(1);
	//检查是否遍历
	int allvisited=1;
	for(i=0;i<=len-1;i++)
		allvisited *= visited[i];
	printf("%s",allvisited? "yes": "no");

	return 0;
}
