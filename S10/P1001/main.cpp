/*
第一题：复数运算（25 分）
编程实现两个复数的运算。
要求：
a) 定义一个结构体类型来描述复数；
b) 复数之间的加法、减法、乘法和除法分别用不同的函数实现；
c) 必须使用结构体指针的方法把函数的计算结果返回。
程序的用户输入为：运算符号(+,-,*,/) a b c d；输出结果为：a+bi，输出
时不管 a,b 是小于 0 或等于 0 都按该格式输出，输出时 a,b 保留两位。
样例输入：
- 2.5 3.6 1.5 4.9
样例输出：
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