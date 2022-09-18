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

		// 타이틀 화면 출력
		printf("*= Blacksmith With C =*\n");

		// 현재 상태와 강화 도전 질의 출력
		printf("현재 소지금 : %d\n", funds);
		printf("무기 판매 비용 : %d\n", wepon_price);
		printf("강화 비용 : %d\n", 20);
		printf("무기레벨 : + %d\n", level);
		printf("성공확률 : %.2f%%\n", probability);
		printf("파괴확률 : %.2f%%\n", destroid);
		printf("도전하시겠습니까?\n");
		printf("1.강화   2.판매\n");
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
			printf("강화비용이 부족합니다.\n");
			retTime = time(0) + WAIT_TIME;
			while (time(0) < retTime);
			funds += 20;
			title_main();
		}
		printf("강화비용만큼 소지금에서 차감되었습니다.\n");
		printf("현재 소지금 : %d\n",funds);

		printf("\n강화중..\n\n");
		retTime = time(0) + WAIT_TIME;
		while (time(0) < retTime);

		randNum = (rand() % 10000 + 1) * 0.01f;

		if (level > 3)
			destroid = destroid + 0.6;
		else if (level < 3)
			destroid = 0.0;

		if (randNum < probability) {
			// 성공화면 출력-

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
			// 실패화면 출력
			printf("어익후.. 손이 미끌어졌네..\n");
			printf("5레벨 이전은 강화레벨이 감소하지 않습니다...\n");

			printf("***** STAY *****\n");
			printf("*                 *\n");
			printf("*   + %d  ->  + %d  *\n", level, level);
			printf("*                 *\n");
			printf("***** STAY *****\n");

			retTime = time(0) + WAIT_TIME;\
			while (time(0) < retTime);
			// 수치 stay
		}
		else if (level >= 5 && randNum > probability)
		{
			

			destroid -= 1.2;

			// 실패화면 출력
			printf("어익후.. 손이 미끌어졌네..\n");
			printf("강화레벨이 1 감소합니다...\n");

			printf("***** FAIL *****\n");
			printf("*                 *\n");
			printf("*   + %d  ->  + %d  *\n", level, level - 1);
			printf("*                 *\n");
			printf("***** FAIL *****\n");

			retTime = time(0) + WAIT_TIME;
			while (time(0) < retTime);

			// 각종 수치 1 다운
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
			printf("어익후.. 손이 미끌어졌네..\n");
			printf("+ %d 무기를 잃었습니다.\n", level);

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