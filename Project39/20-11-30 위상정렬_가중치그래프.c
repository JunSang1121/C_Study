#define _CRT_SECURE_NO_WARNINGS
#define true 1
#define false 0
#define MAX_VERTICES 8	  // ���� �׷����� ���� ����
#define INF 10000  
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


int visited[50], result[50], resN = 0,cnt=0;


//��������Ʈ
typedef struct {
	int vertex;
	struct GraphNode* link;
}GraphNode;

//��������Ʈ �׷��� ����ü
typedef struct {
	int n;
	GraphNode* List[50];
}Graph_l;

void init_graph1(Graph_l*g)
{
	int v;
	g->n = 0;
	for (v = 0; v < 50; v++)
		g->List[v] = NULL;
}
//����Ʈ ���� ����
void insert_vertex1(Graph_l* g, int v)
{
	if (((g->n) + 1) > 50)
	{
		printf("�׷��� �ִ� �������� �ʰ�");
	}

	g->n = v;
}
// ����Ʈ ���� ����
void insert_edge1(Graph_l*g, int u, int v)
{
	GraphNode* node;
	  
	node = (GraphNode*)malloc(sizeof(GraphNode));
	node->vertex = v;
	node->link = g->List[u];
	g->List[u] = node;
}
void DFS(Graph_l* g, int v)
{
	GraphNode* w;
	visited[v] = true;   		// ���� v�� �湮 ǥ�� 
	printf("���� %d -> ", v);		// �湮�� ���� ���
	for (w = g->List[v]; w; w = w->link)// ���� ���� Ž�� 
		if (!visited[w->vertex])
			DFS(g, w->vertex); //���� w���� DFS ���� ����
	result[++resN] = v;
	cnt++;
}

void toposort(Graph_l* g, int v)
{
	resN = 0;	
	for (int i = 1; i <= 8; i++)
		visited[i] = false;
	if (!visited[v])
		DFS(g, v);
	for (int i = 1; i < 8; i++)
	{
		if (visited[i] == false)
		{
			printf(" / ");
			DFS(g, i);
		}
	}
}

void print_list(Graph_l* g)
{
	for (int i = 1; i <= g->n; i++)
	{
		GraphNode* p = g->List[i];
		printf("���� %d�� ���� ����Ʈ ", i);
		while (p != NULL)
		{
			printf("-> %d ", p->vertex);
			p = p->link;

		}
		if (p == NULL)
		{
			printf("-> *");
		}
		printf("\n");
	}
}

int weight[MAX_VERTICES][MAX_VERTICES] = {
	{0,10,INF,INF,INF,4,INF,7},
	{INF,0,8,INF,INF,INF,INF,INF},
	{INF,INF,0,12,INF,INF,INF,INF},
	{INF,INF,INF,0,4,INF,INF,INF},
	{INF,INF,INF,INF,0,INF,3,INF},
	{INF,INF,INF,INF,20,0,8,INF},
	{INF,INF,INF,7,INF,INF,0,12},
	{INF,2,8,INF,INF,2,INF,0}
};

int distance[MAX_VERTICES];	// ���� �������κ����� �ִ� ��� ���� ����
int S[MAX_VERTICES];		// ������ ���� S
int prev[MAX_VERTICES];


int nextVertex(int n) // �ּ� �Ÿ��� ���� ���� ������ ã�� ����
{
	int i, min, minpos;
	min = INT_MAX;
	minpos = -1;
	for (i = 0; i < n; i++)
	{
		if (distance[i] < min && !S[i])
		{
			min = distance[i];
			minpos = i;
		}
	}
	return minpos;
}
int printStep(int step)
{
	printf("STEP %d ", step);
	printf("distance: ");
	for (int i =1; i < 8; i++)
	{
		if (distance[i] == INF)
			printf(" * ");
		else
			printf("%2d ", distance[i]);
	}
	printf("\n");
	printf("\t   �湮: ");
	for (int i = 1; i < 8; i++)
	{
		printf("%2d ", S[i]);
	}
	printf("\n\n");
}

void Dijkstra_shortestPath(int start, int n)
{
	int i, u, w, step = 0;
	for (i = 0; i < n; i++)
	{
		distance[i] = weight[start][i];
		S[i] = false;
	}
	S[start] = true;
	distance[start] = 0;

	for (i = 0; i < n-1; i++)
	{
		printStep(i);
		u = nextVertex(n);
		S[u] = true;
		for (w = 0; w < n; w++)
		{
			if (!S[w])
				if (distance[u] + weight[u][w] < distance[w]) {
					distance[w] = distance[u] + weight[u][w];
				}
		}
	}
}
void print_matrix()
{
	for (int i = 1; i < 8; i++)
	{
		for (int j = 1; j < 8; j++)
		{
			printf("%2d ", weight[i][j]);
		}
		printf("\n");
	}
}
int main(void)
{	
	Graph_l* g3 = (Graph_l*)malloc(sizeof(Graph_l));

		init_graph1(g3);
		insert_vertex1(g3, 8);

		insert_edge1(g3, 1, 2);
		insert_edge1(g3, 1, 4);
		insert_edge1(g3, 2, 3);
		insert_edge1(g3, 4, 5);
		insert_edge1(g3, 4, 6);
		insert_edge1(g3, 5, 6);
		insert_edge1(g3, 5, 7);
		insert_edge1(g3, 6, 7);
		insert_edge1(g3, 6, 8);

	while (1)
	{

		int num;
		int n;
		printf("1.�������� \n2.�ִܰ�� \n\n\n");
		scanf("%d", &num);
		switch (num) {
		case 1:
			
			printf("����Ʈ ��\n");
			print_list(g3);

			printf("\n\n������ ����: ");
			scanf("%d", &n);
			toposort(g3, n);

			printf("\n\n���: ");
			for (int i = cnt; i >= 1; i--)
			{
				printf(" %d ", result[i]);
			}
			cnt = 0;
			printf("\n\n");
			break;
		case 2:
			printf("\n���� ���\n\n");
			print_matrix();
			printf("\n\n������ ���� �Է�: ");
			scanf("%d", &n);
			printf("\n\n");
			Dijkstra_shortestPath(n, MAX_VERTICES);
			break;
		}
	}
}