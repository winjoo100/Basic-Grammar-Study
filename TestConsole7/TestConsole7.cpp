
// 정수 3개를 입력받아서 x+y*z 의 결과를 출력하는 프로그램 작성해보기
// - 입력은 scanf_s를 쓰고, 한 라인에서 3개의 입력을 받는다.
// - 함수를 활용한다.
// - 사칙연산 순서에 유의할 것


#include <iostream>

// 함수 전방 선언
int CalculationThreeNumbers(int x, int y, int z);
int DeformCalculationThreeNumbers(int x, int y, int z);

// 메인 함수 시작
int main()
{
    // { 변수 선언부
    int num1, num2, num3;
    int result, deFormResult;
    // } 변수 선언부

    // { 사용자 입력받는 로직
    printf("정수 3개를 입력하세요 (숫자 숫자 숫자) : ");
    scanf_s("%d %d %d", &num1, &num2, &num3);
    // } 사용자 입력받는 로직

    // { 실제 연산하는 로직
    result = CalculationThreeNumbers(num1, num2, num3);
    deFormResult = DeformCalculationThreeNumbers(num1, num2, num3);
    // } 실제 연산하는 로직

    // { 계산 결과 출력
    printf("\n계산 결과\n");
    printf("%d + %d * %d = %d\n", num1, num2, num3, result);
    // } 계산 결과 출력

    // { 변형 계산식 출력
    printf("\n변형계산식\n");
    printf("(%d - %d) * (%d + %d) * (%d %% %d) = %d\n", num1, num2, num2, num3, num3, num1, deFormResult);
    printf("%d * %d * %d = %d\n", (num1 - num2), (num2 + num3), (num3 % num1), deFormResult);
    // } 변형 계산식 출력
}

// 정수 3개를 입력받아서 계산하는 함수
int CalculationThreeNumbers(int x, int y, int z)
{
    return x + y * z;
}

// 변형 계산식
int DeformCalculationThreeNumbers(int x, int y, int z)
{
    return (x - y) * (y + z) * (z % x);
}






