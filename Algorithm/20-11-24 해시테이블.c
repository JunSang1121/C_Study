#define _CRT_SECURE_NO_WARNINGS
/*define Table_Size 13*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

typedef struct
{
	int key;
	int empty;
}element;

struct list
{
	element item1;
	struct list *link;
};
struct list *hash_table1[13];
element *hash_table; //해싱 테이블
element item;
void init_h(element ht[])
{
	int i;
	for (i = 0; i < 13; i++) {
		memset(&ht[i].key,0, sizeof(ht[i].key));
		ht[i].empty = -1;
	}
}
void init_h_chain(struct list *ht[])
{
	for (int i = 0; i < 13; i++)
	{
		ht[i] = NULL;
	}
}

int hash_Func(int key, int m)
{
	return key % m;
}
int hash_Func2(int key)
{
	return 7 - (key % 7);
}
int hash_Func3(int key)
{
	return 1 + (key % 11);
}
int hash_Func4(int key)
{
	return 1 + (key %13);
}

void hash_insert_lp(element item, element *ht,int Table_Size) //선형 조사법
{
	int i, value;
	value = i = hash_Func(item.key,Table_Size);

	while (ht[i].empty == 1)
	{
		if (item.key == ht[i].key)
		{
			printf("탐색키 중복");
			exit(1);
		}
		printf(" 값이 들어있습니다. 위치를 이동합니다. 위치: [%d] -> ",i);
		i = (i + 1) % Table_Size;
		printf("[%d]\n",i);
		if (i == value)
			printf("테이블 가득참\n");
	}

	item.empty = 1;
	ht[i] = item;
}
void hash_insert_qp(element item, element *ht, int Table_Size) //이차조사법
{
	int i, value,inc=0;
	value = i = hash_Func4(item.key);
	while (ht[i].empty == 1)
	{
		if (item.key == ht[i].key)
		{
			printf("탐색키 중복");
			exit(1);
		}
		printf(" 값이 들어있습니다. 위치를 이동합니다. 위치: [%d] -> ", i);
		i = (value + inc*inc) % Table_Size;
		inc = inc + 1;
		printf("[%d]\n", i);
		if (i == value)
			printf("테이블 가득참\n");
	}

	item.empty = 1;
	ht[i] = item;
}
void hash_insert_dh(element item, element *ht, int Table_Size) //이중
{
	int i, value, inc;
	value = i = hash_Func3(item.key, Table_Size);
	inc = hash_Func4(item.key);
	while (ht[i].empty == 1)
	{
		if (item.key == ht[i].key)
		{
			printf("탐색키 중복");
			exit(1);
		}
		printf(" 값이 들어있습니다. 위치를 이동합니다. 위치: [%d] -> ", i);
		i = (i + inc) % Table_Size;
		printf("[%d]\n", i);
		if (i == value)
			printf("테이블 가득참\n");
	}

	item.empty = 1;
	ht[i] = item;
}
void hash_insert_dh2(element item, element *ht, int Table_Size) //이중 (전공 서적)
{
	int i, value, inc;
	value = i = hash_Func(item.key, Table_Size);
	inc = hash_Func3(item.key);
	while (ht[i].empty == 1)
	{
		if (item.key == ht[i].key)
		{
			printf("탐색키 중복");
			exit(1);
		}
		printf(" 값이 들어있습니다. 위치를 이동합니다. 위치: [%d] -> ", i);
		i = (i + inc) % Table_Size;
		printf("[%d]\n", i);
		if (i == value)
			printf("테이블 가득참\n");
	}

	item.empty = 1;
	ht[i] = item;
}
void hash_insert_chain(element item, struct list *ht[])
{
	int value = hash_Func(item.key, 11);
	struct list *ptr;
	struct list *node_before = NULL, *node = ht[value];
	for (; node; node_before = node, node = node->link)
	{
		if (node->item1.key == item.key)
		{
			printf("이미 존재합니다.\n");
			return;
		}
	}
	ptr= (struct list*)malloc(sizeof(struct list));
	ptr->item1 = item;
	ptr->link = NULL;
	if (node_before)
		node_before->link = ptr;
	else
		ht[value] = ptr;
}
void hash_print_chain(struct list *ht[])
{
	struct list *node;
	int i;
	for (i = 0; i < 11; i++)
	{
		printf("[%d]->", i);
		for (node = ht[i]; node; node=node->link)
		{
			printf("%d->", node->item1.key);
		}
		printf("\n");
	}
}
void hash_print(element *ht, int Table_Size)
{
	for (int i = 0; i < Table_Size; i++)
	{
		printf("[%d] %d\n", i, ht[i].key);
	}
	printf("\n\n");
}
void textcolor(int color_number)

{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_number);
}
int main(void)
{
	hash_table = (element*)malloc(sizeof(element)*13/*Table_Size*/);
	init_h(hash_table);

	while (1) {

		int num,n;
		printf("1. 선형 조사법\n2. 이차조사법\n3. 이중 해싱법\n4  체이닝\n5. 그만\n\n");
		scanf("%d", &num);
		switch (num) {
		case 1:
			printf("1. 전공 서적 문제\n2. 과제\n\n");
			scanf("%d", &n);
			if (n == 1) {
				printf("값 입력\n");
				for (int i = 0; i < 8; i++)
				{
					scanf("%d", &item.key);
					printf("\n");
					hash_insert_lp(item, hash_table,13);
					hash_print(hash_table,13);
				}
				textcolor(14);
				printf("\n=============최종=============\n\n");
				for (int i = 0; i < 7; i++)
				{
					
					printf("[%d] %d\n", i, hash_table[i].key);
				}
				printf("\n=============================\n\n");
				textcolor(7);
				init_h(hash_table);
			}
			if (n == 2) {
				printf("값 입력\n");
				for (int i = 0; i < 11; i++)
				{
					scanf("%d", &item.key);
					printf("\n");
					hash_insert_lp(item, hash_table,11);
					hash_print(hash_table,11);
				}
				textcolor(14);
				printf("\n=============최종=============\n\n");
				for (int i = 0; i < 11; i++)
				{
					printf("[%d] %d\n", i, hash_table[i].key);
				}
				printf("\n=============================\n\n");
				textcolor(7);
				init_h(hash_table);
			}
			break;

		case 2:
			printf("1. 교과서 문제\n2. 과제\n\n");
			scanf("%d", &n);
			if (n == 1) {
				printf("값 입력\n");
				for (int i = 0; i < 8; i++)
				{
					scanf("%d", &item.key);
					printf("\n");
					hash_insert_qp(item, hash_table, 13);
					hash_print(hash_table, 13);
				}
				textcolor(14);
				printf("\n=============최종=============\n\n");
				for (int i = 0; i < 13; i++)
				{
					printf("[%d] %d\n", i, hash_table[i].key);
				}
				printf("\n=============================\n\n");
				textcolor(7);
				init_h(hash_table);
			}
			if (n == 2) {
				printf("값 입력\n");
				for (int i = 0; i < 7; i++)
				{
					scanf("%d", &item.key);
					printf("\n");
					hash_insert_qp(item, hash_table, 13);
					hash_print(hash_table, 13);
				}
				textcolor(14);
				printf("\n=============최종=============\n\n");
				for (int i = 0; i < 13; i++)
				{
					printf("[%d] %d\n", i, hash_table[i].key);
				}
				printf("\n=============================\n\n");
				textcolor(7);
				init_h(hash_table);
			}
			break;
		case 3:
			printf("1. 교과서 문제\n2. 과제\n\n");
			scanf("%d", &n);
			if (n == 1) {
				printf("값 입력\n");

				for (int i = 0; i < 7; i++)
				{
					scanf("%d", &item.key);
					printf("\n");
					hash_insert_dh2(item, hash_table, 13);
					hash_print(hash_table, 13);
				}
				textcolor(14);
				printf("\n=============최종=============\n\n");
				for (int i = 0; i < 13; i++)
				{
					printf("[%d] %d\n", i, hash_table[i].key);
				}
				printf("\n=============================\n\n");
				textcolor(7);
				init_h(hash_table);
			}
			if (n == 2) {
				printf("값 입력\n");
				for (int i = 0; i < 11; i++)
				{
					scanf("%d", &item.key);
					printf("\n");
					hash_insert_dh(item, hash_table, 11);
					hash_print(hash_table, 11);
				}
				textcolor(14);
				printf("\n=============최종=============\n\n");
				for (int i = 0; i < 11; i++)
				{
					printf("[%d] %d\n", i, hash_table[i].key);
				}
				printf("\n=============================\n\n");
				textcolor(7);
				init_h(hash_table);
			}
			break;
		case 4:
			printf("값 입력\n");
			for (int i = 0; i < 11; i++)
			{
				scanf("%d", &item.key);
				printf("\n");
				hash_insert_chain(item, hash_table1);
				hash_print_chain(hash_table1);
			}
			textcolor(14);
			printf("\n=============최종=============\n\n");
			for (int i = 0; i < 11; i++)
			{
				printf("[%d]->", i);
				for (struct list *node = hash_table1[i]; node; node = node->link)
				{
					printf("%d->", node->item1.key);
				}
				printf("\n");
			}
			printf("\n=============================\n\n");
			textcolor(7);
			init_h_chain(hash_table1);
			break;
		case 5:
			return 0;
		}

	}
	free(hash_table);
}