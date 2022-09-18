#include<stdio.h>
#include<windows.h>
#include<stdlib.h>
#include<time.h>

#define MAX_PROBABILITY 100.0f
#define WAIT_TIME 1

int level = 0;
float probability = MAX_PROBABILITY;
int funds= 1000;
int wepon_price =1;
double destroid = 0.0;

void title_main()
{	
	srand((double)time(NULL));
	int isTry = 0;
	while (1)
	{
		system("@cls||clear");

		// Ÿ��Ʋ ȭ�� ���
		printf("*= Blacksmith With C =*\n");

		// ���� ���¿� ��ȭ ���� ���� ���
		printf("���� ������ : %d\n", funds);
		printf("���� �Ǹ� ��� : %d\n", wepon_price);
		printf("��ȭ ��� : %d\n", 20);
		printf("���ⷹ�� : + %d\n", level);
		printf("����Ȯ�� : %.2f%%\n", probability);
		printf("�ı�Ȯ�� : %.2f%%\n", destroid);
		printf("�����Ͻðڽ��ϱ�?\n");
		printf("1.��ȭ   2.�Ǹ�\n");
		scanf_s("%d", &isTry);
		
		str_wepon(isTry);
	}
}
int str_wepon(int isTry)
{	
	time_t retTime = 0;
	double randNum = 0.0;
	

	switch (isTry)
	{
	case 1:
		funds -= 20;
		if (funds < 0)
		{
			printf("��ȭ����� �����մϴ�.\n");
			retTime = time(0) + WAIT_TIME;
			while (time(0) < retTime);
			funds += 20;
			title_main();
		}
		printf("��ȭ��븸ŭ �����ݿ��� �����Ǿ����ϴ�.\n");
		printf("���� ������ : %d\n",funds);

		printf("\n��ȭ��..\n\n");
		retTime = time(0) + WAIT_TIME;
		while (time(0) < retTime);

		randNum = (rand() % 10000 + 1) * 0.01f;

		if (level > 3)
			destroid = destroid + 0.6;
		else if (level < 3)
			destroid = 0.0;

		if (randNum < probability) {
			// ����ȭ�� ���-

			printf("***** SUCCESS *****\n");
			printf("*                 *\n");
			printf("*   + %d  ->  + %d  *\n", level, level + 1);
			printf("*                 *\n");
			printf("***** SUCCESS *****\n");

			retTime = time(0) + WAIT_TIME;
			while (time(0) < retTime);
			
			level++;
			wepon_price = level *level * 15;
			probability -= (probability / 30.0f) * level;
			if (level > 6)
				probability = 35.0f;
			
		}
		else if (level <= 4 && randNum > probability)
		{
			destroid = 0.0;
			// ����ȭ�� ���
			printf("������.. ���� �̲�������..\n");
			printf("5���� ������ ��ȭ������ �������� �ʽ��ϴ�...\n");

			printf("***** STAY *****\n");
			printf("*                 *\n");
			printf("*   + %d  ->  + %d  *\n", level, level);
			printf("*                 *\n");
			printf("***** STAY *****\n");

			retTime = time(0) + WAIT_TIME;\
			while (time(0) < retTime);
			// ��ġ stay
		}
		else if (level >= 5 && randNum > probability)
		{
			

			destroid -= 1.2;

			// ����ȭ�� ���
			printf("������.. ���� �̲�������..\n");
			printf("��ȭ������ 1 �����մϴ�...\n");

			printf("***** FAIL *****\n");
			printf("*                 *\n");
			printf("*   + %d  ->  + %d  *\n", level, level - 1);
			printf("*                 *\n");
			printf("***** FAIL *****\n");

			retTime = time(0) + WAIT_TIME;
			while (time(0) < retTime);

			// ���� ��ġ 1 �ٿ�
			level = level - 1;
			wepon_price = level *level * 15;
			probability += (probability / 20.0f) * level;

			if (level == 5)
				destroid = 0.6;
			if (level > 6)
				probability = 30.0f;
			
		}
		
		else if (level >= 7 && randNum > probability || destroid > randNum)
		{
			destroid = 0.0;
			printf("������.. ���� �̲�������..\n");
			printf("+ %d ���⸦ �Ҿ����ϴ�.\n", level);

			printf("***** DESTROID *****\n");
			printf("*                 *\n");
			printf("*   + %d  ->  + %d  *\n", level, 0);
			printf("*                 *\n");
			printf("***** DESTROID *****\n");

			retTime = time(0) + WAIT_TIME;
			while (time(0) < retTime);

			level = 0;
			wepon_price = level * level * 15;
			probability = MAX_PROBABILITY;
		}
		break;
	case 2:
		funds += wepon_price;
		level = 0;
		wepon_price = 1;
		probability = 100.0f;

		break;
	}

}

int main(void)
{
	title_main();
}