/*
第三题：字符统计（20 分）
编写一个程序，不断输入字符直到遇到’#’为止。然后输出读入的空格’   ’，换
行符’\n’和其它字符个数。 （注：最后的‘#’不计入其他字符）
样例输入：
Chapter 1. Getting Ready
Chapter 2. Introducing C
Chapter 3. #
样例输出：
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
