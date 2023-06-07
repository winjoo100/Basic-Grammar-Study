// 문자열을 입력받아서 대문자 - 소문자 - 대문자 - 소문자, ..
// 순으로 수정해서 출력하는 프로그램 작성하기 (Easy)
// 위의 프로그램을 수정해서 거꾸로 뒤집어서 출력하는 프로그램 작성하기 (Normal)
// 65 ~ 90 대문자, 97 ~ 122 소문자

#include <iostream>

int main()
{
    int ex = 0;                         // 특수 문자가 입력 됬는지 구분하기 위한 변수
    char string_BigSmall[100] = { 0, }; // 

    printf("영어문자열을 입력하시오 : ");
    std::cin >> string_BigSmall;        // 문자열을 받아서 string_BigSmall[] 에 대입합니다.

    for (int i = 0; i < 100; i++)       
    {
        // 특수문자인지 영문자인지 판단
        if ((string_BigSmall[i] >= 97 && string_BigSmall[i] <= 122) || (string_BigSmall[i] >= 65 && string_BigSmall[i] <= 90))
        {
            // 소문자면 대문자로 바꾸기
            if (string_BigSmall[i] >= 97 && string_BigSmall[i] <= 122)
            {
                //해당 인덱스가 몇 번째에 있는지? 짝수 번째라면 소문자를 대문자로 바꿉니다.
                if ((i + ex) % 2 == 0)
                {
                    string_BigSmall[i] = string_BigSmall[i] - 32;
                }

            }

            // 대문자면 소문자로 바꾸기
            else if (string_BigSmall[i] >= 65 && string_BigSmall[i] <= 90)
            {
                //해당 인덱스가 몇 번째에 있는지? 홀수 번째라면 소문자를 대문자로 바꿉니다.
                if ((i + ex) % 2 != 0)
                {
                    string_BigSmall[i] = string_BigSmall[i] + 32;
                }
            }
        }
        // 특수문자면 ex 변수를 1 증가시켜서 특수문자 다음에 (대문자_대문자, 소문자_소문자)가 되는 것을 방지함.
        // 즉, (대문자_소문자, 소문자_대문자)가 되게끔 함.
        else
        {
            ex += 1;
        }
    }

    printf("\n대소문자 변경 후 %s\n", string_BigSmall);

    printf("\n문자의 순서를 반대로 출력해보기");
    for (int i = 99; i >= 0; i--)
    {
        printf("%c", string_BigSmall[i]);
    }

    printf("\n\n");
}