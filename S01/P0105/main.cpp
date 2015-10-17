/*
�����⣺�ⷽ�̣�20 �֣�
�󷽳� ax^2+bx+c=0 ��ʵ������a,  b,  c �ɼ������룬-1000=<a,b,c<=1000 ��
a!=0����������ʵ������b^2-4ac>0�� �������ʱ���ʵ������ǰ��С���ں���ֻ
��һ��ʵ������b^2-4ac=0�� ����ֻ���һ���⣻����ʵ������b^2-4ac<0�� ������
����Error���� ��ע���������С����� 6 λ��
�������� 1��
2.5 7.5 1.0
������� 1��ע����ʵ������ǰ��С���ں� ��
-0.139853
-2.860147
�������� 2��
1.0 4.0 4.0
������� 2��
-2.000000
�������� 3��
1.0 2.0 3.0
������� 3��
Error
*/ 
#include <stdio.h>
#include <math.h>
int main(){
	double a,b,c;
	scanf("%lf %lf %lf",&a,&b,&c);
	double delta=b*b-4*a*c;
	if(delta<0){
		printf("Error\n");
		return 0;
	}
	double sqrt_delta=sqrt(delta);
	double x1=(-b+sqrt_delta)/(2*a);
	if(delta==0){
		printf("%.6lf\n",x1);
		return 0;
	}
	double x2=(-b-sqrt_delta)/(2*a);
	/*��֤x1>x2*/
	if(a<0){
		double x_temp;
		x_temp=x1,x1=x2,x2=x_temp;
	}
	printf("%.6lf\n%.6lf\n",x1,x2);
	return 0;
}
		

