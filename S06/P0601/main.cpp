/*
��һ�⣺�����ַ���25 �֣�
��дһ����������һ���ַ���ֻ������ĸ���ҳ���С�� 100���س�������
�룩 �����ַ�������ֻ��һ���ַ����ֵĴ���Ϊ�����������ַ����ֵĴ�����Ϊ
ż����������ִ���Ϊ�������ַ���
�������룺
abbcacdddad
���������
a
*/
#include <stdio.h>
#include <string.h>
int main()
{
	char str[101]={0};
	//Ϊÿ���ַ������������������±꼴ascii
	int lettercount[128]={0};
	gets(str);
	int len = strlen(str);
	int i;
	//���������ַ�����ÿһ���ַ�
	for(i=0;i<=len;i++)
		lettercount[(str[i])]++;
	//������������ĸ���������ֵ������
	for(i=1;i<=127;i++)
	{
		if( (lettercount[i]%2) ==1)
		{
			printf("%c\n",i);
			return 0;
		}
	}
}
