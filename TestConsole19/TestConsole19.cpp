// 배열을 이용한 로또 번호 출력하기

#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <time.h>

void MyShuffle();
void DescriptionShuffle();
void ShuffleOnce(int* firstNumber, int* secondNumber);

int main()
{
    DescriptionShuffle();
    MyShuffle();
}

void DescriptionShuffle()
{
    // 1 ~ 45번 까지의 값을 numbers[] 배열에 넣음
    int numbers[45] = { 0, };
    for (int i = 0; i < 45; i++)
    {
        numbers[i] = i + 1;
    }

    // { 셔플 로직
    const int shuffleCount = 200;
    int randomIdx1, randomIdx2 = 0;
    srand(time(NULL));

    for (int i = 0; i < shuffleCount; i++)
    {
        randomIdx1 = rand() % 45;
        randomIdx2 = rand() % 45;
        ShuffleOnce(&numbers[randomIdx1], &numbers[randomIdx2]);
    }
    // } 셔플로직

    // { 배열의 출력
    printf("1등 로또 번호\n");
    for (int i = 0; i < 6; i++)
    {
        Sleep(500);
        printf("%d ", numbers[i]);
    }
    printf("\n");

    // } 배열의 출력

}   // DescriptionShuffle()

void ShuffleOnce(int* firstNumber, int* secondNumber)
{
    int temp = 0;
    temp = *firstNumber;
    *firstNumber = *secondNumber;
    *secondNumber = temp;
}   // ShuffleOnce()


void MyShuffle()
{
    const int lottoLange = 6;
    int lottoNum = 0;
    int numbers[6] = { 0, };

    srand(time(NULL));

    // 랜덤한 6개의 숫자 배열 안에 넣기
    for (int i = 0; i < lottoLange; i++)
    {
        lottoNum = rand() % 45 + 1;
        numbers[i] = lottoNum;

        // 중복된 넘버가 있다면 다시 랜덤 넘버를 넣기
        for (int j = 0; j < i; j++)
        {
            if (lottoNum == numbers[j])
            {
                lottoNum = rand() % 45 + 1;
                numbers[i] = lottoNum;
            }
        }

    }

    printf("\n다음주 1등 번호 뽑기\n");

    // 배열에 들어있는 6개의 숫자를 뽑아보기
    for (int i = 0; i < lottoLange; i++)
    {
        Sleep(500);
        printf("%d ", numbers[i]);
    }
}