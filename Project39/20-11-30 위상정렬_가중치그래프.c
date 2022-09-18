#define _CRT_SECURE_NO_WARNINGS
#define true 1
#define false 0
#define MAX_VERTICES 8	  // 예제 그래프의 정점 개수
#define INF 10000  
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>


int visited[50], result[50], resN = 0,cnt=0;


//인접리스트
typedef struct {
	int vertex;
	struct GraphNode* link;
}GraphNode;

//인접리스트 그래프 구조체
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
//리스트 정점 삽입
void insert_vertex1(Graph_l* g, int v)
{
	if (((g->n) + 1) > 50)
	{
		printf("그래프 최대 정점개수 초과");
	}

	g->n = v;
}
// 리스트 간선 삽입
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
	visited[v] = true;   		// 정점 v의 방문 표시 
	printf("정점 %d -> ", v);		// 방문한 정점 출력
	for (w = g->List[v]; w; w = w->link)// 인접 정점 탐색 
		if (!visited[w->vertex])
			DFS(g, w->vertex); //정점 w에서 DFS 새로 시작
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
		printf("정점 %d의 인접 리스트 ", i);
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

int distance[MAX_VERTICES];	// 시작 정점으로부터의 최단 경로 길이 저장
int S[MAX_VERTICES];		// 정점의 집합 S
int prev[MAX_VERTICES];


int nextVertex(int n) // 최소 거리를 갖는 다음 정점을 찾는 연산
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
	printf("\t   방문: ");
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
		printf("1.위상정렬 \n2.최단경로 \n\n\n");
		scanf("%d", &num);
		switch (num) {
		case 1:
			
			printf("리스트 값\n");
			print_list(g3);

			printf("\n\n시작할 정점: ");
			scanf("%d", &n);
			toposort(g3, n);

			printf("\n\n결과: ");
			for (int i = cnt; i >= 1; i--)
			{
				printf(" %d ", result[i]);
			}
			cnt = 0;
			printf("\n\n");
			break;
		case 2:
			printf("\n인접 행렬\n\n");
			print_matrix();
			printf("\n\n시작할 정점 입력: ");
			scanf("%d", &n);
			printf("\n\n");
			Dijkstra_shortestPath(n, MAX_VERTICES);
			break;
		}
	}
}