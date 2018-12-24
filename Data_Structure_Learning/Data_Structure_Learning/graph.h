#ifndef GRAPH_H
#define GRAPH_H
#define MaxSize 50
//�ڽӾ���
typedef struct {
	int vertex[MaxSize];		//�����Ȩֵ��
	int edge[MaxSize][MaxSize];	//�߱�
	int vertexNum, arcNum;	//������������
}MGraph; 

//�ڽӱ�
typedef struct ArcNode {		//�߱���
	int adjvex;					//�û�ָ��Ķ����λ��
	struct ArcNode *next;		//ָ����һ������ָ��
	//int info;					//Ȩֵ
}ArcNode;
typedef struct VNode {			//�������
	int data;					//��������
	ArcNode *first;				//ָ���һ�������ڸö���Ļ���ָ��
}VNode, AdjList[MaxSize];
typedef struct {
	AdjList vertices;			//�ڽӱ�
	int vertexNum, arcNum;		//������������
}ALGraph;

//ʮ������
typedef struct ArcNode_2 {					//�߱�
	int tailvex, headvex;					//����βͷ���
	struct ArcNode_2 *taillink, *headlink;	//ָ��β��ͬ����ͷ��ͬ�Ľ��
	//int info;									
}ArcNode_2;
typedef struct VNode_2 {				//�����
	int data;	
	ArcNode_2 *firstin, *firstout;		//��һ���뻡�ͳ���
}VNode_2;								
typedef struct {
	VNode_2 xlist[MaxSize];				//�ڽӱ�
	int vertexNum, arcNum;
}GLGraph;

//�ڽӶ��ر�
typedef struct ArcNode_3 {				//�߱�
	bool mark;							//���ʱ��
	int ivex, jvex;						//�û����������
	struct ArcNode_3 *ilink, *jlink;	//�����������һ����
	//int info							
}ArcNode_3;
typedef struct VNode_3 {				//�����
	int data;							
	ArcNode_3 *firstedge;				//��һ�������ö���ı�
}VNode_3;
typedef struct {
	VNode_3 adjmulist[MaxSize];
	int vertexNum, arcNum;		
}AMLGraph;

void GraphTest(void);
MGraph *CreateMGraph(void);
MGraph *CreateMGraph_2(int n);
void DisplayMGraph(MGraph *p);
ALGraph *CreateALGraph(void);
ALGraph *CreateALGraph_2(void);		
void DisplayALGraph(ALGraph *p);



int FirstNeighbor(ALGraph *p, int v);
int NextNeighbor(ALGraph *p, int v, int n);
void BFSTraverse(ALGraph *G);
void BFS(ALGraph *G, int v);
void DFSTraverse(ALGraph *G);
void DFS(ALGraph *G, int v);
void visit(ALGraph *G, int v);

void BFSTraverse_2(ALGraph *G, int source);
void DFSTraverse_2(ALGraph *G, int source);
void DFSTraverse2(ALGraph *G, int source);

void BFS_Min_Distance(ALGraph *G, int v);

void Prim(MGraph *G);
void Dijkstra(MGraph *G, int v);
void Floyd(MGraph *G);
#endif // !GRAPH_H

