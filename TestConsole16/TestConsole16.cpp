// 60% 확률로 크리티컬 데미지 주는 프로그램 만들기
// loop 사용해서 종료 입력 전까지 반복
// 플레이어가 어떤 상태인지 출력해서 보여줄 것 (왜 크리티컬인지, 아닌지 알 수 있어야 함.)

// 헤더파일 추가
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <conio.h>

// 메인 함수 시작
int main()
{
	// 변수 선언, 상수화를 통해 값 고정
	const int playerDamage = 100;				// 현재 플레이어의 데미지
	const float critical_Strike_Rate = 1.5;		// 크리티컬 배율
	const int diceRange = 101;					// 주사위 값을 0 ~ 100 까지
	int randomDice;								// 치명타 확률을 랜덤 주사위에 따라 결정되게함
	bool isCritical_hit;						// 치명타의 여부

	srand(time(NULL));							// rand() 함수의 키 값을 바꿔줌

	// 게임 시작
	while (1)
	{

		printf("아무키나 눌러 공격하세요!!!");
		_getch();
		printf("\n");

		// 주사위를 굴려서 치명타의 여부를 결정합니다.
		randomDice = (rand() % diceRange);
		printf("[주사위 값이 40 % 이상이면 치명타 성공]\n");
		Sleep(500);
		printf("주사위를 굴리는 중입니다.");

		for (int i = 3; i >= 0; i -= 1)
		{
			Sleep(1000);
			printf("....\n");
		}

		if (randomDice >= 40 && randomDice <= 100)
		{
			isCritical_hit = 1;
		}
		else
		{
			isCritical_hit = 0;
		}


		// 치명타가 발동했는지 출력합니다.
		if (isCritical_hit)
		{
			printf("\n주사위 값 : %d \n", randomDice);
			printf("\n★★★★★치명타 성공!★★★★★\n");
			printf("치명타 배율 : %.0f\n", critical_Strike_Rate * 100);
			printf("가한 데미지 : %.0f\n", playerDamage * critical_Strike_Rate);
		}

		else
		{
			printf("\n주사위 값 : %d \n", randomDice);
			printf("\n----------치명타 실패!----------\n");
			printf("가한 데미지 : %d\n", playerDamage);
		}
		printf("\n\n");
	}
}
