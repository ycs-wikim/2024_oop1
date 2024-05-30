// 0530.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

/// 생성자와 소멸자로 확인한 메모리 생성/해제 순서
/// 생성 순서 : 상속된 클래스가 먼저 생성되고, 상속 받은 클래스가 나중에 생성
///     ==> 상위 클래스 정보를 사용하기 위해 먼저 생성!
/// 소멸 순서 : 상속 받은 클래스가 먼저 소멸, 상속된 클래스가 나중에 소멸
///     ==> 인스턴스 생성 위치가 변경될 수 있고, 잘못 해제할 경우 메모리 오류
/// 생성 순서와 소멸 순서는 정확하게 역순으로 진행된다.
class Parent
{
public:
    int m_xy = 1;
    Parent()
    {
        printf("Parent 생성자 호출\n");
    }
    ~Parent()
    {
        printf("Parent 소멸자 호출\n");
    }
};

class Child : public Parent
{
public:
    int m_yx = 2;
    const int x;
    ~Child()
    {
        printf("Child 소멸자 호출\n");
    }
    /// 후처리 영역 : 부모 클래스의 소멸자를 호출하는 위치

    Child()
        /// 선처리 영역 : 생성자 인수 받는 ) 뒤부터 함수 몸체가 시작되는
        /// { 사이에 위치한 영역. 상수 값을 설정할 수 있다.
        /// 부모 클래스의 생성자를 호출하는 위치
        : x(9)
    {
        printf("Child 생성자 호출\n");
    }

    /// 인수를 받는 생성자
    Child(int a)
        : x(a)      // 상수 멤버 변수인 x에 전달한 a 값으로 설정 가능!
                    // 인스턴스 생성 시마다 서로 다른 상수 값을 가질 수 있다!
    {
        m_yx = 7;
    }

    /// 복사 생성자 : 선행하는 인스턴스를 받아 정보를 이용하여 인스턴스 생성할 때 사용
    Child(const Child& obj)     // const ClassName& 형태는 고정!
        : x(10)
    {
        this->m_xy = obj.m_xy;
        //this->x = obj.x;
        this->m_yx = obj.m_yx + 110;
    }
};


int main()
{
    int x = 9;

    int k = x;
    int y(x);       // Child a(k);와 동일한 형태로 구성!
                    // OOP에서는 모든 자료형도 객체로 처리된다!!!
    printf("%d %d %d\n", x, k, y);

    Child c;        // 인수 없는 생성자 호출
    Child a(k);     // 인수 있는 생성자 호출. 상수 멤버 x 값이 k로 결정.
    Child b(c);     // 인수 있는 생성자 호출. 동일 객체를 전달하는 복사 생성자.
    printf("%p %p\n", &c.m_xy, &c.m_yx);
    std::cout << "Hello World!\n";
}
