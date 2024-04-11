// 0411.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//
#include <iostream>

// 전역 변수
int g_x = 9;
int g_y = 9;

int main()
{
	int a = 9;
	void* ap = &a;	// void* : 범용, 뭐든지 가능 ==> 보관용
	//ap++;	ap + 1;
	// ==> ap 자료형이 void이기 때문에 얼마나 이동해야 하는지에
	// 대한 정보가 없어서 모두 오류!!! ==> 자료형이 없어서...


	// 일반 변수
	int x = 9;
	printf("주소 : %p %p %p\n", &x, &g_x, &g_y);
	//char* cp = &x;		// char* = int* : 허용 불가
	// 포인터는 자료형이 다르면 메모리 접근에 문제 발생!
	// cp를 이용한 x의 접근은 1바이트씩 이루어진다.
	// 연산 시 의도하지 않은 문제가 발생
	char u = 65;
	//int* pu = &u;		// int* = char*
	// ==> 포인터에서는 자료형이 다르면 주소 대입이 불가능!
	// 프로그램에서 강제로 하지 못하도록 구성되어 있음.
	int* puu = (int*) & u;
	// 강제 형변환으로 자료형이 달라도 대입 가능!
	// 프로그래머가 정확하게 이해하고 적용하는 경우에만 사용!

	puu++;
#ifdef EX_2
	int k = 9;
	int* p = &k;
	//printf("K: %d %d %p\n", k, *k, &k);
	//  - 일반 변수는 앞에 *을 붙일 수 없다!
	printf("K: %d %p\n", k, &k);
	printf("P: %p %d %p\n", p, *p, &p);

	// 일반 변수에 &를 붙이면 * 1개를 얻는다.
	int* p1 = &k;		// * = *
	int** pp = &p1;		// ** = **
	int*** ppp = &pp;	// *** = ***
	int**** pppp = &ppp;
	int***** ppppp = &pppp;
	printf("K	: %d %p\n", k, &k);
	printf("p1	: %p %d %p\n", p1, *p1, &p1 );
	printf("p2	: %p %d %p %p\n", pp, **pp, &pp, *pp);
	printf("p3	: %p %d %p %p %p\n", ppp, ***ppp, &ppp, **ppp, *ppp);
	printf("p4	: %p %d %p %p %p %p\n", pppp, ****pppp,
		&pppp, ***pppp, **pppp, *pppp);
	//printf("p5	: %d\n", *****ppppp);
#endif

#ifdef EX_1
	/// 포인터 연산자
	/// 1. *	1) 선언	-> 바로 뒤 변수는 포인터
	///			2) 사용 -> 포인터가 가리키는 주소의 값
	/// 2. &	사용 -> 바로 뒤 변수의 주소
	int a = 8;
	int k = 9;			// 일반 변수의 선언
	int* p = nullptr;	// 포인터 변수의 선언
	//p = 3;		// 포인터는 값을 받을 수 없다!
	//k = &a;		// 일반 변수는 주소를 받을 수 없다!
	p = &k;		// 포인터는 주소 값만을 받는다!
	//int* p = &k;
	// p는 일반 변수처럼 공간을 가지고, 값은 k의 주소
	// 주소를 이용하면, 해당 위치의 값 접근이 가능
	//p = 3;		// 포인터 = 상수 입력 불가
	*p = 3;			// *p == k = 3
	printf("K: %d\n", k);

	int* ptr = &k;		// * = *
	int** pp = &ptr;		// ** = **
	int*** ppp = &pp;	// *** = ***
	int**** pppp = &ppp;
	int***** ppppp = &pppp;
	printf("K	: %d\n", k);
	printf("ptr	: %d\n", *ptr);	// *ptr == k
	printf("K	: %d\n", **pp);	// pp
	printf("K	: %d\n", ***ppp);
	printf("K	: %d\n", ****pppp);
	printf("K	: %d\n", *****ppppp);
#endif
}
