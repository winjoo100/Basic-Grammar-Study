
// 유저에게 정사각형의 사이즈를 입력 받아서
// '*'로 출력하는 프로그램 만들기
// - 유저 입력은 3이상 10이하 사이로만 입력한다.

// iostream 헤더파일
#include <iostream>

// 메인 함수 시작
int main()
{	
	// { 변수 선언부
	int sideLength;
	int horizoncount = 1;
	int verticalCount = 1;
	// } 변수 선언부

	// { 사용자 입력을 받는 로직
	printf("정사각형의 한 변을 입력하세요 : ");
	scanf_s("%d", &sideLength);
	// } 사용자 입력을 받는 로직

	// { 정사각형을 출력하는 로직
	while (sideLength >= verticalCount)
	{
		while (sideLength >= horizoncount)
		{
			printf("* ");
			horizoncount += 1;
		}

		verticalCount += 1;
		printf("\n");
		horizoncount = 1;
	}		// loop 루프 종료
	// } 정사각형을 출력하는 로직

	return 0; // 메인함수 종료
}	