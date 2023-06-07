
// 배열의 값을 셔플하는 프로그램 만들기

#include <iostream>
#include <time.h>
#include <Windows.h>

// 함수 전방선언
void DescriptionShuffle();
void ShuffleOnce(int* firstNumber, int* secondNumber);


int main()
{
    DescriptionShuffle();
}

void DescriptionShuffle()
{
    // 1~10까지의 숫자를 배열 numbers[]에 대입합니다.
    int numbers[10] = { 0, };
    for (int i = 0; i < 10; i++)
    {
        numbers[i] = i + 1;
    }

    // number[] 배열의 0번 인덱스부터 9번 인덱스까지 정수 10개를 출력합니다.
    printf("Shuffle 하기 전 \n\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", numbers[i]);
    }
    printf("\n\n");


    // 셔플 로직
    const int shuffleCount = 1000;  // 1000번 셔플
    int randomIdx1, randomIdx2 = 0; // 첫번째 수, 두번째 수를 저장할 변수

    srand(time(NULL));              // 랜덤 시드 변경

    // 셔플카운트 횟수만큼 셔플
    for (int i = 0; i < shuffleCount; i++)
    {
        randomIdx1 = rand() % 10;
        randomIdx2 = rand() % 10;
        ShuffleOnce(&numbers[randomIdx1], &numbers[randomIdx2]);
    }

    // 셔플한 뒤 배열 출력
    printf("Shuffle 한 후 \n\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");
}   // DescriptionShuffle()


// 한 번 셔플하는 함수
// 첫번째 변수와 두번째 변수의 값을 바꿉니다.
void ShuffleOnce(int* firstNumber, int* secondNumber)
{
    int temp = 0;
    temp = *firstNumber;
    *firstNumber = *secondNumber;
    *secondNumber = temp;
}   // ShuffleOnce()