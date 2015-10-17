/*
��һ�⣺�������㣨25 �֣�
���ʵ���������������㡣
Ҫ��
a) ����һ���ṹ������������������
b) ����֮��ļӷ����������˷��ͳ����ֱ��ò�ͬ�ĺ���ʵ�֣�
c) ����ʹ�ýṹ��ָ��ķ����Ѻ����ļ��������ء�
������û�����Ϊ���������(+,-,*,/) a b c d��������Ϊ��a+bi�����
ʱ���� a,b ��С�� 0 ����� 0 �����ø�ʽ��������ʱ a,b ������λ��
�������룺
- 2.5 3.6 1.5 4.9
���������
1.00+-1.30i

*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>


struct complex
{
	float real;
	float imaginary;
};
complex* plus_complex(complex* buffer, complex x1, complex x2)
{
	buffer->real = x1.real + x2.real;
	buffer->imaginary = x1.imaginary + x2.imaginary;
	return buffer;
}
complex* minus_complex(complex* buffer, complex x1, complex x2)
{
	buffer->real = x1.real - x2.real;
	buffer->imaginary = x1.imaginary - x2.imaginary;
	return buffer;
}
complex* multiply_complex(complex* buffer, complex x1, complex x2)
{
	float a=x1.real, b=x1.imaginary, c=x2.real, d=x2.imaginary;
	buffer->real = a*c-b*d;
	buffer->imaginary = b*c+a*d;
	return buffer;
}
complex* division_complex(complex* buffer, complex x1, complex x2)
{
	float a=x1.real, b=x1.imaginary, c=x2.real, d=x2.imaginary;
	if(c==0 && d==0) return NULL;
	buffer->real = (a*c+b*d)/(c*c+d*d);
	buffer->imaginary = (b*c-a*d)/(c*c+d*d);
	return buffer;
}

complex* calc_complex(complex* buffer, char op, complex x1, complex x2)
{
	switch(op)
	{
	case '+':
		buffer = plus_complex(buffer, x1, x2);
		break;
	case '-':
		buffer = minus_complex(buffer, x1, x2);
		break;
	case '*':
		buffer = multiply_complex(buffer, x1, x2);
		break;
	case '/':
		buffer = division_complex(buffer, x1, x2);
		break;
	}
	return buffer;
}
void print_complex(complex* x)
{
	if(x == NULL)
		puts("Error");
	else
		printf("%.2f+%.2fi", x->real, x->imaginary);
}
int main()
{
	complex x1, x2, ans;
	char op;
	scanf("%c %f %f %f %f", &op, &x1.real, &x1.imaginary, &x2.real, &x2.imaginary);
	//end of input
	print_complex(calc_complex(&ans, op, x1, x2));
	return 0;
} 