#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct treeNode {// Ʈ���� ��� ���� ����

	int data;// ������ �ʵ�
	struct treeNode *left;// ���� ���� Ʈ���� ���� ��ũ �ʵ�
	struct treeNode *right;// ������ ���� Ʈ���� ���� ��ũ �ʵ�
} treeNode;


// data�� ��Ʈ ����� ������ �ʵ�� �Ͽ� ���ʰ� ������ ���� Ʈ���� �����ϴ� ����

treeNode* addNewNode(int data, treeNode* leftNode, treeNode* rightNode) {

	treeNode* root = (treeNode *)malloc(sizeof(treeNode));
	root->data = data;
	root->left = leftNode;
	root->right = rightNode;
	return root;
}

// �Ʒ��� �����Ͽ� T1, T2, T3�� �����Ѵ�

//���� ��ȸ

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
// ��� ���� 
int Node_count(treeNode* root) {
	if (root == NULL)
		return 0;
	else
		return Node_count(root->left) + Node_count(root->right) + 1;
}
// ���� ���ϱ�
int Node_height(treeNode *root)
{
	if (root==NULL)
		return 0;

	int left_height = Node_height(root->left);
	int right_height = Node_height(root->right);
	return  (left_height > right_height) ? left_height+1 : right_height + 1;

}
// �����Ѱ�..?
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
		printf("1. ���� ��ȸ\n2. ��� ����\n3. ����\n4. ����\n5. copy�� ���\n6. ����Ž��Ʈ�� �Ǻ�\n\n");
		scanf("%d", &num);

		switch (num) {
		case 1: {
			printf("\n\n ========================== ���� ��ȸ ==========================\n\n");
			printf("T1���� ��ȸ=");
			inorder(T1);
			printf("\n");

			printf("T2���� ��ȸ=");
			inorder(T2);
			printf("\n");

			printf("T3���� ��ȸ=");
			inorder(T3);
			printf("\n");
			printf("\n\n ====================================================\n\n");
			break;
		}
		case 2:{
			printf("\n\n ======================== ����� ���� ============================\n\n");
			printf("t1��� ����= %d\n", Node_count(T1));

			printf("t2��� ����= %d\n", Node_count(T2));

			printf("t3��� ����= %d\n", Node_count(T3));
			printf("\n\n ====================================================\n\n");
			break;
		}
		case 3: {
			printf("\n\n ========================= Ʈ���� ���� ===========================\n\n");
			printf("\n");
			printf("T1����= ");
			printf("%d", Node_height(T1));
			printf("\n");

			printf("T2����= ");
			printf("%d", Node_height(T2));
			printf("\n");

			printf("T3����= ");
			printf("%d", Node_height(T3));
			printf("\n");
			printf("\n");
			printf("\n\n ====================================================\n\n");
			break;
		}
		case 4: {
			printf("\n\n ========================= ���ϼ� �˻� ===========================\n\n");
			printf("T1 �� T2 �����Ѱ�?\t");
			m = equal(T1, T2);
			if (m == 1)
				printf("TRUE(������)");
			else
				printf("FALSE(�������� ����)");
			printf("\n");
			printf("\n");
			printf("T1 �� T3 �����Ѱ�?\t");
			m = equal(T1, T3);
			if (m == 1)
				printf("TRUE(������)");
			else
				printf("FALSE(�������� ����)");
			printf("\n");
			printf("\n");
			printf("T2 �� T3 �����Ѱ�?\t");
			m = equal(T2, T3);
			if (m == 1)
				printf("TRUE(������)");
			else
				printf("FALSE(�������� ����)");
			printf("\n");
			printf("\n");
			printf("T1 �� T1 �����Ѱ�?\t");
			m = equal(T1, T1);
			if (m == 1)
				printf("TRUE(������)");
			else
				printf("FALSE(�������� ����)");
			printf("\n");

			printf("T2 �� T2 �����Ѱ�?\t");
			m = equal(T2, T2);
			if (m == 1)
				printf("TRUE(������)");
			else
				printf("FALSE(�������� ����)");
			printf("\n");

			printf("T3 �� T3 �����Ѱ�?\t");
			m = equal(T3, T3);
			if (m == 1)
				printf("TRUE(������)");
			else
				printf("FALSE(�������� ����)");
			printf("\n");
			printf("\n");
			printf("\n\n ====================================================\n\n");
			break;
		}
		case 5: {
			printf("\n\n ========================= Copy ===========================\n\n");
			temp = copy(T1);
			printf("copy�� t1���� ��ȸ=");
			inorder(temp);
			printf("\n");

			temp = copy(T2);
			printf("copy�� t2���� ��ȸ=");
			inorder(temp);
			printf("\n");

			temp = copy(T3);
			printf("copy�� t3���� ��ȸ=");
			inorder(temp);
			printf("\n");
			printf("\n");
			printf("\n\n ====================================================\n\n");
			break;
		}
		case 6: {
			printf("\n\n ========================= ����Ž��Ʈ�� üũ ===========================\n\n");
			printf("t1 ����Ž��Ʈ�� üũ: \n");
			n = check_BST(T1);
			if (n == 1)
				printf("����Ž��Ʈ�� �Դϴ�.\n");
			else
				printf("����Ž��Ʈ���� �ƴմϴ�.\n");

			printf("t2 ����Ž��Ʈ�� üũ: \n");
			n = check_BST(T2);
			if (n == 1)
				printf("����Ž��Ʈ�� �Դϴ�.\n");
			else
				printf("����Ž��Ʈ���� �ƴմϴ�.\n");

			printf("t3 ����Ž��Ʈ�� üũ: \n");
			n = check_BST(T3);
			if (n == 1)
				printf("����Ž��Ʈ�� �Դϴ�.\n");
			else
				printf("����Ž��Ʈ���� �ƴմϴ�.\n");
			printf("\n\n ====================================================\n\n");
			break;
		}
		}
	}
}