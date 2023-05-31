// 최대체력 = 50, 현재체력 = 20 인 상태에서 힐을 하는 함수

#include <stdio.h>

int DoHeal(int current_Hp, int heal)
{
	return current_Hp + heal;
}

int main()
{
	int maxHp = 50;
	int current_Hp = 20;

	printf("힐 받기 전 체력 : %d\n", current_Hp);

	int heal = 10000;

	int nowHp = DoHeal(current_Hp, heal);

	current_Hp = nowHp > maxHp ? maxHp : nowHp;


	printf("힐량 : %d\n", heal);
	printf("현재 체력 : %d\n", current_Hp);
}