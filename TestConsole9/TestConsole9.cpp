//원의 반지름을 입력받아서 원의 넓이를 출력하는 프로그램 작성해보기
// - 함수를 사용할 것. 전방선언 해볼 것
// - 원의 반지름은 정수.
// 원의 넓이를 구하는 공식 => 원주율(π) × 반지름(r)2

#include <iostream>

// 함수 전방선언
void WidthCircle(float pi, int radius);

// 메인함수
int main()
{
	// { 변수 선언부
	const float PI = 3.141592f;
	int radius;
	// } 변수 선언부

	// { 사용자 입력을 받는 로직
	printf("반지름을 입력하세요 : ");
	scanf_s("%d", &radius);
	// } 사용자 입력을 받는 로직

	// { 실제 연산하는 함수
	WidthCircle(PI, radius);
	// } 실제 연산하는 함수
}

// { 원의 넓이를 구하는 함수
void WidthCircle(float pi, int radius)
{
	printf("원의 넓이: %f * (%d * %d) = %f \n", pi, radius, radius, pi * (radius * radius));
}
// } 원의 넓이를 구하는 함수