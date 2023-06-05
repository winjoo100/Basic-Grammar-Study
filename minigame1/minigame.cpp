// 게임 루프를 활용해서 배틀시스템 + 걷기 시스템만들기
// 플레이어의 최대 Hp는 50, 플레이어는 6번 길 (Load)을 걸으면 게임 종료

#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include <stdlib.h>

// 함수 전방 선언
// { 이미지 출력 관련 함수
void PrintDice();
void StartGameCattle();
void Load_Art();
void Mountain_Art();
void MountainHeal_Art();
void River_Art();
void GameClear_Art();
void GameOver_Art();
void Bat_Art();
void Bear_Art();
void Slime_Art();
// }

int MonsterBattle(int playerHp, int playerDamage); // 몬스터와 전투하는 함수
void RollTheDice();								   // 주사위 굴리는 연출을 하는 함수
void DelayCount();								   // 3, 2, 1 카운트를 딜레이를 걸며 자동으로 세주는 함수
void ReturnToMapSelect();						   // 행동 종료 후 맵 선택화면으로 돌아오는 함수
void GameOver(int playerHp);					   // 게임이 오버 되었을 때 쓰는 함수
void GameClear(int loadCount);					   // 게임을 클리어 했을 때 쓰는 함수



// main() 함수
int main()
{
	// 변수 선언
	const int randomDiceRange = 10;	// 1 ~ 10의 값을 위한 범위

	int playertMaxHp = 100;			// 플레이어의 최대 체력
	int playerHp = playertMaxHp;	// 플레이어의 체력
	int playerDamage = 10;			// 플레이어의 공격력
	int heal = 10;

	int randomMapDice;			// 강 산 길을 가기 위한 주사위 값 저장 변수
	int randombattleOrHeal;		// 40%의 확률로 전투, 60%의 확률로 플레이어 회복
	
	int loadCount = 0;	// 길을 몇 번 걸었는지 확인하는 변수
	int mountCount = 0;	// 산을 몇 번 올랐는지 확인하는 변수
	int riverCount = 0; // 강을 몇 번 들렀는지 확인하는 변수

	int randomRiverEvent;		// 강에서 랜덤한 이벤트 확률을 저장하기 위한 변수

	int battleCount = 0; // 전투를 몇 번 했는지 확인하는 변수
	


	// 게임 시작 도입부
	StartGameCattle();
	printf("\t■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n\n");
	printf("\t※ 안내사항\n");
	printf("\t1. 콘솔 글꼴을 NSimsun으로 바꿔주세요\n");
	printf("\t2. 안내에 맞춰 천천히 키를 눌러주세요.\n\n\n");
	printf("\t■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n\n");
	printf("\t아무키나 눌러 게임을 시작하세요 ......");
	_getch();
	printf("\n\n\n게임을 시작합니다.\n");
	DelayCount();
	system("cls");

	// 맵 이동 (루프 시작)
	while (loadCount < 6)
	{
		// 게임의 메인 화면 (맵 선택화면)
		printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n\n");
		printf("■■ \t    게임목표! : 길을 6번 걸으시오		             \t\t\t■■\n\n");
		printf("■■ \t    ( 길을 걸은 횟수  [%d] ) ( 산에 오른 횟수  [%d] ) ( 강에 들린 횟수  [%d] )     ■■ \n\n", loadCount, mountCount, riverCount);
		printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n\n");
		printf("■■ \t\t\t\t  [1, 2, 3]       = 강                  \t\t■■\n");
		printf("■■ \t\t\t\t  [4, 5, 6, 7]    = 산                  \t\t■■\n");
		printf("■■ \t\t\t\t  [8, 9, 10]      = 길                  \t\t■■\n\n");
		printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n\n");
		printf("   \t\t전투한 총 횟수  [%d]  \t\t플레이어의 최대 체력  [%d]              \n\n", battleCount, playertMaxHp);
		printf("   \t\t플레이어의 공격력  [%d]         현재 플레이어의 체력  [%d]              \n\n", playerDamage, playerHp);
		printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
		printf("   \t\t\t      주사위를 굴려 맵을 이동합니다.			        \n\n");
		PrintDice();

		printf("\t\t\t  아무키를 누르면 주사위를 굴립니다.......\n");
		_getch();
		system("cls");

		// 주사위 굴리는 연출을 하는 함수
		RollTheDice();

		// 랜덤 값을 이용해 주사위를 굴림 1 ~ 10;
		srand(time(NULL));
		randomMapDice = (rand() % randomDiceRange) + 1;
		
		printf("\n\n\n\n");
		// 콘솔화면을 초기화함
		system("cls");	

		// 주사위의 값에 따라 맵 이동
		if (randomMapDice > 0 && randomMapDice <= 3)
		{
			// 주사위의 값이 1 ~ 3일 경우 강으로 갑니다.
			riverCount += 1;
			printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n\n");
			printf("나온 주사위 값 : ▨ %d ---------> 강으로 이동합니다.\n\n", randomMapDice);
			printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n\n");
			River_Art();
			printf("갈증을 견디지 못해 당신은 강의 물을 허겁지겁마십니다.\n\n");
			if (riverCount > 2)
			{
				printf("(물을 안마실 수는 없냐구요?... 네 ^^/) \n");
			}
			printf("아무키를 눌러 다음으로 ...\n");
			_getch();
			system("cls");

			// [강]에서 랜덤한 이벤트를 발생시킵니다.
			printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n\n");
			printf("강에 도착한 당신은 랜덤한 주사위의 값으로 스탯에 영향을 받습니다. \n\n");
			printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n\n");
			printf("주사위가 [1 ~ 3]이 나오면 [공격력 1] ▲ 증가시킵니다.\n\n");
			printf("주사위가 [4 ~ 5]이 나오면 [공격력 1] ▼ 감소시킵니다.\n\n");
			printf("주사위가 [6 ~ 7]이 나오면 [최대체력 5] ▲ 증가시킵니다.\n\n");
			printf("주사위가 [8 ~ 9]이 나오면 [최대체력 5] ▼ 감소시킵니다.\n\n");
			printf("주사위가 [10]이 나오면 그냥 지나갑니다.\n\n");
			printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n\n");

			printf("\t아무키나 눌러 주사위를 굴려보세요.");
			_getch();
			RollTheDice();
			randomRiverEvent = (rand() % randomDiceRange) + 1;

			printf("\n\n---------------------------------------------------------\n\n");
			printf("\t   ★☆★☆  주사위의 값은 %d  ★☆★☆\n", randomRiverEvent);
			printf("\n");
			if (randomRiverEvent >= 1 && randomRiverEvent <= 3)
			{
				printf("\t      [ 공격력이 1 ▲ 증가했습니다. ]\n\n");
				playerDamage += 1;

			}
			else if (randomRiverEvent >= 4 && randomRiverEvent <= 5)
			{
				printf("\t      [ 공격력이 1 ▼ 감소했습니다. ]\n\n");
				playerDamage -= 1;
			}
			else if (randomRiverEvent >= 6 && randomRiverEvent <= 7)
			{
				printf("\t      [ 최대체력이 5 ▲ 증가했습니다.] \n\n");
				playertMaxHp += 5;
			}
			else if (randomRiverEvent >= 8 && randomRiverEvent <= 9)
			{
				printf("\t      [ 최대체력이 5 ▼ 감소했습니다.] \n\n");
				playertMaxHp -= 5;
			}
			else
			{
				printf("        [ 스탯의 변화 없이 강을 통과했습니다. ]\n");
			}
			printf("\n---------------------------------------------------------\n");
			ReturnToMapSelect();
		}

		// 맵 선택 화면에서 주사위의 값이 3 ~ 7일 경우 산을 올라갑니다.
		else if (randomMapDice > 3 && randomMapDice <= 7)
		{
			printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n\n");
			printf("나온 주사위 값 : ▨ %d ---------> 산을 올라갑니다.\n\n", randomMapDice);
			printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n\n");
			Mountain_Art();

			mountCount += 1;

			// 전투를 할 것인가, 힐을 할 것인가 주사위를 굴려서 결정합니다.
			randombattleOrHeal = (rand() % randomDiceRange) + 1;
			printf("랜덤전투주사위의 값이 1 ~ 8일  경우 몬스터와 전투합니다.\n");
			printf("랜덤전투주사위의 값이 9 ~ 10일 경우 체력을 회복합니다.\n\n");
			printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n\n");
			printf("아무키를 눌러 주사위를 굴려보세요.");
			_getch();
			printf("\n\n★★★★★★★[  %d  ]★★★★★★★\n", randombattleOrHeal);
			Sleep(1500);
			system("cls");

			// 9, 10일 경우 힐 하는 로직
			if (randombattleOrHeal > 8)
			{
				printf("\n 플레이어는 잠시 쉬면서 경치를 바라봅니다.\n");
				printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
				printf(" ▲ 플레이어의 체력이 %d 회복되었습니다.\n", heal);

				playerHp = playerHp + heal;

				if (playerHp > playertMaxHp)
				{
					playerHp = playertMaxHp;
				}
				
				printf("현재 플레이어의 체력 : %d 입니다.\n\n", playerHp);

				MountainHeal_Art();

				ReturnToMapSelect();
			}

			// 나머지의 값일 경우 몬스터와 전투하는 로직
			else 
			{
				playerHp = MonsterBattle(playerHp, playerDamage);
				battleCount += 1;
				if (playerHp <= 0)
				{
					break;
				}
			}
		}

		// 맵 선택 화면에서 값이 8 ~ 10일 경우 (나머지 일 경우) 길을 걷는 로직
		else
		{
			loadCount += 1;
			printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n\n");
			printf("나온 주사위 값 : ▨ %d ---------> 길을 걷습니다.\n\n", randomMapDice);
			printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n\n");

			Load_Art();
			ReturnToMapSelect();
		}

		// 길을 6번 걸으면 게임이 클리어 됩니다.
		if (loadCount >= 6)
		{
			GameClear(loadCount);
		}

		// 플레이어의 체력이 0 이하라면 게임이 오버됩니다.
		if (playerHp <= 0)
		{
			break;
		}

	}
	


}	// main() 함수 끝

// 주사위를 굴리는 연출을 하는 로직
void RollTheDice()
{
	PrintDice();
	printf("\t\t\t        주사위를 굴립니다.\n");
	for (int i = 3; i > 0; i -= 1)
	{
		Sleep(500);
		printf("주사위 굴리는 중...... \t");
	}
}


// 몬스터와 전투하는 함수
int MonsterBattle(int playerHp, int playerDamage)
{
	// 몬스터의 종류는 박쥐, 곰, 슬라임
	int monsterBatHp = 20;
	int monsterBatDamage = 8;

	int monsterBearHp = 30;
	int monsterBearDamage = 10;

	int monsterSlimeHp = 15;
	int monsterSlimeDamage = 5;

	int randomSelectMonster;
	int randomSelectMonsterRange = 3;
	bool monsterAlive = false;

	printf("전투가 시작되었습니다.\n");
	
	// 랜덤 값을 이용해 등장하는 몬스터를 다르게 하는 로직
	srand(time(NULL));
	randomSelectMonster = (rand() % randomSelectMonsterRange) + 1;

	switch (randomSelectMonster)
	{
	// 랜덤 값이 1일 경우 박쥐와 전투하는 로직
	case 1:
		monsterAlive = true;
		printf("박쥐가 나타났습니다.\n\n");
		Bat_Art();
		printf("아무키나 눌러 공격하세요!!\n\n");
		_getch();
		system("cls");
		printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
		while (monsterAlive)
		{
			printf("박쥐에게 %d의 데미지를 입혔습니다.\n", playerDamage);
			printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
			monsterBatHp = monsterBatHp - playerDamage;
			Sleep(500);
			
			if (monsterBatHp <= 0)
			{
				printf("박쥐의 남은 체력 : 0\n\n");
				monsterAlive = false;
				Sleep(500);
				printf("박쥐를 처치했습니다!\n");
				printf("전투가 종료되었습니다\n\n");
				printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n\n");
				
				ReturnToMapSelect();
			}

			else
			{
				printf("박쥐의 남은 체력 : %d\n\n", monsterBatHp);
				Sleep(500);
				printf("박쥐가 당신을 공격했습니다!!\n");
				printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
				Sleep(500);
				printf("★★★ -8 ★★★\n");
				playerHp = playerHp - monsterBatDamage;
				Sleep(500);
				printf("당신의 현재 체력 : %d\n\n", playerHp);
				Sleep(500);

				// 전투를 진행하다 플레이어의 체력이 0이하가 되면 게임오버 함수를 불러오고 게임을 종료합니다.
				if (playerHp <= 0)
				{
					GameOver(playerHp);
					break;
				}
			}
		}
		break;

	// 랜덤 값이 2일 경우 곰과 전투합니다.
	case 2:
		monsterAlive = true;
		printf("야생의 곰이 나타났습니다.\n\n");
		Bear_Art();
		printf("아무키나 눌러 공격하세요!!\n\n");
		_getch();
		system("cls");
		printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
		while (monsterAlive)
		{
			printf("야생의 곰에게 %d의 데미지를 입혔습니다.\n", playerDamage);
			printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
			monsterBearHp = monsterBearHp - playerDamage;
			Sleep(500);
			

			if (monsterBearHp <= 0)
			{
				printf("야생의 곰의 남은 체력 : 0\n\n");
				monsterAlive = false;
				Sleep(500);
				printf("야생의 곰을 처치했습니다!\n");
				printf("전투가 종료되었습니다\n\n\n");
				printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n\n");

				ReturnToMapSelect();
			}

			else
			{
				printf("야생의 곰의 남은 체력 : %d\n\n", monsterBearHp);
				Sleep(500);
				printf("야생의 곰이 당신을 공격했습니다!!\n");
				printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
				Sleep(500);
				printf("★★★ -10 ★★★\n");
				playerHp = playerHp - monsterBearDamage;
				Sleep(500);
				printf("당신의 현재 체력 : %d\n\n", playerHp);
				Sleep(500);

				// 전투를 진행하다 플레이어의 체력이 0이하가 되면 게임오버 함수를 불러오고 게임을 종료합니다.
				if (playerHp <= 0)
				{
					GameOver(playerHp);
					break;
				}
			}
		}
		break;

	// 랜덤 값이 2일 경우 슬라임과 전투합니다.
	case 3:
		monsterAlive = true;
		printf("푸르댕댕 슬라임이 나타났습니다.\n\n");
		Slime_Art();
		printf("아무키나 눌러 공격하세요!!\n\n");
		_getch();
		system("cls");
		printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n");
		while (monsterAlive)
		{
			printf("푸르댕댕 슬라임에게 %d의 데미지를 입혔습니다.\n", playerDamage);
			printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
			monsterSlimeHp = monsterSlimeHp - playerDamage;
			Sleep(500);

			if (monsterSlimeHp <= 0)
			{
				printf("푸르댕댕 슬라임의 남은 체력 : 0\n\n");
				monsterAlive = false;
				Sleep(500);
				printf("푸르댕댕 슬라임을 처치했습니다!\n");
				printf("전투가 종료되었습니다\n");
				printf("■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■■\n\n");
				ReturnToMapSelect();
			}

			else
			{
				printf("푸르댕댕 슬라임의 남은 체력 : %d\n\n", monsterSlimeHp);
				Sleep(500);
				printf("푸르댕댕 슬라임이 당신을 공격했습니다!!\n");
				printf("ㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡㅡ\n");
				Sleep(500);
				printf("★★★ -5 ★★★\n");
				playerHp = playerHp - monsterSlimeDamage;
				Sleep(500);
				printf("당신의 현재 체력 : %d\n\n", playerHp);
				Sleep(500);

				// 전투를 진행하다 플레이어의 체력이 0이하가 되면 게임오버 함수를 불러오고 게임을 종료합니다.
				if (playerHp <= 0)
				{
					GameOver(playerHp);
					break;
				}
			}
		}
		break;
	}
	// 전투를 한 뒤 플레이어의 체력을 반환합니다.
	return playerHp;
}

// 게임 클리어 함수
void GameClear(int loadCount)
{
	if (loadCount >= 6)
	{
		system("cls");
		printf("★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆\n");
		printf("★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆\n");
		printf("★☆★☆★☆★☆★☆    길을 6번 걸었습니다! GAME CLEAR   ★☆★☆★☆★☆★☆★\n");
		GameClear_Art();
		printf("★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆\n");
		printf("★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆\n");
	}
}

// 게임오버 함수
void GameOver(int playerHp)
{
	if (playerHp <= 0)
	{
		system("cls");
		printf("＠＠＠＠＠＠＠＠＠＠＠＠＠＠＠＠＠＠＠＠＠＠＠＠＠＠＠＠＠＠＠＠＠＠\n");
		printf("＠＠＠＠＠＠＠＠＠＠＠＠＠＠＠＠＠＠＠＠＠＠＠＠＠＠＠＠＠＠＠＠＠＠\n\n");
		printf("＠＠＠＠＠           당신의 체력이 0이 되었습니다.    ＠＠＠＠＠＠＠\n");
		printf("＠＠＠＠＠                   GAME OVER                ＠＠＠＠＠＠＠\n");
		GameOver_Art();
		printf("＠＠＠＠＠＠＠＠＠＠＠＠＠＠＠＠＠＠＠＠＠＠＠＠＠＠＠＠＠＠＠＠＠＠\n");
		printf("＠＠＠＠＠＠＠＠＠＠＠＠＠＠＠＠＠＠＠＠＠＠＠＠＠＠＠＠＠＠＠＠＠＠\n");
	}
}

// 3, 2, 1 을 시간차로 출력하는 함수
void DelayCount()
{
	for (int i = 3; i > 0; i -= 1)
	{
		Sleep(750);
		printf("%d\n", i);
	}
}

// 분기가 끝나고 맵 선택으로 되돌아 갈때 사용하는 함수
void ReturnToMapSelect()
{
	printf("\n아무 키를 눌러 맵 선택 화면으로 되돌아가세요.\n");
	_getch();
	printf("\n잠시 후 맵 선택 화면으로 되돌아갑니다....\n");
	DelayCount();
	system("cls");
}

// 주사위의 이미지를 출력하는 함수
void PrintDice()
{
	printf("\t\t\t\t    ____			   \n");
	printf("\t\t\t\t   /\\' .\\    _____   \n");
	printf("\t\t\t\t  /: \\___\\  / .  /\\  \n");
	printf("\t\t\t\t  \\' / . / /____/..\\ \n");
	printf("\t\t\t\t   \\/___/  \\'  '\\  / \n");
	printf("\t\t\t\t            \\'__'\\/  \n");
}

// 시작화면의 성 이미지를 출력하는 함수
void StartGameCattle()
{
	printf("\n\n");
	printf("\t\t                             -|             |-\n");
	printf("\t\t         -|                  [-_-_-_-_-_-_-_-]                  |-\n");
	printf("\t\t         [-_-_-_-_-]          |             |          [-_-_-_-_-]\n");
	printf("\t\t          | o   o |           [  0   0   0  ]           | o   o |\n");
	printf("\t\t           |     |    -|       |           |       |-    |     |\n");
	printf("\t\t           |     |_-___-___-___-|         |-___-___-___-_|     |\n");
	printf("\t\t           |  o  ]              [    0    ]              [  o  |\n");
	printf("\t\t           |     ]   o   o   o  [ _______ ]  o   o   o   [     | ----__________\n");
	printf("\t\t_____----- |     ]              [ ||||||| ]              [     |\n");
	printf("\t\t           |     ]              [ ||||||| ]              [     |\n");
	printf("\t\t       _-_-|_____]--------------[_|||||||_]--------------[_____|-_-_\n");
	printf("\t\t      ( (__________------------_____________-------------_________) )\n");
	printf("\t\t                              Back  To  Home.");
	printf("\n\n");
}

// 길을 걸을 때 나오는 이미지를 출력하는 함수
void Load_Art()
{
	printf("\n\n");
	printf("\t\t    .    _    +     .  ______   .          .\n");
	printf("\t\t (      /|\\      .    |      \\      .   +\n");
	printf("\t\t     . |||||     _    | |   | | ||         .\n");
	printf("\t\t.      |||||    | |  _| | | | |_||    .\n");
	printf("\t\t   /\\  ||||| .  | | |   | |      |       .\n");
	printf("\t\t__||||_|||||____| |_|_____________\\__________\n");
	printf("\t\t. |||| |||||  /\   _____      _____  .   .\n");
	printf("\t\t  |||| ||||| ||||   .   .  .         ________\n");
	printf("\t\t . \\|`-'|||| ||||    __________       .    .\n");
	printf("\t\t    \\__ |||| ||||      .          .     .\n");
	printf("\t\t __    ||||`-'|||  .       .    __________\n");
	printf("\t\t   . _ ||||| . _               .   _________\n");
	printf("\t\t_   ___|||||__  _ \\\\--//    .          _\n");
	printf("\t\t     _ `---'    .)=\\oo|=(.   _   .   .    .\t\t 집에 돌아가자... \n");
	printf("\t\t_  ^      .  -    . \\.|\n");
	printf("\n\n");
}

// 산을 올랐을 때 나오는 이미지를 출력하는 함수
void Mountain_Art()
{
	printf("\n\n");
	printf("\t\t    .                  .-.    .  _   *     _   .	\n");
	printf("\t\t           *          /   \\     ((       _/ \\       *    .	\n");
	printf("\t\t         _    .   .--'\\/\\_ \\     `      /    \\  *    ___	\n");
	printf("\t\t     *  / \\_    _/ ^      \\/\\'__        /\/\  /\  __/   \\ *	\n");
	printf("\t\t       /    \\  /    .'   _/  /  \\  *' /    \/  \/ .`'\\_/\\   .	\n");
	printf("\t\t  .   /\\/\\  /\\/ :' __  ^/  ^/    `--./.'  ^  `-.\ _    _:\\ _	\n");
	printf("\t\t     /    \\/  \\  _/  \\-' __/.' ^ _   \\_   .'\\   _/ \ .  __/ \\	\n");
	printf("\t\t   /\\  .-   `. \\/     \\ / -.   _/ \\ -. `_/   \\ /    `._/  ^  \\	\n");
	printf("\t\t  /  `-.__ ^   / .-'.--'    . /    `--./ .-'  `-.  `-. `.  -  `.	\n");
	printf("\t\t@/        `.  / /      `-.   /  .-'   / .   .'   \\    \\  \\  .-  \\%	\n");

	printf("\n\n");
}

// 산에서 힐을 했을 때 나오는 이미지를 출력하는 함수
void MountainHeal_Art()
{
	printf("\n\n");
	printf("\t\t                            .-""""-                                   \n");
	printf("\t\t                           F   .-'                                    \n");
	printf("\t\t                          F   J                                       \n");
	printf("\t\t                         I    I                                       \n");
	printf("\t\t                          L   `.                                      \n");
	printf("\t\t                           L    `-._,                                 \n");
	printf("\t\t                            `-.__.-'            ##                    \n");
	printf("\t\t                                               ###\n");
	printf("\t\t                        #                      ####\n");
	printf("\t\t              _____   ##                 .---#####-...__             \n");
	printf("\t\t          .--'     `-###          .--..-'    ######     ""`---....   \n");
	printf("\t\t _____.----.        ###`.._____ .'          #######                  \n");
	printf("\t\t a:f                ###       /       -.    ####### _.---            \n");
	printf("\t\t                    ###     .(              #######                  \n");
	printf("\t\t                     #      : `--...        ######                   \n");
	printf("\t\t                     #       `.     ``.     ######                   \n");
	printf("\t\t                               :       :.    #####                   \n");

	printf("\n\n");
}

// 강을 들렀을 때 나오는 이미지를 출력하는 함수
void River_Art()
{
	printf("\t\t                              _____,,,\\//,,\\\\,/,	\n");
	printf("\t\t                             /-- --- --- -----					\n");
	printf("\t\t                            ///--- --- -- - ----				\n");
	printf("\t\t                           o////- ---- --- --					\n");
	printf("\t\t                           !!//o/---  -- --						\n");
	printf("\t\t                         o*) !///,~,,\\\\,\\/,,/,//,,				\n");
	printf("\t\t                           o!*!o'(\\          /\\						\n");
	printf("\t\t                         | ! o \", ) \\ / \\ / \\ / \\ / \\				\n");
	printf("\t\t                        o  !o! !!|    \\/  \\/     /					\n");
	printf("\t\t                        o o ! * !` | \\  /       \\						\n");
	printf("\t\t                           ' !o!':\\  \\\\        \\					\n");
	printf("\t\t                            ( ('|  \\  `._______/						\n");
	printf("\t\t////\\\\\\,,\\///,,,,\\,/oO._*  o !*!'`  `.________/					\n");
	printf("\t\t  ---- -- ------- - -oO*OoOo (o''|           /							\n");
	printf("\t\t-------  -- - ---- --* oO*OoO *!'| '         /							\n");
	printf("\t\t ---  -   -----  ---- - oO*OoO!!':o!'       /							\n");
	printf("\t\t - -  -----  -  --  - *--oO*OoOo!`         /		      여긴 어디 나는 누구...	\n");

	printf("\n\n");
}

// 길을 6번 걸어서 게임 클리어 할 때 나오는 이미지를 출력하는 함수
void GameClear_Art()
{
	printf("\n\n");
	printf("집에 도착했다...!");
	printf("\t\t\t      `'::::.			\n");
	printf("\t\t\t        _____A_			\n");
	printf("\t\t\t       /      /\\		\n");
	printf("\t\t\t    __/__/\\__/  \\___	\n");
	printf("\t\t\t---/__|\" \'\' \"| /___/\\----	\n");
	printf("\t\t\t   |''|\"\'||\'\"| |\' \'||		\n");
	printf("\t\t\t   |''|\"\'||\'\"| |\' \'||		\n");
	printf("\t\t\t   `\"\"`\"\"))\"\"`\"`\"\"\"\"`	\n");


	printf("\n\n");
}

// 게임 오버일때 나오는 이미지를 출력하는 함수
void GameOver_Art()
{
	printf("\t\t\t      ,-=-.   \n");
	printf("\t\t\t     /  +  \\  \n");
	printf("\t\t\t     | ~~~ |  \n");
	printf("\t\t\t     |R.I.P|  \n");
	printf("\t\t\t\\vV,,|_____|V,\n");
}

// 박쥐 이미지
void Bat_Art()
{
	printf("    =/\                 /\=			\n");
	printf("    / \\\'._   (\\_/)   _.\'/ \\			\n");
	printf("   / .\'\'._\'--(o.o)--\'_.\'\'. \\		\n");
	printf("  /.\' _/ |`\'=/ \" \\ = `|\\_ `.\\		\n");
	printf(" /` .\' `\;-,\'\\___/\',-;/` \'. \'\\		\n");
	printf("/.-\' jgs   `\\(-V-)/`       `-.\\				\n");
	printf("`            \"   \"            `				\n");
}
// 곰 이미지
void Bear_Art()
{
	printf("    ╭─────╮    \n");
	printf(" (O)│ ‾o‾ │(O) \n");
	printf("╭─╨─╯╔═══╗╰─╨─╮\n");
	printf("│ ╭╮╔╝   ╚╗╭╮ │\n");
	printf("╰─╯╔╝     ╚╗╰─╯\n");
	printf("   ╚╗     ╔╝   \n");
	printf("  ╭╯╚╗   ╔╝╰╮  \n");
	printf("  │ ╭╚═══╝╮ │  \n");
	printf("  ╰─╯     ╰─╯   \n");
}
// 슬라임 이미지
void Slime_Art()
{
	printf(" ╭────╮ \n");
	printf(" │\\_/│ \n");
	printf(" │    │ \n");
	printf("─┴────┴─\n");
	
}