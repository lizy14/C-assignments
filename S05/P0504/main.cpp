/*
第四题：Anagrams 问题（20 分）
Anagrams 指的是具有如下特性的两个单词：在这两个单词当中，每一个英文
字母（不区分大小写）所出现的次数都是相同的。例如，Unclear 和 Nuclear、
Rimon 和 MinOR 都是 Anagrams。
编写一个程序，输入两个单词（只包含英文字母，且每一个单词的长度不会
超过 80 个字符），判断这两个单词是否是 Anagrams，如果是则输出“yes” ,否则
输出“no” 。
样例输入：
Unclear Nuclear
样例输出：
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
