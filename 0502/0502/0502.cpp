// 0502.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

/// 함수의 호출 방식
/// 1. call by value : 인수 값이 복사되어 별도 변수에 보관
/// 2. call by address : 인수 값이 포인터인 경우
/// 3. call by reference : 인수 값이 참조 변수인 경우

// 값이 복사되어 int a = x, int b = y
int call_by_value(int a, int b)
{
    //return a + b;
    a = 777;
    b = 888;
    return 3, a, b;
}

// int *p1 = &x, int *p2 = &y
int call_by_address(int* p1, int* p2)
{
    int ret = *p1 + *p2;
    *p1 = 777;  // x = 777
    *p2 = 888;  // y = 888
    return ret;
}

// int& a = x, int& b = y;
int call_by_reference(int& a, int& b)
{
    int ret = a + b;
    a = 7;
    b = 9;
    return ret;
}


int main()
{
    int x = 55, y = 77;
    printf("%d\n", call_by_value(x, y));
    printf("%d %d\n", x, y);
    printf("%d\n", call_by_address(&x, &y));
    printf("%d %d\n", x, y);
    printf("%d\n", call_by_reference(x, y));
    printf("%d %d\n", x, y);
}

#ifdef FUNCTION
/// 함수 : 기능을 사용자 정의로 만들어 놓은 것.
/// 함수 작성 방법
/// 1) 함수의 반환 값 : 함수 종료시 알려주는 자료형
/// 2) 함수의 이름 : 중복되지 않는 의미를 갖는 이름
/// 3) 함수의 인수 : 기능 동작을 위해 필요한 부가 정보
/// 4) 함수의 기능 : 어떠한 처리를 수행할 것인가
/// 5) 함수의 반환 값 : 함수 종료 시 알려주는 값
/// 예.
/// 1) 2) ( 3) )
/// {
///   4)
///   ...
///   5)
/// }
/// 
/// Ex) 두 값(int)을 더해서 반환(int)해주는 기능
/// 1. int
/// 2. Add
/// 3. int su1, int su2
/// 4. su1 + su2
/// 5. return su1 + su2; or return ret;



// 함수의 종료 : 함수의 실행 흐름 도중
//   return 키워드를 만나면 더 이상 실행하지 않는다.

// 함수의 원형(프로토타입)
//  - 컴파일러에게 이러한 함수가 있으니 참고해라.
// 함수의 몸체( {, } ) 전까지를 가져와서 ) 뒤에 ; 마무리
// 원형 작성시에는 변수 이름이 없어도 문제가 없다.
//int Add(int su1, int su2);
int Add(int, int);

// Add(3, 8)과 같이 호출하면 int su1 = 3, int su2 = 8
// 인수의 자료형과 변수명이 존재하기 때문에 일반 변수 선언과
// 동일하게 변수가 선언된다. ==> Add 함수의 스택에 보관
int Add(int su1, int su2)
{
    int ret;
    ret = su1 + su2;
    return ret;
}

int main()
{
    if (0)
        return -1;      // 실행되지 않으면 함수가 종료되지 않음.

    printf("%d\n", Add(3, 8));
    return 0;
}

#endif



#ifdef ASDF
typedef struct asdf
{
    int a;
    int b;
    int c;
} ASDF, *PASDF;


int main()
{
    ASDF a = { 19, 29, 39 };     // 구조체 변수
    PASDF ptr = &a;     // 구조체 포인터
    void* vp = ptr;     // void 포인터
    int* ip = (int*)vp;     // int 포인터
    printf("%d %d %d\n", ip[0], ip[1], ip[2]);
    std::cout << "Hello World!\n";
}
#endif