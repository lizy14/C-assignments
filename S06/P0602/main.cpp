/*
�ڶ��⣺�ַ�������25 �֣�
��дһ�����򣬴Ӽ�������һ���ַ��������Ȳ����� 100 ���ַ�����Ȼ�󽫸�
�ַ���������Ҫ����
a)  ������ԭ���ַ��ĸ��ַ���ԭ���໥���˳���ϵ�����б�����ԭ����
������ߣ�
b)  ��С�ڵ���ԭ���ַ��ĸ��ַ����� ASCII ��ֵ�����򶼼��б�����ԭ��
�ַ����ұߡ�
������������֮�󣬽���õ�һ���µ��ַ�����Ȼ�󽫸��ַ�����ӡ������
˵����
a)  ����ʹ���ַ�����洢������ַ�����
b)  ����������ַ������п��ܰ����пհ��ַ�����ո�Tab ����������Ӧ
��ʹ�� gets ��������ȡ����ַ�������Ҫ�� scanf ������
c)  ������ַ����ܰ�����Сд������ţ�
d)  ��ʾ������ʹ�� gets��puts��strcpy��strcat ���ַ�����������
�������룺
abcdABCD1234
���������
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
