// 계산하는 함수를 만들어서 계산기 만들어보기 (실수 float)

#include <iostream>

float PlusNum(float num1, float num2)
{
    return num1 + num2;
}
float MinusNum(float num1, float num2)
{
    return num1 - num2;
}
float MulNum(float num1, float num2)
{
    return num1 * num2;
}
float DivNum(float num1, float num2)
{
    return num1 / num2;
}
int ModNum(int num1, int num2)
{
    return num1 % num2;
}

int main()
{
    float num1 = 12.4, num2 = 5;

    printf("덧셈 : %.1f + %.1f = %.1f\n", num1, num2, PlusNum(num1, num2));
    printf("뺄셈 : %.1f - %.1f = %.1f\n", num1, num2, MinusNum(num1, num2));
    printf("곱셈 : %.1f * %.1f = %.1f\n", num1, num2, MulNum(num1, num2));
    printf("나눗셈 : %.1f / %.1f = %.1f\n", num1, num2, DivNum(num1, num2));
    printf("나머지 : %.1f %% %.1f = %d\n", num1, num2, ModNum(num1, num2));
}

