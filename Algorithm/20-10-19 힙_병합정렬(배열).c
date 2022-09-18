#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cnt = 0;

void print_arr(int* arr, int n)
{
	printf("\n배열 출력\n");
	for (int i = 1;i <= n; i++)
		printf("%3d ", arr[i]);
	printf("\n");
}
int mergeSort(int Arr[], int p, int r, int n) {
	
	if (p < r) {
		int q = (p + r) / 2;
		mergeSort(Arr, p, q, n);
		mergeSort(Arr, q + 1, r, n);
		merge(Arr, p, q, r, n);
	}
}

int merge(int Arr[], int p, int q, int r, int n)
{

	int i = p, j = q + 1, t = p;
	int tmp[100];
	while (i <= q&&j <= r)
	{// 비교해서 작은값부터 넣기
		if (Arr[i] <= Arr[j]) 
			tmp[t++] = Arr[i++];	
		else 
			tmp[t++] = Arr[j++];
	}
	
	
	while (i <= q) // left에 남아있으면 남은값 넣어주기
		tmp[t++] = Arr[i++];
	while (j <= r)// right에 남아있으면 남은값 넣어주기
		tmp[t++] = Arr[j++];

	for (int k = p; k <= r; k++)
		Arr[k] = tmp[k];

	printf("병합정렬 >> ");
	for (int a = 0; a < n; a++)
	{
		if (a == p)
			printf("[ ");
		printf("%d ", Arr[a]);
		if (a == r)
			printf("] ");
	}
	printf("\n\n");
}

int heapSort(int Arr[],int n)
{
	
	int tmp = 0;
	buildHeap(Arr, n);
	printf("\n\n\t<Heap Sorting>");
	printf("\n===========================\n");
	for (int i = n; i > 0; i--)
	{
		printf("\n***");
		printf("\nroot >> [%d]<->last index : [%d]\n",Arr[1], Arr[i]);
		printf("***\n\n");
		tmp = Arr[1];
		Arr[1] = Arr[i];
		Arr[i] = tmp;
		printf("교환 후");
		print_arr(Arr, n);
		heapify(Arr, 1, i-1);
	}
	printf("\n===========================\n");
}

int buildHeap(int Arr[], int n)
{
	printf("\n\n\t<build heap>");
	printf("\n===========================\n");
	for (int i = (n / 2); i > 0; i--)
	{
		heapify(Arr, i, n);
	}
	printf("\n===========================\n");
	
}
int heapify(int Arr[], int k, int n)
{
	int left, right;
	int smaller = k;
	int tmp = 0;
	left = 2 * k;
	right = (2 * k) + 1;
	if (left <= n && Arr[left] > Arr[smaller]) {
		smaller = left;
	}
	if (right <= n && Arr[right] > Arr[smaller]) {
		smaller = right;
	}
	
	
	if (smaller != k)
	{
		printf("\n(%d번째 index값: %d) <-> (%d번째 index값: %d)", k, Arr[k], smaller, Arr[smaller]);
		tmp = Arr[smaller];
		Arr[smaller] = Arr[k];
		Arr[k] = tmp;
		cnt++;
		print_arr(Arr, n);
		heapify(Arr, smaller, n);
	}

}
int main(void)
{
	while (1) {
		int n, num, Arr[50];
		printf("1.mergeSort\n2.heapSort\n3.Quit\n");
		scanf("%d", &num);
		switch (num) {
		case 1: {
			printf("몇개 입력? (50개 이하)\n");
			scanf("%d", &n);

			srand((unsigned)time(NULL));

			for (int i = 0; i < n; i++)
			{
				Arr[i] = rand() % 50;
				for (int j = 0; j < i; j++)
				{
					if (Arr[i] == Arr[j])
					{
						i--;
						break;
					}
				}
			}

			printf("\n정렬 전: ");
			for (int i = 0; i < n; i++)
			{
				printf("%d ", Arr[i]);
			}
			printf("\n\n");

			printf("\n\n\t<<<<<<<<<< 병합 정렬 수행 >>>>>>>>>>\n\n");
			mergeSort(Arr, 0, n - 1,n);

			printf("\n\n정렬 후: ");
			for (int i = 0; i < n; i++)
			{
				printf("%d ", Arr[i]);
			}
			printf("\n");
			break;
		}
		case 2: {
			printf("몇개 입력? (50개 이하)\n");
			scanf("%d", &n);
			srand((unsigned)time(NULL));

			for (int i = 1; i <= n; i++)
			{
				Arr[i] = rand() % 50;
				for (int j = 1; j < i; j++)
				{
					if (Arr[i] == Arr[j])
					{
						i--;
						break;
					}
				}
			}

			printf("\n정렬 전 ");
			for (int i = 1; i <= n; i++)
			{
				printf("%d ", Arr[i]);
			}
			printf("\n");


			heapSort(Arr, n);

			printf("\n\n정렬 후: ");
			for (int i = 1; i <= n; i++)
			{
				printf("%d ", Arr[i]);
			}
			printf("\n");
			printf("교환 횟수: %d\n", cnt);
			cnt = 0;
			break;
		}
		case 3: {
			return 0;
		}
		
		}
	}
}