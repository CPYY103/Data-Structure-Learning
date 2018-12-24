#include<stdio.h>
#include<stdlib.h>
#include "graph.h"
bool Visited[MaxSize];		//���ڱ������ʱ������
int Queue[MaxSize], Front, Rear; //���ڱ���������

void GraphTest()
{
	//MGraph *G1 = CreateMGraph();
	//DisplayMGraph(G1);
	ALGraph *G2 = CreateALGraph_2();
	DisplayALGraph(G2);
	BFSTraverse(G2);
	DFSTraverse(G2);
	BFSTraverse_2(G2, 0);
	DFSTraverse_2(G2, 0);

	BFS_Min_Distance(G2, 0);

	MGraph *G3 = CreateMGraph_2(1);
	DisplayMGraph(G3);
	Prim(G3);
	Dijkstra(G3, 4);
	Floyd(G3);

}

MGraph *CreateMGraph()
{
	int i, j;
	MGraph *p = (MGraph*)malloc(sizeof(MGraph));
	printf("Input vertexNum\n");
	scanf("%d", &p->vertexNum);
	for (i = 0; i < p->vertexNum; i++)	//�����ʼ��
		for (j = 0; j < p->vertexNum; j++)
			p->edge[i][j] = 0;
	printf("Input vertex:\n");
	for (i = 0; i < p->vertexNum; i++)
		scanf("%d", &p->vertex[i]);
	printf("Input edge:\n");
	for (i = 0; i < p->vertexNum; i++)
		for (j = 0; j < p->vertexNum; j++)
		{
			printf("%d - %d:\n", i, j);
			scanf("%d", &p->edge[i][j]);     //����ͼ����ͼ��Ȩֵ
		}
	return p;
}
//�����ã�ʡ��ÿ���ֶ�����
MGraph *CreateMGraph_2(int n)
{
	int A[6][6] = {    //65535��ʾ���������ͼ
		{ 0,2,1,65535,65535,4 },
		{ 2,0,5,3,65535,65535 },
		{ 1,5,0,4,2,6 },
		{ 65535,3,4,0,7,65535 },
		{ 65535,65535,2,7,0,5 },
		{ 4,65535,6,65535,5,0 } };
	int B[6][6] = {   //����ͼ
		{ 0,1,65535,65535,65535,3 },
		{ 65535,0,2,65535,65535,5 },
		{ 65535,65535,0,2,65535,1 },
		{ 65535,65535,1,0,4,65535 },
		{ 2,65535,65535,1,0,65535 },
		{ 65535,2,4,5,3,0 }
	};
	int (*q)[6];
	if (n == 0) //65535��ʾ���������ͼ
		q = &A[0];
	else		//����ͼ
		q = &B[0];
	int i, j;
	MGraph *p = (MGraph*)malloc(sizeof(MGraph));
	p->vertexNum = sizeof(A)/sizeof(A[0]);
	for (i = 0; i < p->vertexNum; i++)
		p->vertex[i] = i;
	for (i = 0; i < p->vertexNum; i++)
		for (j = 0; j < p->vertexNum; j++)
			p->edge[i][j] = q[i][j];
	return p;
}
void DisplayMGraph(MGraph *p)
{
	int i, j;
	printf("Vertex Info:\n");
	for (i = 0; i < p->vertexNum; i++)
		printf("\t%d ", p->vertex[i]);
	printf("\nEdge Info:\n");
	for (i = 0; i < p->vertexNum; i++)
	{
		for (j = 0; j < p->vertexNum; j++)
			printf("\t%d ", p->edge[i][j]);
		printf("\n");
	}
}
ALGraph *CreateALGraph()
{
	ALGraph *p;
	ArcNode *s;
	p = (ALGraph *)malloc(sizeof(ALGraph));
	int i, a, b;
	printf("Input VertexNum ArcNum\n");
	scanf("%d%d", &p->vertexNum, &p->arcNum);
	for (i = 0; i < p->vertexNum; i++)
	{	
		printf("Input vertex[%d]: ", i);
		scanf("%d", &p->vertices[i].data);
		p->vertices[i].first = NULL;
	}
	for (i = 0; i < p->arcNum; i++)
	{
		printf("Input No.%d Edge(Vi-Vj): ",i);
		scanf("%d%d", &a, &b);
		s = (ArcNode*)malloc(sizeof(ArcNode));
		s->adjvex = b;
		s->next = p->vertices[a].first;  //ͷ��
		p->vertices[a].first = s;

		s = (ArcNode*)malloc(sizeof(ArcNode)); //����ͼ
		s->adjvex = a;
		s->next = p->vertices[b].first;  
		p->vertices[b].first = s;
	}
	return p;
}
ALGraph *CreateALGraph_2()
{
	ALGraph *p;
	ArcNode *s;
	int A[] = { 1,1,1,2,6,6,7,3,3,8,4,4,4,5,9,0}; //A[i] --> B[i] ����ͼ
	int B[] = { 2,4,5,6,3,7,3,1,8,4,2,9,7,0,8,4};
	p = (ALGraph *)malloc(sizeof(ALGraph));
	int i;
	p->vertexNum = 10;
	p->arcNum = sizeof(A)/sizeof(A[0]);
	for (i = 0; i < p->vertexNum; i++)
	{
		p->vertices[i].data = i;
		p->vertices[i].first = NULL;
	}
	
	for (i = 0; i < p->arcNum; i++)
	{
		s = (ArcNode*)malloc(sizeof(ArcNode));
		s->adjvex = B[i];
		s->next = p->vertices[A[i]].first;  
		p->vertices[A[i]].first = s;

	}
	return p;
}
void DisplayALGraph(ALGraph *p)
{
	ArcNode *s;
	for (int i = 0; i < p->vertexNum; i++)
	{
		printf("No.%d : %d ", i, p->vertices[i].data);
		s = p->vertices[i].first;
		while (s)
		{
			printf("-> %d ", s->adjvex);
			s = s->next;
		}
		printf("\n");
		
	}
}
int FirstNeighbor(ALGraph *p, int v)
{
	ArcNode *s = p->vertices[v].first;
	if (s)
		return s->adjvex;
	else
		return -1;
}
int NextNeighbor(ALGraph *p, int v, int n)
{
	ArcNode *s = p->vertices[v].first;
	while (s->adjvex != n)
		s = s->next;
	s = s->next;
	if (s)
		return s->adjvex;
	else
		return -1;
}
void BFSTraverse(ALGraph *G)
{
	int i;
	for (i = 0; i < G->vertexNum; i++)
		Visited[i] = false;
	Front = -1;  //����Ķ���ȫ�ֱ���
	Rear = -1;
	printf("BFS: \n");
	for (i = 0; i < G->vertexNum; i++) //�ӵ�0��ʼ����,�Է�ͼΪ����ͨͼ
		if (!Visited[i])
			BFS(G, i);
	printf("\n");
}
void BFS(ALGraph *G, int v)
{
	int i, j;
	visit(G, v);
	Visited[v] = 1;
	Queue[++Rear] = v;	//���
	while (Front < Rear)
	{
		i = Queue[++Front];
		for (j = FirstNeighbor(G, i); j >= 0; j = NextNeighbor(G, i, j))
			if (!Visited[j])
			{
				visit(G, j);
				Visited[j] = 1;
				Queue[++Rear] = j;
			}
	}
}
void DFSTraverse(ALGraph *G)
{
	int i;
	printf("DFS:\n");
	for (i = 0; i < G->vertexNum; i++)
		Visited[i] = false;
	for (i = 0; i < G->vertexNum; i++)
		if (!Visited[i])
			DFS(G, i);
	printf("\n");
}
void DFS(ALGraph *G, int v)
{
	int i;
	visit(G, v);
	Visited[v] = 1;
	for (i = FirstNeighbor(G, v); i >= 0; i = NextNeighbor(G, v, i))
		if (!Visited[i])
			DFS(G, i);
}
void visit(ALGraph *G, int v)
{
	printf("%d ", G->vertices[v].data);
}
void BFS_Min_Distance(ALGraph *G, int v)
{
	int d[MaxSize], i, j;
	for (i = 0; i < G->vertexNum; i++)
	{
		d[i] = 65535;
		Visited[i] = 0;
	}
	Visited[v] = 1;
	d[v] = 0;
	Front = -1;
	Rear = -1;
	Queue[++Rear] = v;
	while (Front < Rear)
	{
		i = Queue[++Front];
		for (j = FirstNeighbor(G, i); j >= 0; j = NextNeighbor(G, i, j))
			if (!Visited[j])
			{
				Visited[j] = 1;
				d[j] = d[i] + 1;
				Queue[++Rear] = j;
			}
	}
	printf("BFS Min Distance:\nvertex:");
	for (i = 0; i < G->vertexNum; i++)
		printf("\t%d", i);
	printf("\ndict:");
	for (i = 0; i < G->vertexNum; i++)
		printf("\t%d", d[i]);
	printf("\n--------------------\n");
}
void BFSTraverse_2(ALGraph *G, int source)
{
	bool visitedd[MaxSize];
	int i, front = -1, rear = -1, Q[MaxSize];
	ArcNode *cur;
	for (i = 0; i < G->vertexNum; i++)
		visitedd[i] = false;
	printf("BFS_2:\n");
	printf("%d ", G->vertices[source].data);
	visitedd[source] = 1;
	Q[++rear] = source;
	while (front < rear)
	{
		i = Q[++front];
		cur = G->vertices[i].first;
		while (cur)
		{
			if (!visitedd[cur->adjvex])
			{
				printf("%d ", G->vertices[cur->adjvex].data);
				visitedd[cur->adjvex] = 1;
				Q[++rear] = cur->adjvex;
				cur = cur->next;
			}
			else
				cur = cur->next;
		}
	}
	printf("\n");
}
void DFSTraverse_2(ALGraph *G, int source)
{
	printf("DFS_2:\n");
	DFSTraverse2(G, source);
	printf("\n");
}
void DFSTraverse2(ALGraph *G, int source)
{
	static bool visitedd[MaxSize] = { 0 };
	ArcNode *cur;
	printf("%d ", G->vertices[source].data);
	visitedd[source] = 1;
	cur = G->vertices[source].first;
	while (cur)
	{
		if (!visitedd[cur->adjvex])
			DFSTraverse2(G, cur->adjvex);
		cur = cur->next;
	}
}
//��С������
void Prim(MGraph *G)
{
	printf("Prim:\n");
	int min, i, j, k;
	int path[MaxSize];   //��ʾ���ĸ�������
	int dict[MaxSize];  //ֵΪ0ʱ����ʾ�Ѽӵ��������У�65535Ϊ����ͨ������ΪȨֵ
	path[0] = 0;
	dict[0] = 0;
	for (i = 1; i < G->vertexNum; i++)  //��ʼ������0�ſ�ʼ
	{
		dict[i] = G->edge[0][i];   
		path[i] = 0;
	}
	for (i = 1; i < G->vertexNum; i++)
	{
		min = 65535;
		j = 0;
		k = 0;	
		while (j < G->vertexNum)		//�Ҷ���
		{
			if (dict[j] != 0 && dict[j] < min) //�ҵ���������������Ȩֵ��С��
			{
				min = dict[j];
				k = j;
			} 
			j++;
		}
		printf("\t%d - %d\n", path[k], k);
		dict[k] = 0;//����������	
		for (j = 0; j < G->vertexNum; j++)		//��������
		{
			if (dict[j] != 0 && G->edge[k][j] < dict[j]) //�������ö���ʹȨֵ��С
			{
				dict[j] = G->edge[k][j];
				path[j] = k;
			}
		}
	}
}
//���·��
void Dijkstra(MGraph *G, int v)
{
	int dist[MaxSize] = { 0 };	//Դ�㵽������������·������
	int path[MaxSize] = { 0 };	//Դ�㵽i֮������·����i��ǰ�����
	int s[MaxSize] = { 0 };		//��ʾ�Ƿ���뵽·����
	int i, j, min, u;
	
	for (i = 0; i < G->vertexNum; i++)	//��ʼ��
	{
		dist[i] = G->edge[v][i];
		s[i] = 0;
		if (G->edge[v][i] < 65535)  //�������ͨ
			path[i] = v;
		else
			path[i] = -1;
	}
	s[v] = 1;		//Դ�����
	path[v] = -1;
	for (i = 0; i < G->vertexNum; i++)
	{
		min = 65535;
		for (j = 0; j < G->vertexNum; j++)  //�ҵ�ʣ�����о�����С�Ľ��
		{
			if (s[j] == 0 && dist[j] < min)
			{
				u = j;
				min = dist[j];
			}
		}
		s[u] = 1;	//����·��
		for (j = 0; j < G->vertexNum; j++)
		{
			if (s[j] == 0 && dist[u] + G->edge[u][j] < dist[j]) //�������飬����¼���Ľ�㵽��������·�������
			{
				dist[j] = dist[u] + G->edge[u][i];
				path[j] = u;   //�϶̵�·������u����
			}
		}
	}
	printf("\nDijkstra:\nvertex:");
	for (i = 0; i < G->vertexNum; i++)
		printf("\t%d", i);
	printf("\ndict:");
	for (i = 0; i < G->vertexNum; i++)
		printf("\t%d", dist[i]);
	printf("\npath:");
	for (i = 0; i < G->vertexNum; i++)
		printf("\t%d", path[i]);
	printf("\n");

}
void Floyd(MGraph *G)
{
	int A[MaxSize][MaxSize];
	int path[MaxSize][MaxSize];		//���ڱ���·��
	int i, j, k;
	for (i = 0; i < G->vertexNum; i++)	//��ʼ��
		for (j = 0; j < G->vertexNum; j++)
		{
			A[i][j] = G->edge[i][j];
			path[i][j] = -1;
		}

	for(k=0;k<G->vertexNum;k++)			//k���Դ�1��ʼ
		for(i=0;i<G->vertexNum;i++)
			for(j=0;j<G->vertexNum;j++)
				if (A[i][j] > A[i][k] + A[k][j]) //���i��j�ľ����i����k��j�ľ���С�����¾������ݣ����洢·��
				{
					A[i][j] = A[i][k] + A[k][j];
					path[i][j] = k;
				}


	printf("\nFloyd:\nA:\n");
	for (i = 0; i < G->vertexNum; i++)
		printf("\t%d", i);
	printf("\n   ________________________________________________\n");
	for (i = 0; i < G->vertexNum; i++)
	{
		printf("%d |", i);
		for (j = 0; j < G->vertexNum; j++)
			printf("\t%d", A[i][j]);
		printf("\n");
	}
	printf("path:\n");
	for (i = 0; i < G->vertexNum; i++)
		printf("\t%d", i);
	printf("\n   ________________________________________________\n");
	for (i = 0; i < G->vertexNum; i++)
	{
		printf("%d |", i);
		for (j = 0; j < G->vertexNum; j++)
			printf("\t%d", path[i][j]);
		printf("\n");
	}
}