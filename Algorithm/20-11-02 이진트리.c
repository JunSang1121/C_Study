#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct treeNode {// 트리의 노드 구조 정의

	int data;// 데이터 필드
	struct treeNode *left;// 왼쪽 서브 트리에 대한 링크 필드
	struct treeNode *right;// 오른쪽 서브 트리에 대한 링크 필드
} treeNode;


// data를 루트 노드의 데이터 필드로 하여 왼쪽과 오른쪽 서브 트리를 연결하는 연산

treeNode* addNewNode(int data, treeNode* leftNode, treeNode* rightNode) {

	treeNode* root = (treeNode *)malloc(sizeof(treeNode));
	root->data = data;
	root->left = leftNode;
	root->right = rightNode;
	return root;
}

// 아래를 참조하여 T1, T2, T3를 생성한다

//중위 순회

int Arr[1024];
int n = 0;
void inorder(treeNode *node) {
	if (node == NULL) return;
	
	inorder(node->left);
	Arr[n++] = node->data;
	printf(" %d ", node->data);
	inorder(node->right);
}

int check_BST(treeNode *root)
{	
	n = 0;
	inorder(root);
	
	for (int i = 0; i < n - 1; i++)
	{
		if (Arr[i] >= Arr[i + 1])
			return 0; //false
	}
	
	return 1; // true
}
// 노드 개수 
int Node_count(treeNode* root) {
	if (root == NULL)
		return 0;
	else
		return Node_count(root->left) + Node_count(root->right) + 1;
}
// 높이 구하기
int Node_height(treeNode *root)
{
	if (root==NULL)
		return 0;

	int left_height = Node_height(root->left);
	int right_height = Node_height(root->right);
	return  (left_height > right_height) ? left_height+1 : right_height + 1;

}
// 동일한가..?
int equal(treeNode *first, treeNode *second)
{
	if (first == NULL && second == NULL)
		return 1; //true
	else if (first != NULL && second != NULL)
	{
		if (equal(first->left, second->left))
		{
			if (equal(first->right, second->right))
			{
				if (first->data == second->data)
					return 1;
			}
		}

	}
	return 0; //false
}
treeNode * copy(treeNode * root)
{
	if (root == NULL)
		return NULL;

	treeNode *temp = (treeNode*)malloc(sizeof(treeNode));
	temp->left = copy(root->left);
	temp->right = copy(root->right);
	temp->data = root->data;
	return temp;
}

int main(void)
{
	int m,n;
	treeNode* temp;

	treeNode* n8 = addNewNode(42, NULL, NULL);
	treeNode* n7 = addNewNode(30, NULL, NULL);
	treeNode* n6 = addNewNode(55, n8, NULL);
	treeNode* n5 = addNewNode(15, n7, NULL);
	treeNode* n4 = addNewNode(2, NULL, NULL);
	treeNode* n3 = addNewNode(10, NULL, n6);
	treeNode* n2 = addNewNode(16, n4, n5);
	treeNode* n1 = addNewNode(22, n2, n3);
	treeNode* T1 = n1;

	treeNode* m8 = addNewNode(42, NULL, NULL);
	treeNode* m7 = addNewNode(18, NULL, NULL);
	treeNode* m6 = addNewNode(55, m8, NULL);
	treeNode* m5 = addNewNode(20, m7, NULL);
	treeNode* m4 = addNewNode(2, NULL, NULL);
	treeNode* m3 = addNewNode(36, NULL, m6);
	treeNode* m2 = addNewNode(16, m4, m5);
	treeNode* m1 = addNewNode(22, m2, m3);
	treeNode* T2 = m1;

	treeNode* p8 = addNewNode(42, NULL, NULL);
	treeNode* p7 = addNewNode(18, NULL, p8);
	treeNode* p6 = addNewNode(55, NULL, NULL);
	treeNode* p5 = addNewNode(20, p7, NULL);
	treeNode* p4 = addNewNode(2, NULL, NULL);
	treeNode* p3 = addNewNode(36, NULL, p6);
	treeNode* p2 = addNewNode(16, p4, p5);
	treeNode* p1 = addNewNode(22, p2, p3);
	treeNode* T3 = p1;
	while (1) {
		int num;
		printf("1. 중위 순회\n2. 노드 개수\n3. 높이\n4. 동일\n5. copy본 출력\n6. 이진탐색트리 판별\n\n");
		scanf("%d", &num);

		switch (num) {
		case 1: {
			printf("\n\n ========================== 중위 순회 ==========================\n\n");
			printf("T1중위 순회=");
			inorder(T1);
			printf("\n");

			printf("T2중위 순회=");
			inorder(T2);
			printf("\n");

			printf("T3중위 순회=");
			inorder(T3);
			printf("\n");
			printf("\n\n ====================================================\n\n");
			break;
		}
		case 2:{
			printf("\n\n ======================== 노드의 개수 ============================\n\n");
			printf("t1노드 개수= %d\n", Node_count(T1));

			printf("t2노드 개수= %d\n", Node_count(T2));

			printf("t3노드 개수= %d\n", Node_count(T3));
			printf("\n\n ====================================================\n\n");
			break;
		}
		case 3: {
			printf("\n\n ========================= 트리의 높이 ===========================\n\n");
			printf("\n");
			printf("T1높이= ");
			printf("%d", Node_height(T1));
			printf("\n");

			printf("T2높이= ");
			printf("%d", Node_height(T2));
			printf("\n");

			printf("T3높이= ");
			printf("%d", Node_height(T3));
			printf("\n");
			printf("\n");
			printf("\n\n ====================================================\n\n");
			break;
		}
		case 4: {
			printf("\n\n ========================= 동일성 검사 ===========================\n\n");
			printf("T1 과 T2 동일한가?\t");
			m = equal(T1, T2);
			if (m == 1)
				printf("TRUE(동일함)");
			else
				printf("FALSE(동일하지 않음)");
			printf("\n");
			printf("\n");
			printf("T1 과 T3 동일한가?\t");
			m = equal(T1, T3);
			if (m == 1)
				printf("TRUE(동일함)");
			else
				printf("FALSE(동일하지 않음)");
			printf("\n");
			printf("\n");
			printf("T2 과 T3 동일한가?\t");
			m = equal(T2, T3);
			if (m == 1)
				printf("TRUE(동일함)");
			else
				printf("FALSE(동일하지 않음)");
			printf("\n");
			printf("\n");
			printf("T1 과 T1 동일한가?\t");
			m = equal(T1, T1);
			if (m == 1)
				printf("TRUE(동일함)");
			else
				printf("FALSE(동일하지 않음)");
			printf("\n");

			printf("T2 과 T2 동일한가?\t");
			m = equal(T2, T2);
			if (m == 1)
				printf("TRUE(동일함)");
			else
				printf("FALSE(동일하지 않음)");
			printf("\n");

			printf("T3 과 T3 동일한가?\t");
			m = equal(T3, T3);
			if (m == 1)
				printf("TRUE(동일함)");
			else
				printf("FALSE(동일하지 않음)");
			printf("\n");
			printf("\n");
			printf("\n\n ====================================================\n\n");
			break;
		}
		case 5: {
			printf("\n\n ========================= Copy ===========================\n\n");
			temp = copy(T1);
			printf("copy한 t1중위 순회=");
			inorder(temp);
			printf("\n");

			temp = copy(T2);
			printf("copy한 t2중위 순회=");
			inorder(temp);
			printf("\n");

			temp = copy(T3);
			printf("copy한 t3중위 순회=");
			inorder(temp);
			printf("\n");
			printf("\n");
			printf("\n\n ====================================================\n\n");
			break;
		}
		case 6: {
			printf("\n\n ========================= 이진탐색트리 체크 ===========================\n\n");
			printf("t1 이진탐색트리 체크: \n");
			n = check_BST(T1);
			if (n == 1)
				printf("이진탐색트리 입니다.\n");
			else
				printf("이진탐색트리가 아닙니다.\n");

			printf("t2 이진탐색트리 체크: \n");
			n = check_BST(T2);
			if (n == 1)
				printf("이진탐색트리 입니다.\n");
			else
				printf("이진탐색트리가 아닙니다.\n");

			printf("t3 이진탐색트리 체크: \n");
			n = check_BST(T3);
			if (n == 1)
				printf("이진탐색트리 입니다.\n");
			else
				printf("이진탐색트리가 아닙니다.\n");
			printf("\n\n ====================================================\n\n");
			break;
		}
		}
	}
}