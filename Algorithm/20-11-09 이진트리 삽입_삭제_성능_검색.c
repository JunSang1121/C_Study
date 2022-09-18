#define _CRT_SECURE_NO_WARNINGS
#define MAX(a, b) (((a) > (b)) ? (a) : (b));
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct treeNode {
	int value;// ������ �ʵ�
	struct treeNode* left;// ���� ���� Ʈ�� ��ũ �ʵ�
	struct treeNode* right;// ������ ���� Ʈ�� ��ũ �ʵ�
} treeNode;



treeNode* addNewNode(int value, treeNode* leftNode, treeNode* rightNode) {

	treeNode* root = (treeNode *)malloc(sizeof(treeNode));
	root->value = value;
	root->left = leftNode;
	root->right = rightNode;
	return root;
}	

void inorder(treeNode *node) {
	if (node == NULL) return;

	inorder(node->left);
	printf(" %d ", node->value);
	inorder(node->right);
}

treeNode* insert(treeNode* root, int key)
{
	if (root == NULL)
	{
		root = (treeNode*)malloc(sizeof(treeNode));
		root->left = NULL;
		root->right = NULL;
		root->value = key;
		return root;
	}

	else
	{
		if (root->value == key)
			printf("\n���� �����մϴ�.\n");
		else if (root->value > key)
			root->left = insert(root->left, key);
		else
			root->right = insert(root->right, key);
	}
	return root;

}

void deleteNode(treeNode *root, int key) {

	treeNode *parent, *p, *succ, *succ_parent;
	treeNode *child;

	parent = NULL;
	p = root;

	while ((p != NULL) && (p->value != key)) {  // ������ ����� ��ġ Ž��
		parent = p;
		if (key < p->value)
			p = p->left;
		else 
			p = p->right;
	}
	// ������ ��尡 ���� ���

	if (p == NULL) {
		printf("\n ã�� Ű�� ���� Ʈ���� �����ϴ�!!");
		return;
	}

	// ������ ��尡 �ܸ� ����� ���
	if ((p->left == NULL) && (p->right == NULL)) {
		if (parent != NULL) {
			if (parent->left == p) 
				parent->left = NULL;
			else 
				parent->right = NULL;
		}
		else root = NULL;
	}
	// ������ ��尡 �ڽ� ��带 �� �� ���� ���

	else if ((p->left == NULL) || (p->right == NULL)) {
		if (p->left != NULL) 
			child = p->left;
		else 
			child = p->right;

		if (parent != NULL) {
			if (parent->left == p) 
				parent->left = child;
			else 
				parent->right = child;
		}
		else root = child;
	}
	// ������ ��尡 �ڽ� ��带 �� �� ���� ���

	else {
		succ_parent = p;
		succ = p->right;

		while (succ->left != NULL) { // ???  �İ��� ã��
			succ_parent = succ;
			succ = succ->left;
		}

		if (succ_parent->right == succ)  
			succ_parent->right = succ->right;
		else 
			succ_parent->left = succ->right;
			p->value = succ->value;
			p = succ;
	}
	free(p);
}

treeNode * key_search(treeNode* root, int key)
{
	if (root == NULL)
		return NULL;
	
	if (root->value == key)
		return root;
	else if (root->value > key)
		return key_search(root->left, key);
	else
		return key_search(root->right, key);
}

int get_node_count(treeNode* root) {
	int count = 0;
	if (root != NULL)
		count = 1 + get_node_count(root->left) + get_node_count(root->right);
	return count;
}
int get_height(treeNode* root) {
	int height = 0;
	if (root != NULL) {
		height = 1 + MAX(get_height(root->left), get_height(root->right));
	}
	return height;
}
int get_Level_Node_Count(treeNode* root, int n, int level) {
	if (root == NULL) return 0;
	if (n == level) return 1;
	else
		return get_Level_Node_Count(root->left, n + 1, level) +
		get_Level_Node_Count(root->right, n + 1, level);
}
void IPL_aver(treeNode * T1) {
	double aver = 0.0;
	int ipl = 0;
	int level = get_height(T1);
	double n = get_node_count(T1);

	for (int i = 1; i <= level; i++) {
		ipl += i * (get_Level_Node_Count(T1, 1, i));
	}
	aver = ipl / n;
	printf("\n=========================\n");
	printf("IPL: %d ���: %.2f \n\n", ipl, aver);


}
int hasPathSum(treeNode* root, int sum)
{	
	if (root == NULL) {
		return sum;
	}
	else
	{
		int tmp = 0;
		int remain = sum - root->value;
		if (remain == 0 && root->left == NULL && root->right == NULL)
			return 1;

		if (root->left)
			tmp = (tmp || hasPathSum(root->left, remain) ? 1 : 0);
		if(root->right)
			tmp = (tmp || hasPathSum(root->right, remain) ? 1 : 0);
		return tmp;
	}
		
}
int main(void)
{
	treeNode* m8 = addNewNode(42, NULL, NULL);
	treeNode* m7 = addNewNode(18, NULL, NULL);
	treeNode* m6 = addNewNode(55, m8, NULL);
	treeNode* m5 = addNewNode(20, m7, NULL);
	treeNode* m4 = addNewNode(2, NULL, NULL);
	treeNode* m3 = addNewNode(36, NULL, m6);
	treeNode* m2 = addNewNode(16, m4, m5);
	treeNode* m1 = addNewNode(22, m2, m3);
	treeNode* T1 = m1;

	while (1)
	{
		int num;
		printf("1. �˻�\n2. ��� ����\n3. ��� ����\n4. IPL & ��� �˻� \n5. �� �˻�\n\n");
		scanf("%d", &num);
		switch (num)
		{
		case 1:
		{
			int n;
			printf("�˻��� ���� �Է��Ͻÿ�:");
			scanf("%d", &n);
			
			if (key_search(T1, n) != NULL)
				printf("%d ���� ������\n\n", n);
			else
				printf("%d ���� �������� ����\n\n",n);
			break;
		}
		case 2: {
			int n;
			printf("������ ���� �Է��Ͻÿ�:");
			scanf("%d",&n);
			insert(T1, n);
			printf("\nƮ�� ��:");
			inorder(T1);
			printf("\n");
			break;
		}
		case 3:
		{
			int n;
			printf("������ ���� �Է��Ͻÿ�\n");
			printf("Ʈ�� ��:\n");
			inorder(T1);
			printf("\n");
			printf("������ ��: ");
			scanf("%d", &n);

			deleteNode(T1, n);
			inorder(T1);
			printf("\n\n");
			break;
		}
		case 4: {
			IPL_aver(T1);
			break;
		}
		case 5:
		{
			int n,m;
			printf("sum �� �Է�: \n");
			scanf("%d", &n);
			m = hasPathSum(T1, n);
			if (m == 1)
				printf("�����մϴ�.\n\n");
			else
				printf("�����ϴ�.\n\n");
			
			break;
		}
		}
	}
}