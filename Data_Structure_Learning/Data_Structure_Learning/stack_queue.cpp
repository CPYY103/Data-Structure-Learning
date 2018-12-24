#include<stdio.h>
#include "stack_queue.h"
#include<stdlib.h>


//��������Ƿ���� 
void CheckBracket()
{

	char *s = "({}{[]})";
	puts(s);
	if (Check(s))
		printf("������Գɹ�\n");
	else
		printf("�������ʧ��\n");

	printf("--------------------\n");
}
bool Check(char *s)
{
	SqStack S;
	InitStack(S);
	int e;      //���ڶ����Push,Pop�����е�Ԫ����int����ʹ��char�ᱨ���൱���ڲ�ASCIIת���� 
	for (int i = 0; s[i] != '\0'; i++)
		switch (s[i])
		{
		case '(':
			Push(S, '(');
			break;
		case '{':
			Push(S, '{');
			break;
		case '[':
			Push(S, '[');
			break;
		case ')':
			Pop(S, e);
			if (e != '(')
				return false;
			break;
		case ']':
			Pop(S, e);
			if (e != '[')
				return false;
			break;
		case '}':
			Pop(S, e);
			if (e != '{')
				return false;
			break;
		}
	if (!isStackEmpty(S))
		return false;
	return true;

}

//����һ�����к�һ����ջ��Ԫ������ 
void Reverse_StackQueue()
{
	//������ʼ�� 
	int e, i;
	SqQueue Q;
	SqStack S;
	InitStack(S);
	InitQueue(Q);
	printf("InitQueue :\n");
	for (i = 1; i<10; i++) {
		EnQueue(Q, i);
		printf("%d ", i);
	}
	printf("\n");

	while (!isQueueEmpty(Q))
	{
		DeQueue(Q, e);
		Push(S, e);
	}
	printf("Reversed Queue:\n");
	while (!isStackEmpty(S))
	{
		Pop(S, e);
		EnQueue(Q, e);
		printf("%d ", e);
	}
	printf("\n");

	printf("--------------------\n");
}

void StackQueueTest()
{
	StackTest();
	QueueTest();
	Reverse_StackQueue();
	CheckBracket();
}
void StackTest()
{
	int i, e;
	SqStack S;
	InitStack(S);
	printf("StackTest\n");
	if (isStackEmpty(S))
		printf("The Stack is Empty !\n");

	printf("InitStack :\n");
	for (i = 1; i<10; i++) {
		Push(S, i);
		printf("%d ", i);
	}
	printf("\n");

	Pop(S, e);
	printf("pop element: %d \n", e);
	GetTop(S, e);
	printf("get top element: %d \n", e);

	printf("--------------------\n");
}

void QueueTest()
{
	SqQueue Q;
	int e, i;
	InitQueue(Q);
	printf("QueueTest\n");
	if (isQueueEmpty(Q))
		printf("The Queue is Empty !\n");
	printf("InitQueue :\n");
	for (i = 1; i<10; i++) {
		EnQueue(Q, i);
		printf("%d ", i);
	}
	printf("\n");

	DeQueue(Q, e);
	printf("DeQueue element: %d \n", e);
	DeQueue(Q, e);
	printf("DeQueue element: %d \n", e);

	printf("--------------------\n");
}



void InitStack(SqStack &S)
{
	S.top = -1;
}

bool isStackEmpty(SqStack &S)
{
	if (S.top == -1)
		return true;
	else
		return false;
}

bool Push(SqStack &S, int e)
{
	if (S.top == MaxSize - 1)  //ջ�� 
		return false;
	S.data[++S.top] = e;
	return true;
}

bool Pop(SqStack &S, int &e)
{
	if (S.top == -1)   //ջ�� 
		return false;
	e = S.data[S.top--];
	return true;
}

bool GetTop(SqStack &S, int &e)
{
	if (S.top == -1)   //ջ�� 
		return false;
	e = S.data[S.top];
	return true;
}


void InitQueue(SqQueue &Q)
{
	Q.front = Q.rear = 0;
}

bool isQueueEmpty(SqQueue Q)
{
	if (Q.front == Q.rear)
		return true;
	else
		return false;
}

bool EnQueue(SqQueue &Q, int e)
{
	if ((Q.rear + 1) % MaxSize == Q.front) //����
		return false;
	Q.data[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MaxSize; //��βָ���1ȡģ 
	return true;
}

bool DeQueue(SqQueue &Q, int &e)
{
	if (Q.rear == Q.front) //�ӿ� 
		return false;
	e = Q.data[Q.front];
	Q.front = (Q.front + 1) % MaxSize;
	return true;
}
