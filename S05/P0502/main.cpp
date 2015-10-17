/*
第二题：计算众数（20 分）
编写一个程序，计算递增数组的众数。程序第一行输入 n （1 ≤ n ≤ 20） ，表
示数组的长度；第二行输入数组中各个元素的值。 输出数组中出现次数最多的元
素。如果有两个元素出现的次数相同，即并列第一，那么只输出较小的那个元素。
（注：输入的数组是递增数组，已经排好序，程序中不需要进行排序）
样例输入：
6
100 150 150 200 200 250
样例输出：
150
*/ 
#include <stdio.h>
int main()
{
	int n, i;
	scanf("%d", &n);
	int most, most_times=1;
	int last, current, current_times=1;
	for(i=1; i<=n; i++)
	{
		scanf("%d", &current);
		if(i == 1){most = last = current; continue;};
		if(current == last)
		{
			current_times++;
			if(current_times > most_times)
			{
				most_times = current_times, most = current;
			}
		}
		else
		{
			current_times = 1;
		}
		last = current;
	}
	printf("%d", most);
	return 0;
}
