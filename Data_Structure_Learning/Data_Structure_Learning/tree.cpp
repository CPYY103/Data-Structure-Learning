#include<stdio.h>
#include<stdlib.h>
#include "tree.h"

void BiTreeTest(void)
{
	int A[] = { 0,1,2,3,4,5,6,7,8,9 };  //��0�����ݲ�������������
	int B[] = { 0,4,3,5,2,6,1,8,9,7 };
	BiTree T = LevelCreateBiTree(A+1, sizeof(A) / sizeof(A[0])-1); //��0�����ݲ�������������
	BiTreeInfo(T);
	//BiTree T1 = PreInCreateBiTree(A, B, 1, 9, 1, 9);
	//BiTreeInfo(T1);
	//SearchAncestor(T1, 9);
	//printf("%d %d 's CommAncestor: %d\n", 4, 6, FindCommAnsestor_2(T1, 4, 6));

	/*BiTree T3;
	PreCreateBiTree(T3);
	PreOrder(T3);*/

	//TreeTest();
	//TreeTest_BST();
}
//����������������ȫ������
BiTree LevelCreateBiTree(int A[], int n)
{
	if (n == 0)
		return NULL;

	BiTree tree = NULL, pnew;
	pNode phead = NULL, ptail = NULL, listpnew = NULL, pcur = NULL;

	for (int i = 0; i < n; i++)
	{
		pnew = (BiTree)calloc(1, sizeof(BiTNode));
		pnew->data = A[i];
		listpnew = (pNode)calloc(1, sizeof(Node));
		listpnew->p = pnew;
		if (i == 0) //��ʼ��
		{
			tree = pnew;//����
			phead = listpnew;
			ptail = listpnew;
			pcur = listpnew;
			continue;
		}
		else
		{
			ptail->next = listpnew;  //���½���������
			ptail = listpnew;
		}
		//�������������
		if (pcur->p->lchild == NULL)
		{
			pcur->p->lchild = pnew;
		}
		else if (pcur->p->rchild == NULL)
		{
			pcur->p->rchild = pnew;
			pcur = pcur->next;
		}
	}

	return tree;
}
//������������
void PreCreateBiTree(BiTree &p)
{
	int elem;
	scanf("%d", &elem);
	if (elem == 0)  //��Ϊ0����ʾ�޶�Ӧ����
		p = NULL;
	else
	{
		p = (BiTree)malloc(sizeof(BiTNode));
		p->data = elem;
		printf("Input %d -> lchild:\n", elem);
		PreCreateBiTree(p->lchild);
		printf("Input %d -> rchild:\n", elem);
		PreCreateBiTree(p->rchild);
	}
	
}
//��������˳���洢ʱѰ��i,j��������
int FindCommAncestor(SqList T, int i, int j)
{
	if(T.data[i]&&T.data[j])
		while (i != j)
		{
			if (i > j)
				i /= 2;
			else
				j /= 2;
		}
	return T.data[i];
}
//����
void PreOrder(BiTree p)
{
	if (p)
	{
		visit(p);
		PreOrder(p->lchild);
		PreOrder(p->rchild);
	}
}
//����ǵݹ�
void PreOrder_2(BiTree T)
{
	BiTree S[MaxSize], p = T;
	int top = -1;
	while (p || top != -1)
	{
		if (p)
		{
			visit(p);
			S[++top] = p;
			p = p->lchild;
		}
		else
		{
			p = S[top--];
			p = p->rchild;
		}
	}
}
//����
void InOrder(BiTree p)
{
	if (p)
	{		
		InOrder(p->lchild);
		visit(p);
		InOrder(p->rchild);
	}
}
//����ǵݹ�
void InOrder_2(BiTree T)
{
	BiTree S[MaxSize], p = T; //����ջ
	int top = -1;
	while (p || top != -1)
	{
		if (p)     //�������������ǿ����ջ
		{
			S[++top] = p;		
			p = p->lchild;
		}
		else     //��������Ϊ�գ���ջ�����ʣ��ٱ���������
		{
			p = S[top--];	
			visit(p);
			p = p->rchild;
		}
	}
}
//����
void PostOrder(BiTree p)
{
	if (p)
	{
		PostOrder(p->lchild);
		PostOrder(p->rchild);
		visit(p);
	}
}
//����ǵݹ�
void PostOrder_2(BiTree T)
{
	BiTree S[MaxSize], p = T, r = NULL;  //r������¼
	int top = -1;
	while (p || top != -1)
	{
		if (p)             //�����
		{
			S[++top] = p;
			p = p->lchild;
		}
		else
		{
			p = S[top];				//ȡջ��
			if (p->rchild&&p->rchild != r)//���������������δ�����ʹ�
			{
				p = p->rchild;
				S[++top] = p;			
				p = p->lchild;
			}
			else
			{
				p = S[top--];         
				visit(p);
				r = p;				//��¼������ʵĽ��
				p = NULL;           //����p
			}
		}
	}

}
//����
void LevelOrder(BiTree p)
{
	BiTree Q[MaxSize], temp;
	int front = -1, rear = -1;
	Q[++rear] = p;
	while (front < rear)
	{
		temp = Q[++front];
		visit(temp);
		if (temp->lchild)
			Q[++rear] = temp->lchild;
		if (temp->rchild)
			Q[++rear] = temp->rchild;
	}
}
//���򣬴������ϣ���������
void LevelOrder_2(BiTree p)
{
	BiTree Q[MaxSize], S[MaxSize], temp;
	int front = -1, rear = -1, top = -1;
	Q[++rear] = p;
	while (front < rear)
	{
		temp = Q[++front];
		S[++top] = temp;
		if (temp->lchild)
			Q[++rear] = temp->lchild;
		if (temp->rchild)
			Q[++rear] = temp->rchild;
	}
	for (; top >= 0; top--)
		visit(S[top]);
}
//���ʽ��
void visit(BiTree p)
{
	printf("%d ", p->data);
}
//�����Ϣ
void BiTreeInfo(BiTree p)
{
	printf("PreOrder:\n");
	PreOrder(p);
	printf("\nInOrder:\n");
	InOrder(p);
	printf("\nPostOrder:\n");
	PostOrder(p);
	printf("\nLevelOrder:\n");
	LevelOrder(p);
	printf("\n");
	BiTreeDepthWidth(p);
	WPL(p);
	printf("-------------------\n");
}
//��������ȣ��߶ȣ����ݹ�
int BiTreeDepth(BiTree T)
{
	if (!T)
		return 0;
	int ldeep = BiTreeDepth(T->lchild);
	int rdeep = BiTreeDepth(T->rchild);

	return ldeep > rdeep ? ldeep + 1 : rdeep + 1;
}
//��������ȣ��߶ȣ�,����ȣ��ǵݹ飬����
void BiTreeDepthWidth(BiTree T)
{
	if (!T)
		return ;
	BiTree Q[MaxSize], p;
	int front = -1, rear = -1;
	int last = 0, level = 0, width = 0;	//lastָ����һ���һ�����λ��
	Q[++rear] = T;				//��������
	while (front < rear)
	{
		p = Q[++front];			//����
		if (p->lchild)
			Q[++rear] = p->lchild;
		if (p->rchild)
			Q[++rear] = p->rchild;
		if (front == last)		//�Ѿ����ò����ҽ��
		{
			level++;			//������1
			last = rear;		//lastָ���²�
			if (width < last - front)
				width = last - front;
		}
	}
	printf("Depth: %d\nWidth: %d\n", level, width);
}
//��֪����������
//A����a1Ϊ��һ���±꣬��1��ʼ��a2Ϊ���һ������±�
//B����b1Ϊ��һ���±꣬��1��ʼ��b2Ϊ���һ������±�
BiTree PreInCreateBiTree(int A[], int B[], int a1, int a2, int b1, int b2)
{
	int i, llen, rlen;
	BiTree root = (BiTree)malloc(sizeof(BiTNode));
	root->data = A[a1];            //�����
	for (i = b1; B[i] != root->data; i++); //��������Ѱ�Ҹ�����±�
	llen = i - b1;		//����������
	rlen = b2 - i;		//����������

	if (llen)			//�ݹ齨��������
		root->lchild = PreInCreateBiTree(A, B, a1 + 1, a1 + llen, b1, b1 + llen - 1);
	else
		root->lchild = NULL;	//������Ϊ��

	if (rlen)
		root->rchild = PreInCreateBiTree(A, B, a2 - rlen + 1, a2, b2 - rlen + 1, b2);
	else
		root->rchild = NULL;

	return root;

}
//Ѱ�����Ƚ�㣬�������
void SearchAncestor(BiTree T, int e)
{
	BiTree S[MaxSize], p = T, r = NULL;  //r������¼
	int top = -1;
	while (p || top != -1)
	{
		if (p)             //�����
		{
			S[++top] = p;
			p = p->lchild;
		}
		else
		{
			p = S[top];						//ȡջ��
			if (p->rchild&&p->rchild != r)	//���������������δ�����ʹ�
			{
				p = p->rchild;
				S[++top] = p;			
				p = p->lchild;
			}
			else
			{
				p = S[top--];					
				
				if (p->data == e)		//ջ������ȫΪ���Ƚ��
				{
					printf("%d 's Ancestor: ", e);
					for (int j = 0; j <= top; j++)
					{
						printf("%d ", S[j]->data);
					}
					printf("\n");
					return;
				}

				r = p;				//��¼������ʵĽ��
				p = NULL;           //����p
			}
		}
	}
}
//Ѱ�ҹ������ȣ���a��b���
int FindCommAnsestor_2(BiTree T, int a, int b)
{
	BiTree S[MaxSize], p = T, r = NULL; 
	int top = -1, j = 0;
	int A[20], B[20];
	while (p || top != -1)
	{
		if (p)        
		{
			S[++top] = p;
			p = p->lchild;
		}
		else
		{
			p = S[top];
			if (p->rchild&&p->rchild != r)	
			{
				p = p->rchild;
				S[++top] = p;
				p = p->lchild;
			}
			else
			{
				p = S[top--];

				if (p->data == a)
					for (j = 0; j <= top; j++)
						A[j] = S[j]->data;      //��ջ�����ݱ��浽����
				if (p->data == b)
				{
					for (j = 0; j <= top; j++)
						B[j] = S[j]->data;
					for (j = 0; j <= top; j++)
					{
						if (A[j] != B[j])		//���ݽ��бȽϣ���ǰ���ݲ�һ��ʱ����һ�����ݼ�Ϊ�����������
							return A[j - 1];
					}
					return A[j - 1];			//һ��������������һ������������ͬ���򲿷���ͬ��
				}
					
				r = p;			
				p = NULL;       
			}
		}
	}
}
//WPL��Ȩ·�����ȣ�����Ҷ����Ȩ·������֮��
void WPL(BiTree T)
{
	printf("WPL: %d\n", wplPreOrder(T, 1));
	printf("WPL: %d\n", wplLevelOrder(T));
}
int wplPreOrder(BiTree T, int depth)
{
	static int wpl = 0;                //wpl��̬���ڲ��Գ����У��ڶ�������������ĵó�WPLֵ����ʵ�ʵ�WPLֵ���ϵ�һ������WPLֵ
	if (T->lchild == NULL&&T->rchild == NULL)
		wpl += depth*T->data;

	if (T->lchild != NULL)
		wplPreOrder(T->lchild, depth + 1);
	if (T->rchild != NULL)
		wplPreOrder(T->rchild, depth + 1);

	return wpl;
}
int wplLevelOrder(BiTree T)
{
	if (!T)
		return 0;
	BiTree Q[MaxSize], p;
	int front = -1, rear = -1;
	int last = 0, level = 1, wpl = 0;	// ������1��ʼ�������������ʵ�ʲ���Ϊlevel��ֵ��1
	Q[++rear] = T;				
	while (front < rear)
	{
		p = Q[++front];			
		if (p->lchild == NULL&&p->rchild == NULL)
			wpl += level*p->data;
		if (p->lchild)
			Q[++rear] = p->lchild;
		if (p->rchild)
			Q[++rear] = p->rchild;
		if (front == last)		//�Ѿ����ò����ҽ��
		{
			level++;			//������1
			last = rear;		//lastָ���²�
		}
	}
	return wpl;
}
//�����ֵܱ�ʾ��
//���ݽṹΪ��������lchildΪ��һ�����ӣ�rchildΪ�ֵܽ��
void TreeTest()
{
	BiTree T;
	printf("Input:\n");
	PreCreateBiTree(T);   //1 2 4 0 0 5 0 0 3 6 0 0 7 0 0
	printf("PreOrder:\n");
	PreOrder(T);
	printf("\nleaves: %d\n", leaves(T));
	printf("height: %d\n", height(T));
}
//�ɶ�������������Ҷ����
int leaves(BiTree T)
{
	if (T == NULL)
		return 0;
	if (T->lchild == NULL)	//�������������޺��ӣ�ΪҶ���
		return leaves(T->rchild) + 1;
	else					//���غ�������Ҷ�������ֵ�����Ҷ����֮��
		return leaves(T->lchild) + leaves(T->rchild);
}
//�ɶ�����������������
int height(BiTree T)
{
	int h1, h2; 
	if (T == NULL)
		return 0;
	else	 //ȡ��Ů�߶�+1���ֵܸ߶��еĴ���
	{
		h1 = height(T->lchild);
		h2 = height(T->rchild);
		return h1 + 1 > h2 ? h1 + 1 : h2;
	}
}
//����������
int BST_Insert(BiTree &T, int e)
{
	if (T == NULL)
	{
		T = (BiTree)malloc(sizeof(BiTNode));
		T->data = e;
		T->lchild = NULL;
		T->rchild = NULL;
		return 1;
	}
	else if (T->data == e)		//����������ͬԪ�أ�����ʧ��
		return 0;
	else if (T->data > e) 
		return BST_Insert(T->lchild, e);
	else
		return BST_Insert(T->rchild, e);
}
BiTree BST_Create(int A[], int n)
{
	BiTree T = NULL;
	for (int i = 0; i < n; i++)
		BST_Insert(T, A[i]);
		
	return T;
}
int BST_Search(BiTree T, int e, BiTree &parent, BiTree &cur)
{
	int flag = -1;  //��flag=1,��Ϊ��˫�׵��Һ���   flag=0������   flag=-1,û�ҵ�   flag=2,Ϊ�����
	cur = T;
	if (cur->data == e)
		flag = 2;
	else
		while (cur&&cur->data != e)
		{
			parent = cur;
			if (cur->data > e)
			{
				cur = cur->lchild;
				flag = 0;
			}
			else
			{
				cur = cur->rchild;
				flag = 1;
			}
		}
	
	if (!cur)
		flag = -1;
	return flag;
}
void BST_Delete(BiTree &T, int e) //����ɾ�����ڵ�ʱ
{
	BiTree parent = NULL, cur = NULL;
	int flag = BST_Search(T, e, parent, cur);
	if (flag != -1)//���ڸý��
	{
		printf("Search: %d, Parent: %d, flag: %d\n", cur->data, parent->data, flag);
		if (!cur->lchild && !cur->rchild) //ΪҶ���
		{
			if (flag)		//Ϊ�Һ�
				parent->rchild = NULL;
			else
				parent->lchild = NULL;

		}
		else if (cur->lchild && !cur->rchild) //�������գ�����Ů�
		{
			if (flag)
				parent->rchild = cur->lchild;
			else
				parent->lchild = cur->lchild;
		}
		else if (cur->rchild && !cur->lchild)	//�������գ��������
		{
			if (flag)
				parent->rchild = cur->rchild;
			else
				parent->lchild = cur->rchild;
		}
		else //�������������գ������������������һ����Ů�
		{
			BiTree p = cur->rchild, q = cur;
			while (p->lchild)
			{
				q = p;
				p = p->lchild;
			}
			cur->data = p->data;
			if (p->rchild)
				q->lchild = p->rchild;
			else
				q->rchild = NULL;
				
		}

	}

}
//����������������ж��Ƿ�Ϊ����������
int BST_Judge(BiTree T)
{
	if (!T)
		return 1;
	static int pre_data = -32767;
	int left, right;	

	left = BST_Judge(T->lchild);    //�ж�������
	if (left == 0 || pre_data > T->data)
		return 0;
	pre_data = T->data;
	right = BST_Judge(T->rchild);
	return right;
}
//�ж��Ƿ�Ϊƽ�������
//����ƽ����balance,��Ϊƽ�������������1�����򷵻�0
//heightΪ�������߶ȣ����ĸ߶�Ϊ��������ĸ߶�+1
//����
void AVL_Judge(BiTree T, int &balance, int &height)
{
	int balanceLeft = 0, balanceRight = 0, heighLeft = 0, heighRight = 0;
	if (!T)
	{
		height = 0;
		balance = 1;
	}
	else if (!T->lchild && !T->rchild)//���и��ڵ�
	{
		height = 1;
		balance = 1;
	}
	else
	{
		AVL_Judge(T->lchild, balanceLeft, heighLeft);
		AVL_Judge(T->rchild, balanceRight, heighRight);
		height = heighLeft > heighRight ? heighLeft : heighRight + 1;
		if (abs(heighLeft - heighRight) < 2)
			balance = balanceLeft && balanceRight;
		else
			balance = 0;
	}
}
void TreeTest_BST(void)
{
	int A[] = { 4,7,5,8,6,2,3,1,9 };

	BiTree T = BST_Create(A, sizeof(A) / sizeof(A[0]));
	printf("InOrder:\n");
	InOrder(T);
	printf("\n");
	if (BST_Judge(T))
		printf("BST Judge Success\n");
	else
		printf("BST Judge Fail\n");

	int balance = 0, height=0;
	AVL_Judge(T, balance, height);
	if (balance)
		printf("AVL Judge Success\n");
	else
		printf("AVL Judge Fail\n");
	
	BiTree parent = NULL, cur = NULL;
	int flag = BST_Search(T, 5, parent, cur);
	if (flag != -1)
		printf("Search: %d, Parent: %d, flag: %d\n", cur->data, parent->data, flag);
	else
		printf("Not Found \n");

	BST_Delete(T, 7);
	printf("InOrder:\n");
	InOrder(T);
	printf("\n");
}
//����Ϊheight��AVL�������ٽ����
int AVL_Nodes(int height)
{
	if (height == 0)
		return 0;
	else if (height == 1)
		return 1;
	else if (height == 2)
		return 2;

	return AVL_Nodes(height - 1) + AVL_Nodes(height - 2) + 1;
}