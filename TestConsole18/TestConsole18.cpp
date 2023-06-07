// * * * * *
// 0 * * * *	-> 엔터를 누를 때 마다 0이 한 칸 씩 뒤로 밀립니다.
// - > * 0 * * *

#include <iostream>
#include <conio.h>
#include <Windows.h>

int main()
{
	char board[5] = { 0, };

	// * * * * * 찍기
	for (int a = 0; a < 5; a++)
	{
		board[a] = '*';
		printf("%c ", board[a]);
	}

	_getch();
	system("cls");

	// 0 * * * * 에서 오른쪽으로 0이 한칸씩 이동하기
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			board[j] = '*';
			if (j == i)
			{
				board[j] = '0';
			}
			printf("%c ", board[j]);
		}

		_getch();
		system("cls");
	}


}