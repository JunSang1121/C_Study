#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int partition1(int Arr[], int left, int right)
{
	int pivot, i, tmp;
	pivot = Arr[right];
	i = left-1;
	
	for (int j = left; j < right; j++)
	{
		if (Arr[j] < pivot)
		{
			i++;
			tmp = Arr[i];
			Arr[i] = Arr[j];
			Arr[j] = tmp;
			
		}
	}
	printf("\n");
	for (int k = 0; k < right + 1; k++)
	{
		if (Arr[k] == pivot)
		{
			printf("#");
		}
		printf("%d ", Arr[k]);

	}
	printf("\n");

	tmp = Arr[i+1];
	Arr[i+1] = Arr[right];
	Arr[right] = tmp;

	printf("\n변경 후: ");
	for (int k = 0; k < right + 1; k++)
	{
		if (Arr[k] == pivot)
		{
			printf("#");
		}
		printf("%d ", Arr[k]);

	}
	printf("\n");
	return i + 1;
}
int partition2(int Arr[], int left, int right)
{
	int pivot, i, tmp;
	pivot = Arr[left];
	i = left;

	for (int j = i+1; j <= right; j++)
	{
		if (Arr[j] <= pivot)
		{
			i++;
			tmp = Arr[i];
			Arr[i] = Arr[j];
			Arr[j] = tmp;
		}
	}
	printf("\n");
	for (int k = 0; k < right + 1; k++)
	{
		if (Arr[k] == pivot)
		{
			printf("#");
		}
		printf("%d ", Arr[k]);

	}
	printf("\n");
	tmp = Arr[i];
	Arr[i] = Arr[left];
	Arr[left] = tmp;

	printf("\n변경 후: ");
	for (int k = 0; k < right + 1; k++)
	{
		if (Arr[k] == pivot)
		{
			printf("#");
		}
		printf("%d ", Arr[k]);

	}
	printf("\n");
	return i;
}
int partition3(int arr[], int left, int right)
{	
	int pivot, tmp;
	pivot = arr[(right + left) / 2];

	for (int k = 0; k < right + 1; k++)
	{
		if (arr[k] == pivot)
		{
			printf("#");
		}
		printf("%d ", arr[k]);

	}
	printf("\n");

	while (left <= right) {

		while ((arr[left] < pivot) && (left < right))
			left++;

		while ((arr[right] > pivot) && (left < right))
			right--;

		if (left <= right) {
			int temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp;
			left++;
			right--;
		}
	}

	

	printf("\n변경 후: ");
	for (int k = 0; k < right+1; k++)
	{
		if (arr[k] == pivot)
		{
			printf("#");
		}
		printf("%d ", arr[k]);

	}
	printf("\n");

		return left;
}
void QuickSort1(int Arr[], int left, int right)
{
	if (left < right) {
		int q = partition1(Arr, left, right);
		QuickSort1(Arr, left, q - 1);
		QuickSort1(Arr, q + 1, right);
	}
}
void QuickSort2(int Arr[], int left, int right)
{
	if (left < right) {
		int q = partition2(Arr, left, right);
		QuickSort2(Arr, left, q - 1);
		QuickSort2(Arr, q + 1, right);
	}
}
void QuickSort3(int Arr[], int left, int right)
{	
	int q = partition3(Arr, left, right);
	
	if (left < q-1) {
	
		QuickSort3(Arr, left, q - 1);	
	}
	if (q < right)
	{
		QuickSort3(Arr, q , right);
	}
}

int main(void)
{
	while (1) {
		int n, num, Arr[50];
		printf("1.QuickSort(right)\n2.QuickSort(left)\n3.QuickSort(mid)\n4.Quit\n");
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

			printf("\n정렬 전");
			for (int i = 0; i < n; i++)
			{
				printf("%d ", Arr[i]);
			}
			printf("\n");

			QuickSort1(Arr, 0, n - 1);

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
			printf("\n정렬 전");
			for (int i = 0; i < n; i++)
			{
				printf("%d ", Arr[i]);
			}
			printf("\n");

			QuickSort2(Arr, 0, n - 1);

			printf("\n\n정렬 후: ");
			for (int i = 0; i < n; i++)
			{
				printf("%d ", Arr[i]);
			}
			printf("\n");
			break;
		}
		case 3: {
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
			printf("\n정렬 전");
			for (int i = 0; i < n; i++)
			{
				printf("%d ", Arr[i]);
			}
			printf("\n");

			QuickSort3(Arr, 0, n-1);

			printf("\n\n정렬 후: ");
			for (int i = 0; i < n; i++)
			{
				printf("%d ", Arr[i]);
			}
			printf("\n");
			break;
		}
		case 4: {
			return 0;
		}
		}
	}
}