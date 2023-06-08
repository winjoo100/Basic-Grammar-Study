// a, d, w, s 를 입력해서 배열에서 '0'을 움직여보기
// 테두리 끝에는 벽을 친다.
// 벽 밖으로는 나갈 수 없다.

#include <iostream>
#include <conio.h>

void Desc002();

int main()
{
	Desc002();
}

void Desc002()
{
	// 다차원 배열
	char char_[25] = { 0, };
	char movement = '0';
	char playerCharacter = '0';
	char wall = '#';
	int horizonCount = 3;
	int verticalCount = 3;
	char char2_[6][6] = { 0, };

	for (int i = 0; i < 25; i++)
	{
		char_[i] = '*';
	}

	while (true)
	{
		// 배열에 * 입력과정
		for (int y = 0; y < 6; y++)
		{
			for (int x = 0; x < 6; x++)
			{
				// 벽 만들기
				if (x == horizonCount && y == verticalCount)
				{
					char2_[y][x] = playerCharacter;
					continue;
				}
				char2_[y][x] = '*';

				if (y == 0 || y == 5)
				{
					char2_[y][x] = wall;
				}
				else if (x == 0 || x == 5)
				{
					char2_[y][x] = wall;
				}
			}
		}

		// 출력화면
		for (int y = 0; y < 6; y++)					// y가 행이고, x가 열이다.
		{
			for (int x = 0; x < 6; x++)
			{
				printf("%c ", char2_[y][x]);
			}
			printf("\n");
		}

		printf("\n");
		// 입력을 받아서 0이 움직이게 하기

		movement = _getch();


		if ((movement == 'a') || (movement == 'A'))
		{
			if (horizonCount >= 2)
			{
				horizonCount = horizonCount - 1;
			}
		}

		else if ((movement == 'd') || (movement == 'D'))
		{
			if (horizonCount <= 3)
			{
				horizonCount = horizonCount + 1;
			}
		}

		else if ((movement == 'w') || (movement == 'W'))
		{
			if (verticalCount >= 2)
			{
				verticalCount = verticalCount - 1;
			}
		}

		else if ((movement == 's') || (movement == 'S'))
		{
			if (verticalCount <= 3)
			{
				verticalCount = verticalCount + 1;
			}
		}


		system("cls");
	}
}