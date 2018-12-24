#ifndef STACKQUEUE_H
#define STACKQUEUE_H
#define MaxSize 50
//ջ 
typedef struct {
	int data[MaxSize];
	int top;   //ջ��ָ�� 
}SqStack;
//���� 
typedef struct {
	int data[MaxSize];
	int front, rear;
}SqQueue;



void InitStack(SqStack &S);
bool isStackEmpty(SqStack &S);
bool Push(SqStack &S, int e);
bool Pop(SqStack &S, int &e);
bool GetTop(SqStack &s, int &e);
void StackTest(void);

//ѭ������ 
void InitQueue(SqQueue &Q);
bool isQueueEmpty(SqQueue Q);
bool EnQueue(SqQueue &Q, int e);
bool DeQueue(SqQueue &Q, int &e);
void QueueTest(void);

void StackQueueTest(void);


void Reverse_StackQueue(void);
void CheckBracket(void);
bool Check(char *s);

#endif
