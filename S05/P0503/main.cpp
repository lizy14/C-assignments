/*
�����⣺���ʸ���ͳ�ƣ�20 �֣�
��дһ����������һ�����ӣ�Ȼ��ͳ�Ƴ�������ӵ��в�ͬ�ĵ��ʸ�����
���磬���ھ��ӡ�one little two little three  little boys�����ܹ��� 5 ����ͬ�ĵ��ʣ�
one, little, two, three, boys��
˵����
a)  ���ھ��ӵ��а����пո�����Ӧ���� gets ����������������ӡ�
b)  ����ľ��ӵ���ֻ����Ӣ���ַ��Ϳո񣬵���֮����һ���ո������
c)  ���ÿ��ǵ��ʵĴ�Сд����������Ķ���Сд�ַ���
d)  ���ӳ��Ȳ����� 100 ���ַ�
�������룺
one little two little three little boys
���������
5
*/

#include <stdio.h>
#include <string.h>
#include <math.h>
long long int power26(int letter,int times)//���� char * 26^int
{
	long long int temp=1;
	int i;
	for(i=0; i<=times-1; i++)
	{
		temp *= 26;
	}
	return letter * temp;
}
int getlettervalue(char letter)
{
	if(letter>='a' && letter<='z')letter -= 32;
	letter -= 64;
	return letter;
}
long long int getstrvalue(char * str, int length)
{
	int i;
	long long int sum=0;
	for(i=0;i<length;i++)
	{
		if(str[i]=='\0') return sum;
		sum += power26(getlettervalue(str[i]), i);
	}
	return sum;
}
int main()
{
	char str[102]={0};
	gets(str);
	long long int currentword;
	int memorized_words[52]={0};
	int memorized_words_count=0;
	int most, lastspace=-1, length = strlen(str);
	int i, i2;
	int notexist;
	for(i=1; i<=length; i++)
	{   
		if(str[i]=='\0' || str[i]==' ' || str[i]=='\n' )
		{
			
			currentword = getstrvalue(&str[lastspace+1], i-lastspace-1);
			
			//������ currentword �Ƿ������ memorized_words[] ��
			notexist=1;
			for(i2=1; i2<=memorized_words_count; i2++)
			{
				notexist *= ((currentword - memorized_words[i2])==0 ? 0 : 1);
				//������� 0�����Ѵ��ڣ� notexist ��� 0

			}
			if(notexist)
			{
				memorized_words_count ++;
				memorized_words[memorized_words_count] = currentword;
			}

			lastspace = i;
		}
	}
	printf("%d", memorized_words_count);

	return 0;
}
