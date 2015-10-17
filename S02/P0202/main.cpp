/*
第二题：成绩分级（20 分）
编写一个程序， 输入一个百分制成绩 （整数） ，输出相应的成绩等级。规定：
90 或 90 分以上为 A，80-89 分为 B，70-79 分为 C，60-69 分为 D，60 分以下为
F。 （注：出自课本第四章第 7 题）
样例输入：
43
样例输出：
F
*/
#include <stdio.h>
int main()
{
    int score;
    char grade;
    scanf("%d", &score);
    switch (score/10)
    {
        case 10:
        case 9:
            grade = 'A';
            break;
        case 8:
            grade = 'B';
            break;
        case 7:
            grade = 'C';
            break;
        case 6:
            grade = 'D';
            break;
        default:
            grade = 'F';
    }
    printf("%c\n", grade);
    return 0;
}
