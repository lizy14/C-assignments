/*
�ڶ��⣺strcmp������25�֣�
��C�����У���һ��strcmp�������书���ǱȽ������ַ���s1��s2�����
дһ�����Լ����ַ����ȽϺ���my_strcmp����ʵ��strcmp���������ƹ��ܡ���
��s1=s2���򷵻�0�����򷵻�s1 ��s2 ��һ����ͬ�ַ��Ĳ�ֵ�����s1<s2����
��ֵ��һ�����������s1>s2���ò�ֵ��һ����������
��д���Գ���������������С��1000���ַ��������ܰ����пո��ҳ���
��һ����ȣ���Ȼ�����my_strcmp���������бȽϣ���������ؽ������ע����
�Կα������µ�12�⣩
�������룺
aBcDefgf
aacdef
���������
-31
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
int my_strcmp(char* s1, char* s2)
{
	int l1=strlen(s1);
	int l2=strlen(s2);
	int i, dif;
	for(i=0; i<(l1>=l2? l1:l2); i++)
	{
		if(dif=s1[i]-s2[i])
			return dif;
	}
	return 0;
}
int main()
{
	char s1[1000]={0};
	char s2[1000]={0};
	gets(s1);
	gets(s2);
	printf("%d",my_strcmp(s1, s2));
	return 0;
} 
