// 전처리기 include : 해당 피일을 가져와서 소스에 붙여준다
// 번역전에 소스에 필요한 처리를 수행해준다.
#include <iostream>
using namespace std;    // 이름공간 std(standard)
// 매크로 상수 Vs. 변수
// 변수 : l-value, r-value 모두 가능
// 상수 : r-value만 가능
// l-value = r-value
//#define A  B ==> A를 앞으로 B로 사용하겠다.
#define   PI 3.14


void ps()
{
    cout << __FILE__ << endl;
    cout << __LINE__ << endl;
    cout << __FUNCTION__ << endl;

#ifdef _M_X64
    cout << "64bit\n";
#else
    cout << "32bit\n";
#endif
}



int main()
{
    int x = 5;
    cout << "H" << x << "ello World!" << endl;     // end line == \n

    x = 90;
    x = x + 89 + x + 2 * x + PI;
    //PI = 9 + PI;
    ps();

    // main에서 return 프로그램 종료. 숫자는 종료코드
    return 0;
}
