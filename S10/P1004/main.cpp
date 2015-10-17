/*
第四题：用户管理（25 分）
编写一个程序，首先根据用户的输入信息创建一条链表 LA，每个链表结点
的内容为学生的学号（正整数），各结点之间按学号升序排列。然后再根据用户
的输入信息创建另一条链表 LB，每个链表结点包括学生的学号 S 和一个运算符
O，O 的值为“增加”或“删除”。接下来，程序将对 LB 的每个结点进行分析，
如果 O 的值为“增加”，则在链表 LA 中新增一个结点，其学号即为 S；如果 O
的值为“删除”，则在链表 LA 中，找到学号为 S 的结点并将其删除（若找不到
学号为 S 的结点，则不予处理）。在经过上述处理后，要求 LA 中的结点依然按
学号升序排列。
说明：
a)  在创建链表时，为了减少内存空间的浪费，必须采用动态链表的方法，
即每一个链表结点都是根据需要动态创建的；
b)  为了增强程序的可读性，应采用多函数的形式来实现，至少应包含如下
的函数：创建链表、增加节点、删除节点、打印链表等。
输入格式：第一行是一个整数 M，表示链表 LA 的结点个数，接下来有 M 行，
每一行是一个整数 si，表示第 i 个结点的学号（按照从小到大排序）。接下来的一
行是一个整数 N，表示链表 LB 的结点个数，再接下来有 N 行，每一行是两个整
数 si 和 oi，其中， si 表示第 i 个结点的学号（按照从小到大排序）， oi 表示运算符，
oi  为 1 表示“增加”结点，oi 为 0 表示“删除”结点。
输出格式：输出经过处理以后的链表 LA 的内容。假设该链表共有 K 个结点，
则输出有 K 行，每一行是一个整数，即相应的学号。
样例输入：
4
1001
1003
1005
1007
2
1002 1
1007 0
样例输出：
1001
1002
1003
1005
*/




#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define for_(i,x,y) for(i=x; i<=y; i++)

struct A
{
	int id;
	A *next;
};
struct CMD
{
	int id;
	int op;
	CMD *next;
};
void printlist(A *head)
{
	A *p = head;
	while(233)
	{
		if(p == NULL) break;
		printf("%d\n", p->id);
		p = p->next;
	}
}

A* newid(A *head, int id)
{
	A *q = head, *p;
	A *newA = (A*)malloc(sizeof(A));
	newA->id = id;
	if(head->id > id)
	{
		newA->next = head;
		return newA;
	}
	while(233)
	{
		if(q == NULL) break;
		p = q->next;
		
		if((p == NULL || p->id > id) && q->id < id)
		{
			q->next = newA, newA->next = p;
			break;
		}
		q = q->next;
	}
	return head;
}
		
A* deleteid(A *head, int id)
{
	A *q = head, *p;
	if(head->id == id)
	{
		return head->next;
	}
	while(233)
	{
		if(q == NULL) break;
		p = q->next;
		if(p == NULL) break;
		if(p->id == id)
		{
			q->next = p->next;
			break;
		}
		q = q->next;
	}
	return head;
}
int main()
{
	int i, n, x, y;
	A *headA, *pA, *qA;
	CMD *headCMD, *pCMD, *qCMD;

	//input listA
	pA=qA=headA=NULL;
	scanf("%d", &n);
	for_(i, 1, n)
	{
		pA=(A*)malloc(sizeof(A));
		scanf("%d", &x);
		pA->id = x;
		if(headA == NULL)
			headA = pA, qA = pA;
		else
			qA->next = pA, qA = pA;
	}
	if(qA != NULL) qA->next = NULL;




	//input listCMD
	pCMD=qCMD=headCMD=NULL;
	scanf("%d", &n);
	for_(i, 1, n)
	{
		pCMD=(CMD*)malloc(sizeof(CMD));
		scanf("%d %d", &x, &y);
		pCMD->id = x, pCMD->op = y;
		if(headCMD == NULL)
			headCMD = pCMD, qCMD = pCMD;
		else
			qCMD->next = pCMD, qCMD = pCMD;
	}
	if(qCMD != NULL) qCMD->next = NULL;

	
	//end of input


	pCMD = headCMD;
	while(233)
	{
		if(pCMD == NULL) break;
		switch(pCMD->op)
		{
		case 0:
			headA = deleteid(headA, pCMD->id);
			break;
		case 1:
			headA = newid(headA, pCMD->id);
			break;
		}
		pCMD = pCMD->next;
	}

	printlist(headA);
	return 0;
} 