#ifndef TREE_H
#define TREE_H

#include "stack_queue.h"
#include "list.h"
#define MaxSize 50
//������ 
typedef struct BiTNode {
	int data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *BiTree;
//����
typedef struct Node{
	BiTree p;
	struct Node *next;
}Node, *pNode;
//����������
typedef struct ThreadNode {
	int data;
	struct ThreadNode *lchild, *rchild;
	int ltag, rtag;						//���Һ���������־
}ThreadNode, *ThreadTree;
//˫�ױ�ʾ��
typedef struct {
	int data;
	int parent;
}PTNode;
typedef struct {
	PTNode nodes[50];	//˫�ױ�ʾ
	int n;				//�ڵ���
}PTree;
//�����ֵܱ�ʾ��
typedef struct CSNode{
	int data;
	struct CSNode *firstchild, *nextsibling;	//��һ�����Ӻ����ֵ�ָ��
}CSNode, *CSTree;


void BiTreeTest(void);

BiTree LevelCreateBiTree(int A[], int n);		//������
void PreCreateBiTree(BiTree &p);				//������
int FindCommAncestor(SqList T, int i, int j);	//Ѱ�ҹ�������
void SearchAncestor(BiTree T, int e);			//Ѱ�����Ƚ��
int FindCommAnsestor_2(BiTree T, int a, int b);//Ѱ�ҹ�������
int BiTreeDepth(BiTree T);					//����
void BiTreeDepthWidth(BiTree T);					//��������
BiTree PreInCreateBiTree(int A[], int B[], int a1, int a2, int b1, int b2); //��֪����������
void WPL(BiTree T);				//��Ȩ·������
int wplPreOrder(BiTree T, int depth);
int wplLevelOrder(BiTree T);

void BiTreeInfo(BiTree p);
void PreOrder(BiTree p);
void PreOrder(BiTree p);
void InOrder(BiTree p);
void InOrder_2(BiTree p);
void PostOrder(BiTree p);
void PostOrder_2(BiTree p);
void LevelOrder(BiTree p);
void LevelOrder_2(BiTree p);
void visit(BiTree p);

//�����ֵܱ�ʾ���������ṹ
void TreeTest(void);
int leaves(BiTree T);
int height(BiTree T);

//����������
void TreeTest_BST(void);
BiTree BST_Create(int A[], int n);
int BST_Insert(BiTree &T, int e);
int BST_Search(BiTree T, int e, BiTree &parent, BiTree &cur);
void BST_Delete(BiTree &T, int e);
int BST_Judge(BiTree T);

void AVL_Judge(BiTree T, int &balance, int &height);//�ж��Ƿ�Ϊƽ�������
int AVL_Nodes(int height);

#endif
