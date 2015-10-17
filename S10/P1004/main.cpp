/*
�����⣺�û�����25 �֣�
��дһ���������ȸ����û���������Ϣ����һ������ LA��ÿ��������
������Ϊѧ����ѧ�ţ����������������֮�䰴ѧ���������С�Ȼ���ٸ����û�
��������Ϣ������һ������ LB��ÿ�����������ѧ����ѧ�� S ��һ�������
O��O ��ֵΪ�����ӡ���ɾ�����������������򽫶� LB ��ÿ�������з�����
��� O ��ֵΪ�����ӡ����������� LA ������һ����㣬��ѧ�ż�Ϊ S����� O
��ֵΪ��ɾ�������������� LA �У��ҵ�ѧ��Ϊ S �Ľ�㲢����ɾ�������Ҳ���
ѧ��Ϊ S �Ľ�㣬���账�����ھ������������Ҫ�� LA �еĽ����Ȼ��
ѧ���������С�
˵����
a)  �ڴ�������ʱ��Ϊ�˼����ڴ�ռ���˷ѣ�������ö�̬����ķ�����
��ÿһ�������㶼�Ǹ�����Ҫ��̬�����ģ�
b)  Ϊ����ǿ����Ŀɶ��ԣ�Ӧ���öຯ������ʽ��ʵ�֣�����Ӧ��������
�ĺ����������������ӽڵ㡢ɾ���ڵ㡢��ӡ����ȡ�
�����ʽ����һ����һ������ M����ʾ���� LA �Ľ��������������� M �У�
ÿһ����һ������ si����ʾ�� i ������ѧ�ţ����մ�С�������򣩡���������һ
����һ������ N����ʾ���� LB �Ľ��������ٽ������� N �У�ÿһ����������
�� si �� oi�����У� si ��ʾ�� i ������ѧ�ţ����մ�С�������򣩣� oi ��ʾ�������
oi  Ϊ 1 ��ʾ�����ӡ���㣬oi Ϊ 0 ��ʾ��ɾ������㡣
�����ʽ��������������Ժ������ LA �����ݡ������������ K ����㣬
������� K �У�ÿһ����һ������������Ӧ��ѧ�š�
�������룺
4
1001
1003
1005
1007
2
1002 1
1007 0
���������
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