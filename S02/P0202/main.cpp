/*
�ڶ��⣺�ɼ��ּ���20 �֣�
��дһ������ ����һ���ٷ��Ƴɼ� �������� �������Ӧ�ĳɼ��ȼ����涨��
90 �� 90 ������Ϊ A��80-89 ��Ϊ B��70-79 ��Ϊ C��60-69 ��Ϊ D��60 ������Ϊ
F�� ��ע�����Կα������µ� 7 �⣩
�������룺
43
���������
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
