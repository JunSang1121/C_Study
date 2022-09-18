#define _CRT_SECURE_NO_WARNINGS
#define true 1
#define false 0
#define MAX_QUEUE_SIZE 50
#include <stdio.h>
#include <stdlib.h>


int visited[50];

//인접행렬 그래프 구조체
typedef struct {
	int n;
	int matrix[50][50];
}Graph_v;

// 인접리스트
typedef struct {
	int vertex;
	struct GraphNode* link;
}GraphNode;
//인접리스트 그래프 구조체
typedef struct {
	int n;
	GraphNode* List[50];
}Graph_l;
// 큐 타입
typedef struct {
	int queue[MAX_QUEUE_SIZE];
	int front, rear;
} QueueType;
//오류
void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1);
}
//초기화
void queue_init(QueueType* q) {
	q->front = q->rear = 0;
}
//공백
int is_empty(QueueType* q)
{
	return (q->front == q->rear);
}

// 포화 상태 검출 함수
int is_full(QueueType* q)
{
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

// 삽입 함수
void enqueue(QueueType* q, int item) {
	if (is_full(q))
		error("큐가 포화상태입니다");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->queue[q->rear] = item;
}

// 삭제 함수
int dequeue(QueueType* q) {
	if (is_empty(q))
		error("큐가 공백상태입니다");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->queue[q->front];
}
// 인접배열 초기화
void init_graph(Graph_v*g)
{
	int r, c;
	g->n = 0;
	for (r = 0; r < 50; r++)
		for (c = 0; c < 50; c++)
			g->matrix[r][c] = 0;
}
// 리스트 초기화
void init_graph1(Graph_l*g)
{
	int v;
	g->n = 0;
	for (v = 0; v < 50; v++)
		g->List[v] = NULL;

}
// 정점 삽입(행렬)
void insert_vertex(Graph_v* g, int v)
{
	if (((g->n) + 1) > 50)
	{
		printf("그래프 최대 정점개수 초과");
	}

	g->n = v;
}
//정점 삽입(리스트)
void insert_vertex1(Graph_l* g, int v)
{
	if (((g->n) + 1) > 50)
	{
		printf("그래프 최대 정점개수 초과");
	}

	g->n = v;
}
//방향x 인접행렬
void insert_edge(Graph_v*g, int start, int end)
{
	
	g->matrix[start][end] = 1;
	g->matrix[end][start] = 1;
}
void insert_edge1(Graph_l*g, int u, int v)
{
	GraphNode* node;

	node = (GraphNode*)malloc(sizeof(GraphNode));
	node->vertex = v;
	node->link = g->List[u];
	g->List[u] = node;
}
void print_matrix(Graph_v* g)
{
	for (int i = 1; i <= g->n; i++)
	{
		for (int j = 1; j <= g->n; j++)
		{
			printf("%2d ", g->matrix[i][j]);
		}
		printf("\n");
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
void BFS_matrix(Graph_v* g, int v)
{
	int w;
	QueueType q;

	queue_init(&q);     // 큐 초기화 
	visited[v] = true;          // 정점 v 방문 표시 
	printf("%d 방문 -> ", v);
	enqueue(&q, v);			// 시작 정점을 큐에 저장 
	while (!is_empty(&q)) {
		v = dequeue(&q);		// 큐에 정점 추출 
		for (w = 1; w <= g->n; w++)	// 인접 정점 탐색 
			if (g->matrix[v][w] && !visited[w]) {
				visited[w] = true;    // 방문 표시
				printf("%d 방문 -> ", w);
				enqueue(&q, w); 	// 방문한 정점을 큐에 저장
			}
	}
}
void DFS_matrix(Graph_v* g, int v)
{
	int w;
	visited[v] = true;		// 정점 v의 방문 표시 
	printf("정점 %d -> ", v);		// 방문한 정점 출력
	for (w = 1; w <= g->n; w++) 		// 인접 정점 탐색
		if (g->matrix[v][w] && !visited[w])
			DFS_matrix(g, w);	//정점 w에서 DFS 새로 시작
}
void BFS_list(Graph_l* g, int v)
{
	GraphNode* w;
	QueueType q;

	queue_init(&q);    				// 큐 초기 화 
	visited[v] = true;      // 정점 v 방문 표시 
	printf("%d 방문 -> ", v);
	enqueue(&q, v);			// 시작정점을 큐에 저장 
	while (!is_empty(&q)) {
		v = dequeue(&q);		// 큐에 저장된 정점 선택 
		for (w = g->List[v]; w; w = w->link) //인접 정점 탐색
			if (!visited[w->vertex]) {	// 미방문 정점 탐색 
				visited[w->vertex] = true;   // 방문 표시
				printf("%d 방문 -> ", w->vertex);
				enqueue(&q, w->vertex);	//정점을 큐에 삽입
			}
	}
}
void DFS_list(Graph_l* g, int v)
{
	GraphNode* w;
	visited[v] = true;   		// 정점 v의 방문 표시 
	printf("정점 %d -> ", v);		// 방문한 정점 출력
	for (w = g->List[v]; w; w = w->link)// 인접 정점 탐색 
		if (!visited[w->vertex])
			DFS_list(g, w->vertex); //정점 w에서 DFS 새로 시작
}
int main(void)
{
	Graph_v* g1 = (Graph_v*)malloc(sizeof(Graph_v));
				init_graph(g1);
				insert_vertex(g1,14);

				insert_edge(g1, 1, 2);
				insert_edge(g1, 1, 3);
				insert_edge(g1, 2, 9);
				insert_edge(g1, 2, 4);
				insert_edge(g1, 3, 4);
				insert_edge(g1, 3, 5);
				insert_edge(g1, 4, 5);
				insert_edge(g1, 4, 7);
				insert_edge(g1, 4, 11);
				insert_edge(g1, 5, 8);
				insert_edge(g1, 5, 6);
				insert_edge(g1, 6, 7);
				insert_edge(g1, 6, 10);
				insert_edge(g1, 7, 14);
				insert_edge(g1, 9, 11);
				insert_edge(g1, 11, 12);
				insert_edge(g1, 12, 13);
				insert_edge(g1, 12, 14);

	Graph_l* g2 = (Graph_l*)malloc(sizeof(Graph_l));
				init_graph1(g2);
				insert_vertex(g2, 14);

				insert_edge1(g2, 1, 2);
				insert_edge1(g2, 1, 3);
				insert_edge1(g2, 1, 4);
				insert_edge1(g2, 2, 5);
				insert_edge1(g2, 2, 3);
				insert_edge1(g2, 2, 1);
				insert_edge1(g2, 3, 1);
				insert_edge1(g2, 3, 2);
				insert_edge1(g2, 3, 6);
				insert_edge1(g2, 4, 9);
				insert_edge1(g2, 4, 1);
				insert_edge1(g2, 5, 2);
				insert_edge1(g2, 6, 3);
				insert_edge1(g2, 6, 7);
				insert_edge1(g2, 6, 8);
				insert_edge1(g2, 6, 9);
				insert_edge1(g2, 7, 6);
				insert_edge1(g2, 8, 6);
				insert_edge1(g2, 9, 4);
				insert_edge1(g2, 9, 6);
				insert_edge1(g2, 10, 11);
				insert_edge1(g2, 11, 10);
				insert_edge1(g2, 11, 12);
				insert_edge1(g2, 11, 13);
				insert_edge1(g2, 12, 11);
				insert_edge1(g2, 13, 11);

	Graph_l* g3 = (Graph_l*)malloc(sizeof(Graph_l));
				init_graph1(g3);
				insert_vertex(g3, 12);

				insert_edge1(g3, 1, 2);
				insert_edge1(g3, 1, 5);
				insert_edge1(g3, 2, 3);
				insert_edge1(g3, 3, 4);
				insert_edge1(g3, 5, 3);
				insert_edge1(g3, 5, 6);
				insert_edge1(g3, 6, 7);
				insert_edge1(g3, 6, 8);
				insert_edge1(g3, 7, 11);
				insert_edge1(g3, 8, 9);
				insert_edge1(g3, 8, 10);
				insert_edge1(g3, 10, 5);
				insert_edge1(g3, 11, 10);
				
	while (1)
	{	

		int num;
		int a;
		printf("1. 출력\n2. BFS\n3. DFS\n\n");
		scanf("%d", &num);
		switch (num) 
		{
		case 1: 
			printf("\n\n\tG1\n\n");
			print_matrix(g1);
			printf("\n\n\tG2\n\n");
			print_list(g2);
			printf("\n\n\tG3\n\n");
			print_list(g3); 

			printf("\n\n");
			break;
			
			  
		case 2: 
			   
			printf("임의의 값 입력하시오. \n");
			scanf("%d",& a);
			printf("\n\n\tG1\n\n");
			BFS_matrix(g1,a);
			for (int i = 0; i < 50; i++)
				visited[i] = 0;
			printf("\n\n\tG2\n\n");
			BFS_list(g2,a);
			for (int i = 0; i < 50; i++)
				visited[i] = 0;
			printf("\n\n\tG3\n\n");
			BFS_list(g3, a);
			for (int i = 0; i < 50; i++)
				visited[i] = 0;

			printf("\n\n");
			break;
		
		case 3: 

			printf("임의의 값 입력하시오. \n");
			scanf("%d",& a);
			printf("\n\n\tG1\n\n");
			DFS_matrix(g1, a);
			for (int i = 0; i < 50; i++)
				visited[i] = 0;
			printf("\n\n\tG2\n\n");
			DFS_list(g2, a);
			for (int i = 0; i < 50; i++)
				visited[i] = 0;
			printf("\n\n\tG3\n\n");
			DFS_list(g3, a);
			for (int i = 0; i < 50; i++)
				visited[i] = 0;

			printf("\n\n");
			break;
		   
		}
	}
	free(g1);
	free(g2);
	free(g3);
}