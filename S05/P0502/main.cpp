/*
�ڶ��⣺����������20 �֣�
��дһ�����򣬼����������������������һ������ n ��1 �� n �� 20�� ����
ʾ����ĳ��ȣ��ڶ������������и���Ԫ�ص�ֵ�� ��������г��ִ�������Ԫ
�ء����������Ԫ�س��ֵĴ�����ͬ�������е�һ����ôֻ�����С���Ǹ�Ԫ�ء�
��ע������������ǵ������飬�Ѿ��ź��򣬳����в���Ҫ��������
�������룺
6
100 150 150 200 200 250
���������
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
