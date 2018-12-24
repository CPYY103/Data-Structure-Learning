#include<stdio.h>
#include<stdlib.h>
#include "list.h"

//˳���������� 
void ListTest()
{
	printf("ListTest\n");
	SqList L;
	int i;
	L.length = 0;
	for (i = 0; i<9; i++)
	{
		L.data[i] = i + 1;
		L.length++;
	}
	printf_list(L);
	if (ListInsert(L, 5, 9))
		printf_list(L);
	if (ListDelete(L, 5))
		printf_list(L);
	printf("locate 4: %d \n", LocateElem(L, 4));

	printf("------------------\n");
	Reverse_1();
}

//�������
void LinkListTest()
{
	printf("LinkListTest\n");
	LinkList L1;
	CreateList_Head(L1);
	printf_linklist(L1);
	printf("GetElem_i_4: %d \n", GetElem_i(L1, 4)->data);
	printf("Reverse printf:\n");
	R_printf(L1->next);
	printf("\n");
	printf("Reverse_2 printf:\n");
	printf_linklist(Reverse_2(L1));
	printf("\n");

	LinkList L2;
	CreateList_Tail(L2);
	printf_linklist(L2);
	printf("GetElem_e_4: %d \n", GetElem_e(L2, 4)->data);

	LNode *s = (LNode*)malloc(sizeof(LNode));
	s->data = 3;
	printf("insert a elem:\n");
	printf_linklist(L1);
	printf("delete a elem:\n");
	LinkListDelete(L1, 3);
	printf_linklist(L1);

	printf("kth_from_end : %d\n", Search_Kth(L1, 3)->data);

	printf("-------------------\n");

	FindMajority();
}

//��ӡ���� 
void printf_arr(int A[], int n)
{
	for (int i = 0; i<n; i++)
		printf("%d ", A[i]);
	printf("\n");
}
//��ӡ˳��� 
void printf_list(SqList &L)
{
	for (int i = 0; i<L.length; i++)
		printf("%d ", L.data[i]);
	printf("\n");
}
//��ӡ����
void printf_linklist(LinkList L)
{
	printf("printf_linklist:\n");
	L = L->next;
	while (L)
	{
		printf("%d ", L->data);
		L = L->next;
	}
	printf("\n");
}
//��iλ�ò���Ԫ��e 
bool ListInsert(SqList &L, int i, int e)
{
	int j;
	if (i<1 || i>L.length) //i��Ч��Χ 
		return false;
	if (L.length >= MaxSize)  //����ռ��Ƿ����� 
		return false;
	for (j = L.length; j >= i; j--)
		L.data[j] = L.data[j - 1];
	L.data[j] = e;
	L.length++;
	return true;
}

//ɾ����i���� 
bool ListDelete(SqList &L, int i)
{
	if (i<1 || i>L.length) //i��Ч��Χ 
		return false;

	for (int j = i; j<L.length; j++)
		L.data[j - 1] = L.data[j];
	L.length--;
	return true;
}

//����e��λ�� 
int LocateElem(SqList L, int e)
{
	for (int i = 0; i<L.length; i++)
		if (L.data[i] == e)
			return i + 1;
	return 0;
}



//ͷ�彨������ 
LinkList CreateList_Head(LinkList &L)
{
	LNode *s;
	int x = 1;
	L = (LinkList)malloc(sizeof(LNode)); //��ͷ�������� 
	L->next = NULL;
	while (x<10)
	{
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x++;
		s->next = L->next;
		L->next = s;
	}
	return L;
}

//β�巨�������� 
LinkList CreateList_Tail(LinkList &L)
{
	L = (LinkList)malloc(sizeof(LNode));
	LNode *s, *r = L; //rΪ��βָ�� 
	int x = 1;
	while (x<10)
	{
		s = (LNode*)malloc(sizeof(LNode));
		s->data = x++;
		r->next = s;
		r = s;
	}
	r->next = NULL;
	return L;
}


//����Ų��� 
LNode *GetElem_i(LinkList L, int i)
{
	LNode *p = L;
	if (i == 0)
		return L;  //����ͷ���
	if (i<0)
		return NULL; //��Ч
	while (p&&i--)
	{
		//printf("%d ", p->data); 
		p = p->next;

	}

	return i<0 ? p : NULL;
}
//��Ԫ�ز��� 
LNode *GetElem_e(LinkList L, int e)
{
	LNode *p = L;
	while (p&&p->data != e)
		p = p->next;
	return p;
}
//��i��λ�ò�����
void LinkListInsert(LinkList L, LNode *s, int i)
{
	LNode *p = GetElem_i(L, i - 1);
	s->next = p->next;
	p->next = s;
}
//��i��λ��ɾ�����
void LinkListDelete(LinkList L, int i)
{
	LNode *p = GetElem_i(L, i - 1);
	LNode *q;
	q = p->next;
	p->next = q->next;
	free(q);
}



//��һά����A[n]����A������ѭ������p��λ��
//��(X0,X1,...,Xn-1)��ΪXp,Xp+1,..,Xn-1,X0,X1..Xp-1
//�������ab��Ϊba���Ƚ�a���ã���a��b���ٽ�b���õ�a��b��
//��a��b�����õ�ba   
void Reverse(int A[], int from, int to)
{
	int i, temp;
	for (i = 0; i<(to - from + 1) / 2; i++)
	{
		temp = A[from + i];
		A[from + i] = A[to - i];
		A[to - i] = temp;
	}
}
void Reverse_1(void)
{
	int A[] = { 1,2,3,4,5,6,7,8,9 };
	int p = 5, n = sizeof(A) / sizeof(A[0]);

	Reverse(A, 0, p - 1);
	Reverse(A, p, n - 1);
	Reverse(A, 0, n - 1);
	printf_arr(A, n);

	printf("--------------------\n");

}


//��֪����A[n],��������ͬ��Ԫ��x�������Ϊm����m>n/2����xΪ��Ԫ��
//��A={0,5,5,3,5,7,5,5}����5Ϊ��Ԫ��
//��A={0,5,5,3,5,7,5,0}����û����Ԫ��
void FindMajority(void)
{
	int A[] = { 1,2,3,5,3,7,3,3,3 };
	printf("majority: %d\n", Search(A, sizeof(A) / sizeof(A[0])));

	printf("--------------------\n");
}

int Search(int A[], int n)
{
	int i, count = 1, temp; //temp�����������Ԫ��
	temp = A[0];
	for (i = 1; i<n; i++)
		if (A[i] == temp)
			count++;
		else
			if (count>0)
				count--;
			else
			{
				temp = A[i];
				count = 1;
			}
	if (count>0)
		for (i = count = 0; i<n; i++)
			if (A[i] == temp)
				count++;
	if (count>n / 2)      //ȷ����Ԫ�� 
		return temp;
	else
		return -1;
}

//���������е�����kλ���ϵĽ��
LNode *Search_Kth(LinkList L, int k)
{
	LNode *p = L, *q = L;
	while (k--)
		p = p->next;
	while (p)
	{
		p = p->next;
		q = q->next;
	}
	return q;
}

//��������������׺
int LinkListLen(LinkList L)
{
	int len = 0;
	LNode *p = L;
	while (p)
	{
		len++;
		p = p->next;
	}
	return len;
}
LNode *FindCommonAddr(LinkList L1, LinkList L2)
{
	int m = LinkListLen(L1), n = LinkListLen(L2);
	LNode *p, *q;
	for (p = L1; m>n; m--) //��m>n,pָ��m-n+1����� 
		p = p->next;
	for (q = L2; m<n; n--)
		q = q->next;
	while (p->next && q->next!=p->next)
	{
		p = p->next;
		q = q->next;
	}
	return p->next;

}
//�����������
void R_printf(LinkList L)
{
	if (L->next)
		R_printf(L->next);
	printf("%d ", L->data);
}
//������͵�����
LinkList Reverse_2(LinkList &L)
{
	LNode *p, *r;
	p = L->next;
	L->next = NULL;  //��ͷ���ժ��
	while (p)
	{
		r = p->next;     //ͷ��
		p->next = L->next;
		L->next = p;
		p = r;
	}
	return L;
}
