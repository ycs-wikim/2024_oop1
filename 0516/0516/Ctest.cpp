#include "Ctest.h"

/*
* static 정리
* C언어 스타일
*  - 변수 : 한번만 초기화되며 전역 변수처럼 사용 가능
*  - 함수 : 선언된 소스 파일 외부에서 접근 불가
* 
* C++언어 스타일
*  - 변수/함수 : 클래스를 인스턴스화하지 않더라도 메모리에 존재
*/


/// 정적 멤버(static member) : 인스턴스 없이도 사용 가능
/// 비정적 멤버(Non-static member) : 인스턴스 없이 사용 불가능
int Ctest::m_public = 3;

void Ctest::Public()
{
	printf("public memeber\n");
}

void Ctest::Protected()
{
	printf("protedted memeber\n");
}

void Ctest::Private()
{
	printf("private memeber\n");
}
