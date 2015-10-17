/*
第二题：字母转换（20 分）
从键盘输入一个大写字母，要求改用小写字母输出。 （注：出自课本第三章
第 7 题）。
样例输入：
A
样例输出：
a
*/
#include <stdio.h>
#include <ctype.h>
int lower(int c1){
	if (c1>='A' && c1<='Z')
		return c1 + 'a' - 'A';
	else
		return c1;
}int main(){
	char c;
	scanf("%c",&c);
	printf("%c\n",tolower(c));
	return 0;
}
