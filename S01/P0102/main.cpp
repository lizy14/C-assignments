/*
�ڶ��⣺��ĸת����20 �֣�
�Ӽ�������һ����д��ĸ��Ҫ�����Сд��ĸ����� ��ע�����Կα�������
�� 7 �⣩��
�������룺
A
���������
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
