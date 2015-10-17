/*
第一题：三角形高（20 分）
编写一个程序，输入三个实数（double 类型）a、b 和 c 作为三角形的三条
边，1 < a, b, c < 1000。如果三条边能构成三角形，则输出最长边对应的高的长
度；如果不能构成三角形，则输出“NO”。 （提示：三角形面积计算可以采用海
伦-秦九韶公式，结果保留 6 位小数）
样例输入 1：
1.0 2.0 3.0
样例输出 1：
NO
样例输入 2：
3.0 4.0 5.0
样例输出 2：
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
