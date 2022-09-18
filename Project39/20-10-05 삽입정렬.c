#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cnt = 0,I_cnt=0;

void rand_(int Arr[], int n)
{
	
	srand((unsigned)time(NULL));

	for (int i = 0; i < n; i++)
	{
		Arr[i] = rand() % 100;
		for (int j = 0; j < i; j++)
		{
			if (Arr[i] == Arr[j])
			{
				i--;
				break;
			}
		}
	}
}

void insertion_sort(int Arr[],int n)
{
	int i,j,key;
	printf("<<<<<<<<<<<<삽입 정렬 수행>>>>>>>>>>>>\n\n");
	for (i = 1; i < n; i++)
	{
		key = Arr[i];
		
		for (j = i - 1; j >= 0; j--)
		{	
			cnt++;
			I_cnt++;
			if (Arr[j] > key) 
				Arr[j + 1] = Arr[j];
			else 
				break;
			
		}
		Arr[j + 1] = key;
		

		
		printf("%d단계: < ",i);
		for (int k = 0; k < n; k++)
		{
			printf("%d ", Arr[k]);
			if (k == i)
				printf(" > ");
		}
		printf("   비교 횟수: %d\n",I_cnt);
		I_cnt = 0;
		printf("\n");
	}
}
void Bubble_sort(int Arr[], int n)
{
	int temp;
	printf("<<<<<<<<<<<<버블 정렬 수행>>>>>>>>>>>>\n\n");
	for (int i = 0; i < n - 1; i++)
	{
		printf("%d단계>> \n", i + 1);

		for (int j = 0; j < n - 1 - i; j++)
		{
			I_cnt++;
			cnt++;
			if (Arr[j] > Arr[j + 1])
			{
				temp = Arr[j];
				Arr[j] = Arr[j + 1];
				Arr[j + 1] = temp;

			}

			printf("   ");
			for (int k = 0; k < n; k++)
			{
				printf("%d ", Arr[k]);

			}
			printf("\n");
		}

		printf("   비교 횟수: %d\n", I_cnt);
		I_cnt = 0;
		printf("\n");
	}
}
void Bubble_sort_flag(int Arr[],int n)
{
	int temp,flag;
	int m = n-1;
	printf("<<<<<<<<<<<<버블 정렬 수행>>>>>>>>>>>>\n\n");
	for (int i = 0; i < n-1; i++)
	{
		printf("%d단계>> \n", i+1);
		
		flag = 1;
		for (int j = 0; j < n-1-i; j++)
		{	
			I_cnt++;
				cnt++;
			if (Arr[j] > Arr[j + 1])
			{
				flag = 0;
				temp = Arr[j];
				Arr[j] = Arr[j+1];
				Arr[j+1] = temp;
				
			}
			
			printf("   ");
			for (int k = 0; k < n; k++)
			{
				printf("%d ", Arr[k]);
				if (k == m) {
					printf(" # ");
				}
			}
			
			printf("\n");
		}
		m--;
		printf("   비교 횟수: %d\n", I_cnt);
		I_cnt = 0;
		printf("\n");
		if (flag == 1)
				break;
	}
}
int main(void)
{
	while (1)
	{
		int num;
		printf("1. 삽입 정렬,\n2. 버블정렬\n3. 버블정렬(flag)\n4. 종료\n");
		scanf("%d", &num);
		switch (num)
		{
		case 1:
		{
			int Arr[50];
			int n;

			printf("\n몇개를 배열에 넣으시겠습니까? (50개 이하) \n");
			scanf("%d", &n);

			rand_(Arr,n);
			
			printf("삽입정렬 전 배열의 상태\n");

			for (int i = 0; i < n; i++)
			{
				printf("%d ", Arr[i]);
			}
			printf("\n\n");

			insertion_sort(Arr, n);
			printf("\n정렬 후\n");
			for (int i = 0; i < n; i++)
			{
				printf("%d ", Arr[i]);
			}
			printf("\n전체 비교횟수: %d", cnt);
			cnt = 0;
			printf("\n\n");
			break;
		}
		case 2:
		{
			int Arr[50];
			int n;

			printf("\n몇개를 배열에 넣으시겠습니까? (50개 이하) \n");
			scanf("%d", &n);

			rand_(Arr, n);

			printf("버블정렬 전 배열의 상태\n");

			for (int i = 0; i < n; i++)
			{
				printf("%d ", Arr[i]);
			}
			printf("\n\n");

			Bubble_sort(Arr, n);
			printf("\n정렬 후\n");
			for (int i = 0; i < n; i++)
			{
				printf("%d ", Arr[i]);
			}
			printf("\n전체 비교횟수: %d", cnt);
			cnt = 0;
			printf("\n\n");
			break;
		}
		case 3:
		{
			int Arr[50];
			int n;

			printf("\n몇개를 배열에 넣으시겠습니까? (50개 이하) \n");
			scanf("%d", &n);

			rand_(Arr, n);

			printf("버블정렬 전 배열의 상태\n");

			for (int i = 0; i < n; i++)
			{
				printf("%d ", Arr[i]);
			}
			printf("\n\n");

			Bubble_sort_flag(Arr, n);
			printf("\n정렬 후\n");
			for (int i = 0; i < n; i++)
			{
				printf("%d ", Arr[i]);
			}
			printf("\n전체 비교횟수: %d", cnt);
			cnt = 0;
			printf("\n\n");
			break;
		}
		case 4:
			return 0;
		}
	}
}