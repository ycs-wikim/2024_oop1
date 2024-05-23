// 0523.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

/// 생성자/소멸자 모두 반드시 public 권한으로 설정되어야 함!
/// 생성자 : 클래스가 인스턴스화 될때 자동으로 호출되는 함수
///     생성 방법 : 반환 값을 표기하지 함수. 함수명은 클래스 이름으로 고정

/// 소멸자 : 인스턴스가 해제/소멸 될때 자동으로 호출되는 함수
///     생성 방법 : 반환 값을 표기하지 함수. 함수명은 클래스 이름으로 고정
///                 함수 이름 앞에 ~를 붙인다.
class CTEST
{
public:
    CTEST()
    {
        printf("생성자 호출\n");
    }
    ~CTEST()
    {
        printf("소멸자 호출\n");
    }
    void asdf();
};

void main()
{
    CTEST c;
    
}


#ifdef ____EX
class Ctest
{
public:
    int m_x;
    /// 멤버 변수의 상수화
    const int m_c = 90;
    /// 멤버 함수의 상수화
    /// const 멤버 함수 : 멤버 변수의 값 변경 불가능!
    ///const void exe() // 변수에서 const를 사용하는 방식
    void exe() const    // 함수에서 const를 사용하는 방식
    {
        int kkk = 90;   /// const 함수 내부에서 선언된 일반 변수
        kkk += m_x;     /// 값의 변경이 발생해도 전혀 문제가 없음!
                        /// 멤버 변수 값을 변경할 수 없음이지, 사용할 수 없음은 아님!
        /// 일반 멤버 변수라 할지라도 모두 상수화 되어 처리
        //m_x = 66;
        printf("%s [ %d : %d ]\n", __FUNCTION__, m_x, kkk);
    }
};

void main()
{
    Ctest c;
    c.exe();        // 66
    c.m_x = 80;     // 80
    c.exe();
}
#endif


#ifdef __EX
class Parent
{
public:
    int m_member = 90;
};

class Child : public Parent
{
public:
    int m_member = 80;

    /// this : 클래스가 인스턴스화(객체화)되었을때, 자기 자신을 가리키는 포인터
    /// 클래스 내부의 메서드(멤버 함수)에서만 this가 동작한다.
    void getMember()
    {
        /// 상속 받은 부모와 같은 멤버 변수를 사용하는 경우.
        /// 1. 이름을 그대로 사용 : 자신의 멤버가 사용
        /// 2. this를 통해 접근 : 자신의 멤버를 정확하게 기재
        /// 3. ::(범위 지정 연산자) 사용 : 특정 클래스의 멤버 사용 가능
        printf("getMember[ %p ] : %d %d %d\n", this,
            m_member, this->m_member, Parent::m_member );
        /// this는 별도로 값을 할당할 수 없다!
        //this = NULL;
    }
};


class CTest
{
public:
    /// 정적 멤버 변수 : 인스턴스 생성과 관계 없이 무조건 메모리에 적재
    ///     CTest의 모든 인스턴스 내에서 접근할 때 하나만! 보인다.
    ///     정적 멤버 변수는 모든 인스턴스에서 하나만 존재!
    static int m_Value;     // 외부 정의 필요!
    void Func()
    {
        printf("%d\n", m_Value);
    }
    /// 정적 멤버 함수 : 인스턴스 생성과 관계 없이 무조건 메모리에 적재
    ///     클래스의 인스턴스와 관계 없이 호출 가능!
    ///     제약 : 내부에서 사용되는 멤버 변수는 반드시 정적 멤버만 가능!
    static void SFunc()
    {
        /// 클래스를 가리키는 this라고 할지라도 정적 멤버 함수에서는 접근/사용 불가
        //printf("THIS[ %p ]\n", this);
        printf("%d\n", m_Value);
    }
};

int CTest::m_Value = 6;


int main()
{
    /// 정적 멤버 함수는 인스턴스가 없어도 호출/사용이 가능!
    CTest::SFunc();
    printf("\n\n\n");

    /// CTest 객체 4개 생성
    CTest c1, c2, c3, c4;
    /// 정적 멤버 변수/함수 정보 확인
    c1.Func();
    c2.Func();
    /// 정적 멤버 변수의 값 수정
    c1.m_Value = 77;
    /// 동일한 값을 출력 : 정적 멤버 변수는 1개만 존재!
    c1.Func();
    c2.Func();
    /// 각 인스턴스의 주소 출력 ==> 모두 다름
    printf("%p %p %p %p\n", &c1, &c2, &c3, &c4);
    /// 각 인스턴스의 정적 멤버의 주소 출력 ==> 모두 같다!!!
    printf("%p %p %p %p\n", &c1.m_Value, &c2.m_Value, &c3.m_Value, &c4.m_Value);

    Child a, b, c, d;
    a.getMember();
    b.getMember();
    c.getMember();
    d.getMember();
    printf("Class Address : %p %p %p %p\n", &a, &b, &c, &d);
    std::cout << "Hello World!\n";
}
#endif
