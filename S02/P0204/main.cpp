/*
第四题：数字逆序（20 分）
编写一个程序，输入一个正整数 a，1 ≤ a ≤ 999，然后把这个数逆序显示。
例如：如果用户输入了 123，那么程序的输出为“321”；如果用户输入了 65，那
么程序的输出为“56”。
样例输入：
100
样例输出：
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
