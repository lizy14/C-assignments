/*
��һ�⣺�ַ�ɾ����20 �֣�
��дһ�����򣬵�һ������һ���ַ��� str �����Ȳ����� 20�����ڶ������뵥
����һ���ַ� ch��Ҫ�������ַ��� str �������е� ch �ַ���ɾ�����Ӷ��õ�
һ���µ��ַ���������µ��ַ�����
�������룺
123-45-678
-
���������
12345678
*/ 
#include <stdio.h>
int main()
{
	char str[21]={0}, res[21]={0};
	char ch;
	gets(str);
	ch = getchar();
	int i, count=0;
	for(i=0; i<20; i++)
	{
		if (i+count >= 20) break;
		while (str[i+count] == ch) 
		{
			count++;
			if (i+count >= 20) break;
		}
		if (i+count >= 20) break;
		res[i]=str[i+count];
	}

	puts(res);
	return 0;
}
