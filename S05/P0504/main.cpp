/*
�����⣺Anagrams ���⣨20 �֣�
Anagrams ָ���Ǿ����������Ե��������ʣ������������ʵ��У�ÿһ��Ӣ��
��ĸ�������ִ�Сд�������ֵĴ���������ͬ�ġ����磬Unclear �� Nuclear��
Rimon �� MinOR ���� Anagrams��
��дһ�����������������ʣ�ֻ����Ӣ����ĸ����ÿһ�����ʵĳ��Ȳ���
���� 80 ���ַ������ж������������Ƿ��� Anagrams��������������yes�� ,����
�����no�� ��
�������룺
Unclear Nuclear
���������
yes
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
char* lowerword(char* word)
{
	int i, length=strlen(word);
	for(i=0; i<=length; i++)
		word[i]=tolower(word[i]);
	return word;
}
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
	char word1[81]={0};
	char word2[81]={0};

	scanf("%s %s", word1, word2);
	lowerword(word1), lowerword(word2);
	//printf("\n%s %s\n", word1, word2);
	int length1=strlen(word1),length2=strlen(word2);
	sort(word1,length1);
	sort(word2,length2);
	//printf("\n%s %s\n", word1, word2);
	printf("%s", strcmp(word1, word2)==0? "yes": "no");

	return 0;
}
