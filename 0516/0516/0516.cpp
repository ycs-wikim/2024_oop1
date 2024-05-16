// 0516.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
using namespace std;

/// C++에서는 하나의 파일에 여러 클래스 선언과 사용이 가능

class CFamily       /// C를 붙이는 것은 C++에서 관용적 표현
{
/// 관계(상속)가 있는 클래스에서 접근이 가능한 권한
/// 인스턴스(객체)화 되었을 때, 외부에서 접근 및 사용 불가
protected:
    /// 정보
    char* m_FamilyName;     /// m_ ==> member_

/// 누구나 접근 및 사용이 가능한 권한
public:
    /// 기능
    void SetFamilyName(char* arg)
    {
        m_FamilyName = arg;
        //m_FamilyName[0] = 'A';
    }
};

/// CFmaily 클래스를 상속 받아 사용하는 CName 클래스 선언
/// 상속할 때에도 권한을 줄 수 있다.
/// 상속되면, CFamily의 private 멤버를 제외한 모든 멤버 접근 및 사용 가능
/// CName이 객체화 되었을때도 CFamily의 public 멤버 접근 및 사용 가능
class CName : public CFamily
{
/// 나(CName 클래스)만 접근 및 사용이 가능한 권한
//private:      // C++에서는 권한을 주지 않으면 자동으로 private 권한
    const char* m_Name;
public:         // 한번 써주면 다른 권한이 나타날 때까지 지속적으로 적용
    int x;

    /// 클래스 선언에 메서드의 원형만 존재하는 경우.
    /// 반드시 어디에선가 메서드를 구현해야 함.
    /// 즉, 클래스 내부( {, } )가 아닌 외부에 메서드를 구현!
    void SetName(const char* arg);

    void ShowName()
    {
        cout << m_FamilyName << " " << m_Name << endl;
    }
};

void SetName(const char* arg)
{
    printf("%s called\n", __FUNCTION__);
}

/// 클래스 외부에서 내부의 멤버를 정의하는 방법
/// 클래스이름::(범위지정 연산자)멤버이름
/// 멤버가 변수라면 값을 입력하고, 함수라면 함수를 구현.
void CName::SetName(const char* arg)
{
    m_Name = arg;
}

#include "Ctest.h"

void main()
{
    Ctest ct;
    /// 인스턴스 : 메모리에 적재된다.
    ct.m_public = 9;
    ct.Public();

    CName name;
    SetName("asdf");
    name.SetFamilyName((char*)"Kim");       // 1
    name.SetName("Do Hyung");               // 2
    name.ShowName();
}




#ifdef EX__
/// 클래스 선언 : 예약어 클래스이름{ 멤버 변수; .. ; 멤버 함수; .. };
class ASDF      /// C++에서는 구조체 == 클래스
{
public:
    /// 멤버 변수 : 자료구조
    int x;
    int y;
    /// 멤버 함수(메서드) : 알고리즘
    void printX()
    {
        printf("X: %d\n", x);
        printY();
    }
private:
    void printY()
    {
        printf("Y: %d\n", y);
    }
};



int main()
{
    ASDF a;     // 클래스의 인스턴스화(객체화)
    a.printX();
    std::cout << "Hello World!\n";
}
#endif