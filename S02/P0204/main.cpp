/*
�����⣺��������20 �֣�
��дһ����������һ�������� a��1 �� a �� 999��Ȼ��������������ʾ��
���磺����û������� 123����ô��������Ϊ��321��������û������� 65����
ô��������Ϊ��56����
�������룺
100
���������
001
*/
#include <stdio.h>
int main()
{
	printf("#include <stdio.h>\nint main()\n{\n\tint input;\n\tscanf(\"%%d\", &input);\n\tswitch (input)\n\t{\n");
	int digit1, digit2, digit3, input;
	for (input=1; input <= 999; input++)
	{
		if (input < 10)
		{
			printf("\t\tcase %3d: printf(\"%d\"); break;\n",input, input);
		}
		else if (input < 100)
		{
			digit2 = input % 10;
			digit1 = input / 10; 
			printf("\t\tcase %3d: printf(\"%d%d\"); break;\n", input, digit2, digit1);
			
		}
		else
		{
			
			digit3 = input % 10;
			digit2 = (input / 10) % 10; 
			digit1 = input / 100; 
			printf("\t\tcase %3d: printf(\"%d%d%d\"); break;\n", input, digit3, digit2, digit1);
		}
	}
	printf("\t}\n\treturn 0;\n}\n\n");
	return 0;
}
