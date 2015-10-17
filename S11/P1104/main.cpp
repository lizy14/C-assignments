/*
第四题： 循环链表（25 分） 
学校给高一（三）班分配了一个名额，去参加奥运会的开幕式。每个人都争
着要去，可是名额只有一个，怎么办？班长想出了一个办法，让班上的所有同学
围成一圈，按顺时针方向进行编号。然后随便选定一个数 m，并且从 1 号同学开
始按照顺时针方向依次报数， 1,2，…， m，凡报到 m 的同学，都要主动退出圈
子。然后继续按顺时针方向逐一让报出 m 者出圈，最后剩下的那个人就是去参
加开幕式的人。
要求：用循环链表的方法来求解。所谓循环链表，即对于链表尾节点，其 next
指针又指向了链表的首节点。基本思路是先创建一个环形链表，模拟众同学围成
一圈的情形。然后进入循环淘汰环节，模拟从 1 到 m 报数，每次让一位同学（节
点）退出圈子。
输入格式：输入只有 1 行，包括 2 个整数，分别表示人数 n 和随机选择的数
m，以空格分隔（ 0<n<1000,0< m<1000）。
输出格式： 输出只有一个整数， 即最后剩下人的初始编号。
样例输入：
5 3
样例输出：
4
*/
#include <stdlib.h>
#include <stdio.h>
struct node
{
	int id;
	node *next;
};
int main()
{
	int n, m, i;
	node *head, *tail, *p, *q;
	scanf("%d %d", &n, &m);
	
	head = p = q = NULL;
	for(i=1; i<=n; i++)
	{
		p=(node*)malloc(sizeof(node));
		p->id=i;
		if(head == NULL)
			head = p, q = p;
		else
			q->next = p, q = p;
	}
	if(q!=NULL) tail = q, q->next = head;
	//环形链表创建完成
	
	int c=1;
	node *cp=head, *pp=tail;
	while(head != head->next)
	{
		if(c == m)
		{
			if(cp==head)head=head->next;
			//printf("%d", cp->id);
			pp->next=cp->next;
			free(cp);
			cp=pp->next;
			c=0;
		}
		else
		{
			pp=pp->next, cp=cp->next;
		}
		c++;
		
	}
	printf("%d", head->id);
	return 0;
}