
// 캐릭터 하나를 입력받아서 해당 문자가 특수문자인지 아닌지 체크해서 알려주는 프로그램 작성해보기
// - 대문자 알파벳 아니고, 소문자 알파벳 아니면 특수문자로 인정
// 65 ~ 90 대문자, 97 ~ 122 소문자, 그 외 특수문자
// 특수문자만 출력

#include <iostream>

// 전방 선언
void CharCheck(char playerInputNumber);
void CheckSpecialChar(char playerInputNumber);

// 메인함수
int main()
{
    // { 사용자 입력을 받는 로직
    char playerInputNumber;
    printf("문자 하나를 입력하세요 : ");
    scanf_s("%c", &playerInputNumber, 50);

    printf("\n입력하신 문자는 : %c", playerInputNumber);
    // } 사용자 입력을 받는 로직

    // { 문자를 판별해주는 로직
    CharCheck(playerInputNumber);
    CheckSpecialChar(playerInputNumber);
    // } 문자를 판별해주는 로직
}

// 특수 문자인지 아닌지 판별
void CharCheck(char playerInputNumber)
{
    (playerInputNumber > 64 && playerInputNumber < 91) ? printf("\n%c 는 대문자입니다.\n", playerInputNumber) :
        (playerInputNumber > 96 && playerInputNumber < 123) ?
        printf("\n%c 는 소문자입니다.\n", playerInputNumber) : printf("\n%c 는 영문자가 아닙니다.\n", playerInputNumber);
}

// 특수 문자만 출력
void CheckSpecialChar(char playerInputNumber)
{
    ((playerInputNumber >= '!' && playerInputNumber <= '/') || (playerInputNumber >= ':' && playerInputNumber <= '?') ||
        (playerInputNumber >= '[' && playerInputNumber <= '`') || (playerInputNumber >= '{' && playerInputNumber <= '~')) ?
        printf("\n%c 는 특수문자입니다.\n", playerInputNumber) : printf("\n%c 는 특수문자가 아닙니다.\n", playerInputNumber);
}