// 이름, 나이, 전화번호 출력하는 함수

#include <iostream>

int Age(int age)
{
    printf("나이 : %d세 \n", age);
    return age;
}

int main()
{
    printf("이름 : 백승주 \n");
    Age(20);
    printf("전화번호 : 010-1234-5678 \n");
}
