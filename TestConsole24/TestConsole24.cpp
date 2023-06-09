// 슬라이딩 게임 퍼즐만들기
// 사용자로부터 3 ~ 6 사이의 수를 입력받아서 행렬(2차원배열)을 만들기
// 절대 클리어 못하게 되는 것을 방지하는 코드는 추후에 추가해야함

#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <time.h>

void UserInput();

int main()
{
	UserInput();
}

void UserInput()
{
	int x, y = 0;
	int userNum = 1;					// 사용자로부터 행렬의 크기를 입력받는 값
	int slideGame[6][6] = { 0, };		// 최대 [6][6]이기 때문에 그보다 적게 쓰면 6을 입력받았을 때 크기가 초과된다.
	int gameClearCheck[6][6] = { 0, };	// 1 ~ 끝자리 까지 차례로 넣어 랜덤된 게임판과 비교할 수 있는 배열
	int numBlank = 0;					// 배열의 마지막 숫자를 
	int numCount = 1;

	while (userNum != 0)
	{
		// 게임판의 크기를 [3][3] ~ [6][6]의 사용자 입력값을 받기
		printf("행렬을 몇 줄로 하실 건지 입력하세요 (3 ~ 6 사이의 값, 0 => 게임종료) : ");
		scanf_s("%d", &userNum);

		if (3 <= userNum && userNum <= 6)
		{
			// 배열에 숫자 입력과정
			for (int y = 0; y < userNum; y++)
			{
				for (int x = 0; x < userNum; x++)
				{
					// 끝에 빈칸 만들기
					if ((x == (userNum - 1)) && (y == (userNum - 1)))
					{
						slideGame[y][x] = numBlank;
						continue;
					}

					// 나머지엔 숫자 채우기
					slideGame[y][x] = numCount;
					gameClearCheck[y][x] = numCount;
					numCount += 1;
				}
			}

			// 배열을 랜덤하게 셔플하기
			srand(time(NULL));
			int index1, index2 = 0;
			int shuffleCount = 0;
			int nTemp = 0;

			while (shuffleCount < 50)
			{
				for (int i = 0; i < userNum; i++)
				{
					for (int j = 0; j < userNum; j++)
					{
						index1 = rand() % userNum;
						index2 = rand() % userNum;

						nTemp = slideGame[index1][index2];
						slideGame[index1][index2] = slideGame[i][j];
						slideGame[i][j] = nTemp;
					}
				}

				shuffleCount += 1;
			}

			// 0의 자리를 찾아서 배열의 맨 마지막으로 이동시키기
			for (int i = 0; i < userNum; i++)
			{
				for (int j = 0; j < userNum; j++)
				{
					if (slideGame[i][j] == numBlank)
					{
						nTemp = slideGame[i][j];
						slideGame[i][j] = slideGame[userNum - 1][userNum - 1];
						slideGame[userNum - 1][userNum - 1] = nTemp;
					}
				}
			}

			// a, d, w, s를 입력받아서 자리바꾸기
			char inputADWS = '0';
			int verticalCount = userNum - 1;
			int horizonCount = userNum - 1;
			int gameClearCount = 0;

			while (1)
			{
				// 게임 클리어를 위한 로직 (모든 배열의 요소를 비교한뒤 true의 갯수가 사용자 입력값의 제곱과 같다면 성공
				bool gameClear = false;
				int ClearCount = 0;

				for (int y = 0; y < userNum; y++)
				{
					for (int x = 0; x < userNum; x++)
					{
						if (slideGame[y][x] == gameClearCheck[y][x])
						{
							ClearCount += 1;

							if (ClearCount >= userNum * userNum)
							{
								printf("축하합니다. 클리어하셨습니다!!\n");
								_getch();
								gameClear = true;
								break;
							}
						}
					}
				}
				ClearCount = 0;
				if (gameClear == true)
				{
					break;
				}

				printf("\n정답 미리보기\n");
				// 출력화면
				for (int y = 0; y < userNum; y++)					// y가 행이고, x가 열이다.
				{
					for (int x = 0; x < userNum; x++)
					{
						printf("%4d", gameClearCheck[y][x]);
					}
					printf("\n");
				}

				printf("\n현재 행렬의 크기 : %d\n\n", userNum);
				// 출력화면
				for (int y = 0; y < userNum; y++)					// y가 행이고, x가 열이다.
				{
					for (int x = 0; x < userNum; x++)
					{
						printf("%4d", slideGame[y][x]);
					}
					printf("\n");
				}

				printf("\nQ를 입력하면 게임 종료.");
				printf("\n[a←], [d→], [w↑], [s↓] 를 입력해서 0의 위치를 이동하세요\n");
				inputADWS = _getch();

				if (inputADWS == 'a' || inputADWS == 'A')
				{
					if (horizonCount > 0)
					{
						// 0과 스왑
						nTemp = slideGame[verticalCount][horizonCount];
						slideGame[verticalCount][horizonCount] = slideGame[verticalCount][horizonCount - 1];
						slideGame[verticalCount][horizonCount - 1] = nTemp;

						horizonCount -= 1;
					}

				}
				else if (inputADWS == 'd' || inputADWS == 'D')
				{
					if (horizonCount < userNum - 1)
					{
						// 0과 스왑
						nTemp = slideGame[verticalCount][horizonCount];
						slideGame[verticalCount][horizonCount] = slideGame[verticalCount][horizonCount + 1];
						slideGame[verticalCount][horizonCount + 1] = nTemp;

						horizonCount += 1;
					}
				}
				else if (inputADWS == 'w' || inputADWS == 'W')
				{
					if (verticalCount > 0)
					{
						// 0과 스왑
						nTemp = slideGame[verticalCount][horizonCount];
						slideGame[verticalCount][horizonCount] = slideGame[verticalCount - 1][horizonCount];
						slideGame[verticalCount - 1][horizonCount] = nTemp;

						verticalCount -= 1;
					}
				}
				else if (inputADWS == 's' || inputADWS == 'S')
				{
					if (verticalCount < userNum - 1)
					{
						// 0과 스왑
						nTemp = slideGame[verticalCount][horizonCount];
						slideGame[verticalCount][horizonCount] = slideGame[verticalCount + 1][horizonCount];
						slideGame[verticalCount + 1][horizonCount] = nTemp;

						verticalCount += 1;
					}
				}
				else if (inputADWS == 'q' || inputADWS == 'Q')
				{
					printf("\n게임을 종료합니다.\n");
					break;
				}
				system("cls");
			}
			break;
		}
		else if (userNum == 0)
		{
			printf("게임을 종료합니다.\n");
			break;
		}

		else
		{
			printf("다시입력하세요.\n");
		}
	}
}