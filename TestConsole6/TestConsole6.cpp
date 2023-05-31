// 가위, 바위 보 함수 만들기
// 규칙
// 플레이어는 1, 2, 3 중에 하나를 입력 받는다.
// 컴퓨터는 숫자 2를 가지고 있다.
// 1은 가위, 2는 바위, 3은 보다.
// 플레이어의 입력에 따라 플레이어의 승리 혹은 패배를 출력한다.

#include <iostream>

int main()
{
    int playerNumber = 0;
    printf("가위바위보 게임.\n1, 2, 3 중에 하나를 입력하세요 : ");
    scanf_s("%d", &playerNumber);

    int computerNumber = 2;

    int scissors = 1;
    int rock = 2;
    int paper = 3;

    playerNumber == 3 ? printf("승리!") : playerNumber == 2 ? printf("비겼습니다.") : printf("패배!");
    return 0;
}
