// 구구단 출력하는 프로그램 만들기

#include <iostream>

int main()
{
	int lineCount[9] = { 0, }; // 1 ~ 9 까지
	int nDan[8] = { 0, };	// 2 ~ 9 까지


	for (int j = 0; j < 8; j++)
	{
		nDan[j] = j + 2;

		printf("%d 단\n", nDan[j]);

		for (int i = 0; i < 9; i++)
		{
			lineCount[i] = i + 1;
			printf("%d * %d = %d \n", nDan[j], lineCount[i], nDan[j] * lineCount[i]);
		}

		printf("\n");
	}
}