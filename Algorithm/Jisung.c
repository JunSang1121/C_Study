#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int merge_tmp[500] = { NULL, }; // ���� ����
void Merge(int A[], int p, int q, int r, int n) {
	int i = p, j = q + 1, t = 0;
	int cnt = 0;
	printf(">> ");
	for (int a = p; a <= r; a++) {
		printf("%d ", A[a]);
		if (a == q) printf("| ");
	}

	printf("\n");
	while (i <= q && j <= r) {
		if (A[i] <= A[j]) {
			merge_tmp[t++] = A[i++];
			cnt++;
		}
		else {
			merge_tmp[t++] = A[j++];
			cnt++;
		}
	}
	while (i <= q) merge_tmp[t++] = A[i++];
	while (j <= r) merge_tmp[t++] = A[j++];
	i = p;
	t = 0;
	while (i <= r)
		A[i++] = merge_tmp[t++];

	printf("����: ");
	for (int a = p; a <= r; a++)
		printf("%d ", A[a]);
	printf(" (%d ��)\n", cnt);

}

void MergeSort(int A[], int p, int r, int n) {
	int q;
	printf("�� ���� >> ");
	for (int a = p; a <= r; a++)
		printf("%d ", A[a]);
	printf("\n");
	if (p < r) {
		q = (((p - 1) + r) / 2);
		MergeSort(A, p, q, n);
		MergeSort(A, q + 1, r, n);
		Merge(A, p, q, r, n);
		printf("\n--------------------------------\n");
		printf("���� ����: ");
		for (int a = 1; a <= n; a++) {
			if (a == p) printf("< ");
			printf("%d ", A[a]);
			if (a == r) printf("> ");
		}
		printf("\n--------------------------------\n\n");
	}

	else {
		printf(" >> ");
		for (int a = p; a <= r; a++)
			printf("%d ", A[a]);
		printf(" (end)\n");

		printf("\n--------------------------------\n");
		printf("���� ����: ");
		for (int a = 1; a <= n; a++) {
			if (a == p) printf("< ");
			printf("%d ", A[a]);
			if (a == r) printf("> ");
		}
		printf("\n--------------------------------\n\n");
	}
}


void MaxHeapify(int A[], int k, int n) {
	int left = 2 * k;
	int right = (2 * k) + 1;
	int bigger;
	int temp;
	if (left <= n && right <= n) {
		printf("���� ���: %d\n", A[k]);
		printf("����: %d, ������: %d\n", A[left], A[right]);
	}
	else if (left <= n) {
		printf("���� ���: %d\n", A[k]);
		printf("����: %d, ������: NULL\n\n", A[left]);
	}
	else {
		printf("���� ���: %d\n", A[k]);
		printf("����: NULL, ������: NULL\n\n");
	}

	if (right <= n) {
		if (A[left] > A[right]) {
			bigger = left;
		}
		else {
			bigger = right;
		}
	}
	else if (left <= n) {
		bigger = left;
	}
	else return;

	if (A[bigger] > A[k]) {
		printf("\n--------------------------------\n");
		printf("\n%d�� %d �� ��ȯ\n", A[k], A[bigger]);
		for (int a = 1; a <= n; a++)
			if (a == k) printf("[%d] ", A[k]);
			else if (a == bigger) printf("[%d] ", A[bigger]);
			else printf("%d ", A[a]);
		printf("\n");
		temp = A[k];
		A[k] = A[bigger];
		A[bigger] = temp;
		printf("=> ");
		for (int a = 1; a <= n; a++)
			if (a == k) printf("[%d] ", A[k]);
			else if (a == bigger) printf("[%d] ", A[bigger]);
			else printf("%d ", A[a]);
		printf("\n--------------------------------\n\n");
		MaxHeapify(A, bigger, n);
	}
}

void MaxBuildHeap(int A[], int n) {
	for (int i = (n / 2); i >= 1; i--) {
		MaxHeapify(A, i, n);
	}
	printf("\n--------------------------------\n");
	printf("�ʱ� �� >> ");
	for (int a = 1; a <= n; a++)
		printf("%d ", A[a]);
	printf("\n--------------------------------\n\n");
}

void MaxHeapSort(int A[], int n) {
	int temp;
	MaxBuildHeap(A, n);
	for (int i = n; i >= 1; i--) { // n�� �ݺ��ؾ��� O(n)
		temp = A[1];
		A[1] = A[i];
		A[i] = temp;
		printf("--------------------------------\n");
		printf("�� ���� >> ");
		for (int a = 1; a <= n; a++)
			if (a == i) printf("| %d ", A[a]);
			else printf("%d ", A[a]);
		printf("\n--------------------------------\n\n");

		MaxHeapify(A, 1, i - 1); // O(logn)

		printf("\n--------------------------------\n");
		printf("heapify >> ");
		for (int a = 1; a <= n; a++)
			if (a == i) printf("| %d ", A[a]);
			else printf("%d ", A[a]);
		printf("\n");
	}// -> O(nlogn)
}

int array_print() {
	int num = 0;
	printf("\n<<<<<<<<<<���� ���>>>>>>>>>>\n\n");
	printf("1. ���� �Է�\n");
	printf("2. ���� �Է�\n");
	printf("3. ����\n");
	printf("�Է�: "); scanf("%d", &num);
	return num;
}

void Array(int num) {
	srand((unsigned int)time(NULL));
	int n = 0;
	printf("\n#���尳��(����:0): "); scanf("%d", &n);
	if (n == 0) {
		printf("�����մϴ�.\n");
		return 0;
	}
	int* A = (int*)malloc(sizeof(int) * (n));
	A[0] = NULL; // 1���� ����

	int num2;
	num2 = array_print();
	if (num2 == 1) {
		for (int i = 1; i <= n; i++) {
			printf("�Է�(index:%d): ", i);
			scanf("%d", &A[i]);
		}
	}
	else if (num2 == 2) {
		for (int i = 1; i <= n; i++)
			A[i] = (rand() % 99 + 1);
	}
	else if (num2 == 3) {
		printf("�����մϴ�.\n");
		return 0;
	}
	else {
		printf("�߸��Է��ϼ̽��ϴ�.");
		while (getchar() != '\n');
		return 0;
	}

	if (num == 1) {
		printf("\n<<<<<<<<<<���� ���� ����>>>>>>>>>>>\n");

		printf("\n--------------------------------\n");
		printf("������ ����: ");
		for (int i = 1; i <= n; i++)
			printf("%d ", A[i]);
		printf("\n--------------------------------\n\n");

		MergeSort(A, 1, n, n);
		printf("==> ���� ����: ");
		for (int a = 1; a <= n; a++)
			printf("%d ", A[a]);
		printf("\n");
	}
	else if (num == 2) {
		printf("\n<<<<<<<<<<�� ���� ����>>>>>>>>>>>\n");

		printf("\n--------------------------------\n");
		printf("������ ����: ");
		for (int i = 1; i <= n; i++)
			printf("%d ", A[i]);
		printf("\n--------------------------------\n");

		MaxHeapSort(A, n);
		printf("==> ���� ����: ");
		for (int a = 1; a <= n; a++)
			printf("%d ", A[a]);
		printf("\n");
	}

}

int main_print() {
	int num = 0;
	printf("\n<<<<<<<<<<����>>>>>>>>>>\n\n");
	printf("1. ���� ����\n");
	printf("2. �� ����(max)\n");
	printf("3. ����\n");
	printf("�Է�: "); scanf("%d", &num);
	return num;
}

int main() {
	int num = 0;
	while (1) {
		num = main_print();
		switch (num) {
		case 1:
		case 2:
			Array(num);
			break;
		case 3:
			printf("�����մϴ�.\n");
			return 0;
			break;
		default:
			printf("�߸��Է��ϼ̽��ϴ�.");
			while (getchar() != '\n');
			break;
		}
	}
}