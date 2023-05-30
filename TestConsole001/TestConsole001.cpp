// TestConsole001.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream> // #include는 전처리기 지시문 (#이 있으면 전처리기 지시문이구나 라고 생각하면 된다.)
#include <stdio.h>  // #include 안에 <, > 적어주는 .h 는 헤더파일, 추가로 <, > 안에는 주석을 달 수 없다.


void MyNewPrint(int number)                         // 함수를 만들어 보자. (1. 함수의 정의)
{
    printf("입력 값은 : %d 입니다. \n\n", number);
}

// 두 개의 수의 합을 구하는 함수
int PlusTwoNumbers(int number1, int number2)        
{
    printf("입력 값은 : %d, %d 입니다. \n", number1, number2);
    return number1 + number2;
}

// 미션! 세 개의 수의 곱을 구하는 함수
int MulThreeNumbers(int number1, int number2, int number3)
{
    printf("입력 값은 : %d, %d, %d, 입니다 \n", number1, number2, number3);
    return number1 * number2 * number3;
}

int main()
{
    int number = 10;

    printf("Hello Wolrd! \" \t\t\t");
    std::cout << "Hello World!\n";
    printf("Hello Wolrd! %d \n\n", number - 2);
    
    MyNewPrint(100);                                //실제로 함수를 사용하는 줄에서 함수를 부른다. call (2. 함수의 호출)
                                                    //100이란 값을 전달합니다. (3. 인자의 전달)

    printf("두 숫자의 합은 %d 입니다. \n\n", PlusTwoNumbers(5, 7));

    printf("세 숫자의 곱은 %d 입니다. \n\n", MulThreeNumbers(10, 20, 30));



    // Coment 주석 이 라인은 프로그램에 영향을 주지 않는다.
    // 내가 필요한 글자를 마음대로 적으면 된다.

    // 한줄주석이라고 한다.

    /*
    * 이걸 여러줄 주석이라고 한다.
    * 여러줄주석
    * 이 라인들은 프로그램에 영향을 주지 않는다.
    */

    //ctrl + l 라인 지우기, ctrl + 우클릭 단어 한글자 점프, 라인아무대서나 ctrl+c, ctrl+v 하면 라인 통째 복사가능
    //쉬프트 알트 + 아래방향키 => 여러줄을 똑같이 작성할 수 있음.

    //이스케이프 시퀀스 \n
    //변수와 함수를 구분하는 방법은 패턴을 잘 봐야함. ex(괄호가 있고 없고...)

    return 0;   // 리턴을 만나는 순간 함수는 종료.
}
