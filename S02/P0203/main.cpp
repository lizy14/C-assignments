/*
�����⣺�ַ�ͳ�ƣ�20 �֣�
��дһ�����򣬲��������ַ�ֱ��������#��Ϊֹ��Ȼ���������Ŀո�   ������
�з���\n���������ַ������� ��ע�����ġ�#�������������ַ���
�������룺
Chapter 1. Getting Ready
Chapter 2. Introducing C
Chapter 3. #
���������
8 2 51 
*/ 
#include <stdio.h>
int main()
{
	int c;
	int space = 0, newline = 0, other = 0;
	while((c = getchar()) != '#')
	{
		if(c == ' ')
		{
			space++;
			continue;
		}
		if(c == '\n')
		{
			newline++;
			continue;
		}
		other++;
	}
	printf("%d %d %d", space, newline, other);
	return 0;
}
