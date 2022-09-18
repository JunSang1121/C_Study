#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int map[4][4] = {
	{6,9,11,7},
	{3,3,12,15},
	{7,16,3,4},
	{8,13,19,5}
};
int L[10][10];
int dp[100] = { 0 }, dp1[100] = { 0 }, coin[3] = { 80,50,10 };


int Max(int x, int y,int xy)
{
	if (x > y&&x > xy)
		return x;
	else if (x > y && x < xy)
		return xy;
	else if (x<y && y > xy)
		return y;
	else
		return xy;
}
int mat(int i, int j)
{
	int result = 0;

	if (i == 0 && j == 0)
		result = map[i][j];
	else if (i == 0)
		result = mat(0, j - 1) + map[i][j];
	else if (j == 0)
		result = mat(i - 1, 0) + map[i][j];
	else
		result = Max(mat(i - 1, j), mat(i, j - 1), mat(i - 1, j - 1)) + map[i][j];
	
	L[i][j] = result;
	return L[i][j];
}

int stair(int n)
{
	
	if (dp1[n] != 0) {
		printf("%d ->", dp1[n]);
		return dp1[n];
	}
	if (n <= 1)
		return n;
	return dp1[n] = stair(n - 1) + stair(n - 2);
}

int Way(int n)
{
	return stair(n + 1);
}
int main(void)
{	
	
	while (1)
	{
		int p,num1=0;
		int num;
		int n;
		printf("1.행렬 이동. \n2.계단 오르기\n3.최소 우표 개수 \n\n\n");
		scanf("%d", &num);
		switch (num) {
		case 1:

			printf("\n결과 값:%d\n\n",mat(3,3));
			printf("map값\n");
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					printf("%4d  ", map[i][j]);
				}
				printf("\n");
			}
			printf("\n\n\n");
			printf("DP\n");
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					printf("%4d  ", L[i][j]);
				}
				printf("\n");
			}
			printf("\n\n");
			
			break;
		case 2:

			printf("계단 개수 입력\n");
			scanf("%d", &n);
			printf("\n방법의 총 가짓수 =  %d\n\n\n",Way(n));
			for (int i = 0; i < 100; i++)
			{
				dp1[i] = 0;
			}
			break;
			
		case 3:
		

			printf("금액 입력: ");
			scanf("%d", &p);

			int * c = (int*)malloc(sizeof(int)*(p + 1));

			for (int i = 1; i <= p; i++)
			{
				c[i] = INT_MAX;
			}
			c[0] = 0;
			for (int i = 1; i <= p; i++)
			{
				for (int j = 0; j < 3; j++)
				{ 
					if (coin[j] <= i && c[i - coin[j]] + 1 < c[i])
						c[i] = c[i - coin[j]] + 1;
				}
			}
			printf("\nDP: %d개\n\n", c[p]);
	
			for (int i = 0; i < 3; i++)
			{
				while (p >= coin[i]) {
					p -= coin[i];
					num1++;
				}
			}
			printf("\n그리드: %d개\n\n", num1);
			break;
		}
		
	}
	
	

	

	
	
}
