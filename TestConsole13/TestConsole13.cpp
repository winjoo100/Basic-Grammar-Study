// 반복문 사용해서 User에게 아무 숫자나 입력 받는다.
// 그 숫자가 홀수면서 짝수인지 구별해서 출력하는 프로그램 만들기

#include <iostream>

void CheckOddEvenNumber(int userInputNumber);

int main()
{
	// 사용자 입력값을 1로 초기화
	int userInput = 1;

	// 사용자 입력값이 0보다 클 경우 반복
	while (userInput > 0)
	{
		// 사용자의 입력을 받는 로직
		printf("짝수, 홀수 판별기 입니다.\n숫자를 입력해주세요. 종료는 0 : ");
		scanf_s("%d", &userInput);

		// 사용자의 입력이 0일 경우 프로그램 종료
		if (userInput == 0)
		{
			printf("프로그램을 종료합니다.\n");
			break;
		}

		// 사용자의 입력이 0이 아닐 경우 짝수,홀수 판별
		CheckOddEvenNumber(userInput);
		userInput = 1;
		printf("\n");
	}
}
// 짝수와 홀수를 판별하는 함수
void CheckOddEvenNumber(int userInputNumber)
{
	if (userInputNumber % 2 == 0)
	{
		printf("입력하신 숫자는 %d, 짝수입니다.\n", userInputNumber);
	}
	else
	{
		printf("입력하신 숫자는 %d, 홀수입니다.\n", userInputNumber);
	}
}