
// 자료형의 크기를 출력해보자!

#include <iostream>

int main()
{
    // 정수형 데이터 타입들
    char charValue = 'A';             // char   =   문자 하나를 저장하기 위한 데이터 타입
    short shortValue = 10;            // short  =   int 보다 작은 수를 저장하기 위한 데이터 타입
    int intValue = 100;               // int    =   가장 만만한 수를 저장하기 위한 데이터 타입
    long longValue = 200;             // long   =   int가 커져서 이제 잘 안쓰는 데이터 타입
    long long longLongValue = 1000;   // longlong = int보다 큰 수를 저장하기 위한 데이터 타입

    // 실수형 데이터 타입들
    float floatValue = 10.1;                // float    =    가장 만만한 실수를 저장하기 위한 데이터 타입
    double doubleValue = 100.1;             // double   =    float보다 큰 실수를 저장하기 위한 데이터 타입
    long double longDoubleValue = 200.1;    // long double = double 보다 큰 실수를 저장하기 위한 데이터 타입

    printf("char 의 크기는? %d byte. \n", sizeof(char));
    printf("short의 크기는? %d byte. \n", sizeof(shortValue));
    printf("int  의 크기는? %d byte. \n", sizeof(intValue));
    printf("long 의 크기는? %d byte. \n", sizeof(longValue));
    printf("long long 의 크기는? %d byte. \n\n", sizeof(longLongValue));

    printf("float  의 크기는? %d byte. \n", sizeof(float));
    printf("double 의 크기는? %d byte. \n", sizeof(double));
    printf("long double 의 크기는? %d byte. \n", sizeof(long double));
}
