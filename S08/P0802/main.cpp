/*
�ڶ��⣺�ַ������ʽ��25�֣�
��д�����ڳ�����ʵ���ַ������ʽ��⺯��int expression(char* s)���� ��
����Ϊһ���ַ������ʽ�����Ϊ�ú������صĽ��������ı��ʽ��ֻ������
���ͼ������ԵȺš�=�����������Ȳ�����100������������һ������������
������Χ֮�ڡ�
�������룺
2+2345+913-3=
���������
3257
*/

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

//�궨��
#define for_(i,x,y) for(i=x; i<=y; i++)//�����ٰ��ܶ�μ��̣���Լʱ�䣡
#define chartoint(x) (x - '0') //��߿ɶ��ԣ����ظ�ʹ�ã�

int expression(char* s)
{
	int val = 0;
	int i;
	int len=strlen(s);
	int op = 1;  //��һ�������
	int num = 0; //��������
	for_(i, 0, len - 1)
	{
		switch(s[i])
		{
		case '=':
			val += op*num;
			break;
		case '+':
			val += op*num;
			num = 0;
			op = +1;
			break;
		case '-':
			val += op*num;
			num = 0;
			op = -1;
			break;
		default:
			num *= 10;
			num += chartoint(s[i]);
		}
	}
	return val;
}
int main()
{
	char s[102];
	gets(s);
	printf("%d", expression(s));
	return 0;
} 