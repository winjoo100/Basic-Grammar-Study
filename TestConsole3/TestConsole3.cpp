// 데미지를 입력받아서 크리티컬 히트 데미지를 출력하는 함수
// 크리티컬 히트는 150 %

#include <iostream>

float CritDamage(float damage)
{
    return damage * 1.5;
}

int main()
{
    printf("크리티컬 데미지 : %f \n", CritDamage(100));
}
