/*
第三题：成绩排序（25分）
定义一个学生结构体类型student，包 括4个字段，姓名、性别、年龄和成绩。
然后在主函数中定义一个结构体数组（长度不超过1000），并输入每个元素的值，
内部资料  清华大学软件学院软件工程（1）作业    第2页  共3页 
程序使用冒泡排序法将学生按照成绩从小到大的顺序排序，然后输出排序的结果。
输入格式：第一行是一个整数N（N<1000），表示元素个数；接下来N行每
行描述一个元素，姓名、性别都是长度不超过20的字符串，年龄和成绩都是整
型。
输出格式：按成绩从小到大输出所有元素，若多个学生成绩相同则成绩相同
的同学之间保留原来的输入顺序。
样例输入：
3
Alice female 18 98
Bob male 19 90
Miller male 17 92
样例输出：
Bob male 19 90
Miller male 17 92
Alice female 18 98
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define for_(i,x,y) for(i=x; i<=y; i++)

struct student
{
	char name[21];
	char gender[21];
	int age;
	int score;
};

void sort(student student_[],int n)
{
	int i,j;
	student temp;
	for(i=0;i<n-1;i++)
	{
		for(j=0;j<n-1-i;j++)
		{
			if(student_[j].score>student_[j+1].score)
			{
				temp=student_[j];
				student_[j]=student_[j+1];
				student_[j+1]=temp; 
			} 
		} 
	} 
}

int main()
{
	student student_[1000];
	int n;
	scanf("%d", &n);
	int i;
	for_(i, 0, n-1)
		scanf("%s %s %d %d", 
		&student_[i].name,
		&student_[i].gender,
		&student_[i].age,
		&student_[i].score);
	//end of input

	sort(student_, n);

	for_(i, 0, n-1)
		printf("%s %s %d %d\n", 
		student_[i].name,
		student_[i].gender,
		student_[i].age,
		student_[i].score);
	return 0;
} 
