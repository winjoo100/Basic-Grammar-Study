// 트럼프 카드 1장을 랜덤하게 뽑아서 출력하는 프로그램 만들기
// A, 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K

#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <time.h>

void RandomCardNum(int* myCard, char* myCard1);
void RandomCardShape(char* randomShape);

int main()
{
	int myCard = 0;
	char myCard1 = '0';
	char randomShape;

	srand(time(NULL));

	RandomCardNum(&myCard, &myCard1);
	RandomCardShape(&randomShape);
}

// 랜덤한 카드 뽑기
void RandomCardNum(int* myCard, char* myCard1)
{
	// 랜덤한 카드 번호 뽑기
	*myCard = rand() % 13 + 1;

	// 뽑은 카드 조작하기
	// myCard = 1;

	switch (*myCard)
	{
	case 1:
		*myCard1 = 'A';
		break;

	case 11:
		*myCard1 = 'J';
		break;

	case 12:
		*myCard1 = 'Q';
		break;

	case 13:
		*myCard1 = 'K';
		break;
	}


	if ((*myCard == 1) || (11 <= *myCard && *myCard <= 13))
	{
		printf("CardNumber = %c", *myCard1);
	}

	else
	{
		printf("CardNumber = %d", *myCard);
	}
}	// RandomCardNum()

// 랜덤한 문양 뽑기
void RandomCardShape(char* randomShape)
{
	int randomShapeNum = 0;
	randomShapeNum = rand() % 4 + 1;

	switch (randomShapeNum)
	{
	case 1:
		printf("\nCardShape = ♠");
		break;

	case 2:
		printf("\nCardShape = ◈");
		break;

	case 3:
		printf("\nCardShape = ♥");
		break;

	case 4:
		printf("\nCardShape = ♣");
		break;
	}
	
}	// RandomCardShape()
