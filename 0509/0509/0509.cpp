// 0509.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

/// 함수의 중복 정의(C++)
///  : 동일한 이름을 사용하는 함수를 여러개 만들어서 사용하는 방법
///     : 중복 정의가 가능하게 하는 원인은 인수의 자료형!!!
///     : 인수 자료형과 인수의 개수에 따라 중복 선언 가능!
/// sum_int, int_sum, char_sum, sum_char
int sum(int x, int y)
{
    return x + y;
}

int sum(int x)
{
    return x + 10;
}
/*
/// 함수의 반환 값은 함수를 구분하는데 사용되지 않는다.
char sum(int x, int y)
{
    return x + y;
}
*/

char sum(char x, char y)
{
    return x + y;
}

int sum(char x, int y)
{
    return x + y;
}


void fff(short arg)     // 2byte
{
    printf("short: %d\n", arg);
}

void fff(int arg)       // 4byte
{
    printf("int: %d\n", arg);
}

int main()
{
    fff((short)86);    // short? int?
    printf("%d %d %d\n", sum(3, 8), sum('A', 'B'),
        sum('A', 3));
}


#ifdef __ex
/// 가변인수 사용을 위해 포함해야하는 헤더 파일
#include <stdarg.h>

/// 가변인수 적용 함수의 선언 : 마지막에 ... 입력
void VFFunc(int arg1, int arg2, ...)
{
    /// 가변인수를 별도로 접근하기 위한 자료형 선언
    va_list arg_ptr;
    /// 가변인수 접근을 시작
    va_start(arg_ptr, arg2);

    /// va_arg( ) 현재 위치의 가변인수의 값을 가져온다.
    double varg3 = va_arg(arg_ptr, double);
    char varg4 = va_arg(arg_ptr, char);
    char* varg5 = va_arg(arg_ptr, char*);
    /// 가변인수 접근을 종료
    va_end(arg_ptr);

    cout << arg1 << endl;
    cout << arg2 << endl;
    cout << varg3 << endl;
    cout << varg4 << endl;
    cout << varg5 << endl;
}

int main()
{
    VFFunc(1, 2);
    VFFunc(1, 2, 3.0, '4', "Five");
}
#endif

#ifdef EX__
/// 기본 인자 : 함수 인수의 값을 지정하지 않으면 자동 입력되는 인자
///     ==> 함수 선언부에 자동 입력될 값을 대입식으로 표현
///     ==> 인자 값이 없는 경우에 대입되는 값이다.
///     ==> 인자 값을 잘 모를경우, 사용하는 것이 좋다.
///     ==> 기본 인자를 const로 선언하면 반드시 값을 주어야 한다.
///     ==> 기본 인자가 여러 개인 경우는 반드시 다 값을 써야만 특정 위치에 값입력이 가능
///     ==> 기본 인자는 인자의 끝부분에 사용한다.
///     ==> 함수 원형에만 기본 인자를 표시, 구현 시에는 기본 인자 표시를 제거

int addd(int x = 8);

/// int addd(int x) : 함수 선언을 통해 일반 인자 선언
/// 대입식으로 자동 입력될 값을 지정하는 인자 선언
int addd(int x)
{
    return x + 10;
}

/// 기본인자가 포함된 함수의 호출 방법
/// 1. addd1( 10, 10 )  : 값을 다 주고 호출
/// 2. addd1( 10 ) : y 값을 생략하고 호출
int addd1(int x, int y = 100)
{
    return x + y;
}

/// 1. addd2( 1, 2, 3 )
/// 2. addd2( 1, 2 )
int addd2(int x, int y, int z = 100)
{
    return x + y + z;
}

/// 1. addd3( 1, 2, 3 )
/// 2. addd3( 1, 2 )
/// 3. addd3( 1 )
int addd3(int x, int y = 8, int z = 100)
{
    return x + y + z;
}

int addd4(int x, int y, int z = 100)
{
    return x + y + z;
}


int main()
{
    //printf("%d %d %d\n", addd4(90, 80));
    printf("%d %d %d\n", addd3(8), addd3(10, 10), addd3(8, 7, 9));
    printf("%d %d\n", addd2(10, 10), addd2(8, 7, 9));
    printf("%d %d\n", addd1(10, 10), addd1(8));
    std::cout << "Hello World!\n" << addd() << std::endl;
}
#endif