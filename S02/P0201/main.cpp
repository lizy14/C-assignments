/*
��һ�⣺�����θߣ�20 �֣�
��дһ��������������ʵ����double ���ͣ�a��b �� c ��Ϊ�����ε�����
�ߣ�1 < a, b, c < 1000������������ܹ��������Σ��������߶�Ӧ�ĸߵĳ�
�ȣ�������ܹ��������Σ��������NO���� ����ʾ�����������������Բ��ú�
��-�ؾ��ع�ʽ��������� 6 λС����
�������� 1��
1.0 2.0 3.0
������� 1��
NO
�������� 2��
3.0 4.0 5.0
������� 2��
2.40
*/
#include <stdio.h>
#include <math.h>
double max(double a, double b, double c)
{
    return a >= b ? (a >= c ? a : c) : (b >= c ? b : c);
}
int is_triangle(double a, double b, double c)
{
    if ((a + b > c) && (b + c > a) && (a + c > b)) return 1;
    return 0;
}
int main()
{
    double a, b, c, S, h;
    double p;
    scanf("%lf %lf %lf", &a, &b, &c);
    if(! is_triangle(a, b, c))
    {
        printf("NO\n");
        return 0;
    }
    p = (a + b + c) / 2.0;
    S = sqrt(p * (p - a) * (p - b) * (p - c));
    h = 2 * S / max(a, b, c);
    printf("%.6lf\n", h);
    return 0;
}
