#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct
{
	int data;
	struct ListNode *link;
}ListNode;

ListNode* insert_first(ListNode* head, int data) {
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = data;
	node->link = head;
	head = node;
	return head;
}
int cnt = 0, s_cnt = 0;
void select_sort(int Arr[], int n)
{
	int least,temp;
	for (int i = 0; i < n - 1; i++)
	{
		least = i;
		for (int j = i + 1; j < n; j++)
		{
			if (Arr[j] < Arr[least]) {
				least = j;	
			}
			s_cnt++;
			cnt++;
		}
		temp = Arr[least];
		Arr[least] = Arr[i];
		Arr[i] = temp;
		
		for (int k = 0; k < n; k++)
		{
			printf("%d ", Arr[k]);
		}
		printf("  과정 비교 횟수 : %d\n",s_cnt);
		printf("\n");
		s_cnt = 0;
	}
}
void display(ListNode *head) {
	ListNode *p = head;

	while (p != NULL) {
		printf("%d->", p->data);
		p = p->link;
	}
	printf("\n");
}
ListNode* List_select(ListNode * head)
{
	
	int Min,tmp2;
	ListNode *p1, *p2, *temp;
	temp = NULL;
	
	for (p1 = head; p1->link != NULL; p1 = p1->link)
	{
		Min = p1->data;
		
		for (p2 = p1->link; p2 != NULL; p2 = p2->link)
		{
			
			if (p2->data < Min)
			{
				Min = p2->data;
				temp = p2;
			}
			s_cnt++;
			cnt++;
		}
		tmp2 = p1->data;
		p1->data = temp->data;
		temp->data = tmp2;

		for (ListNode *p3 = head; p3!= NULL; p3 = p3->link)
		{
			printf("%d -> ", p3->data);
		}
		printf("  과정 비교 횟수 : %d\n", s_cnt);
		printf("\n");
		s_cnt = 0;
		

	}
	
	

	return head;
}

int main(void)
{
	while (1) {
		int num;
		printf("1. (배열)선택정렬\n2. (연결리스트) 선택정렬\n");
		scanf("%d", &num);
		switch (num) {
		case 1: {
			int Arr[50];
			int n;

			printf("\n몇개를 배열에 넣으시겠습니까? (50개 이하) \n");
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
			printf("선택정렬 전 배열의 상태\n");
			printf("Arr[%d] = ", n);
			for (int i = 0; i < n; i++)
			{
				printf("%d ", Arr[i]);
			}
			printf("\n\n");

			select_sort(Arr, n);
			printf("\n정렬 후 \n");
			for (int i = 0; i < n; i++)
			{
				printf("%d ", Arr[i]);
			}
			
			printf("\n");

			printf("총 %d번 비교했습니다.\n\n", cnt);
			cnt = 0;
			break;
		}
		case 2:
		{
			ListNode * head;
			head = NULL;
			int arr[100], n;
			printf("몇개의 정수를 넣으시겠습니까? \n");
			scanf("%d", &n);
			for (int i = 0; i < n; i++)
			{
				arr[i] = rand() % 100;
			}
			for (int i = 0; i < n; i++)
			{
				head = insert_first(head, arr[i]);
			}
			printf("100이하의 정수를 %d개 넣었습니다..\n\n", n);
			display(head);
			printf("\n");
			head = List_select(head);

			printf("\n정렬 후 \n\n");
			display(head);

			printf("\n");

			printf("\n총 %d번 비교했습니다.\n\n", cnt);
			cnt = 0;
			break;
		}
		}
	}
}