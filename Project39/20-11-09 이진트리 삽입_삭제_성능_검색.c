#define _CRT_SECURE_NO_WARNINGS
#define MAX(a, b) (((a) > (b)) ? (a) : (b));
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct treeNode {
	int value;// 데이터 필드
	struct treeNode* left;// 왼쪽 서브 트리 링크 필드
	struct treeNode* right;// 오른쪽 서브 트리 링크 필드
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
			printf("\n값이 존재합니다.\n");
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

	while ((p != NULL) && (p->value != key)) {  // 삭제할 노드의 위치 탐색
		parent = p;
		if (key < p->value)
			p = p->left;
		else 
			p = p->right;
	}
	// 삭제할 노드가 없는 경우

	if (p == NULL) {
		printf("\n 찾는 키가 이진 트리에 없습니다!!");
		return;
	}

	// 삭제할 노드가 단말 노드인 경우
	if ((p->left == NULL) && (p->right == NULL)) {
		if (parent != NULL) {
			if (parent->left == p) 
				parent->left = NULL;
			else 
				parent->right = NULL;
		}
		else root = NULL;
	}
	// 삭제할 노드가 자식 노드를 한 개 가진 경우

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
	// 삭제할 노드가 자식 노드를 두 개 가진 경우

	else {
		succ_parent = p;
		succ = p->right;

		while (succ->left != NULL) { // ???  후계자 찾기
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
	printf("IPL: %d 평균: %.2f \n\n", ipl, aver);


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
		printf("1. 검색\n2. 노드 삽입\n3. 노드 삭제\n4. IPL & 평균 검색 \n5. 합 검색\n\n");
		scanf("%d", &num);
		switch (num)
		{
		case 1:
		{
			int n;
			printf("검색할 값을 입력하시오:");
			scanf("%d", &n);
			
			if (key_search(T1, n) != NULL)
				printf("%d 값이 존재함\n\n", n);
			else
				printf("%d 값이 존재하지 않음\n\n",n);
			break;
		}
		case 2: {
			int n;
			printf("삽입할 값을 입력하시오:");
			scanf("%d",&n);
			insert(T1, n);
			printf("\n트리 값:");
			inorder(T1);
			printf("\n");
			break;
		}
		case 3:
		{
			int n;
			printf("삭제할 값을 입력하시오\n");
			printf("트리 값:\n");
			inorder(T1);
			printf("\n");
			printf("삭제할 값: ");
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
			printf("sum 값 입력: \n");
			scanf("%d", &n);
			m = hasPathSum(T1, n);
			if (m == 1)
				printf("존재합니다.\n\n");
			else
				printf("없습니다.\n\n");
			
			break;
		}
		}
	}
}