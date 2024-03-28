#include <iostream>

// typefef : 새로운 자료형 선언
// typefef A B : A 자료형을 B로 사용
typedef int INT;
typedef int K;
//i i;
INT a;

// sizeof( 변수 or 자료형 ) ==> 바이트 크기

int main()
{
    //int int = 9;
    K K = 9;
    std::cout << "K: " << sizeof(K) << "\n";
    //std::cout << "K: " << int << "\n";
    /// NULL 문자 : C언어 문자열의 끝 == 0, C++ == nullptr
    //nullptr;
    //문자열(문자 배열)의 초기화
    char c1[4] = "";            // | 0 | 0 | 0 | 0 |
    //char c2[4] = nullptr;
    //char c3[4] = NULL;
    char c4[4] = "ab";          // | a | b | 0 | 0 |
    //char c5[4] = "abcd";        // | a | b | c | d |
    char c6[4] = { 'a', 'b', 'c' }; // | a | b | c | 0 |
    const char* c7 = "fdghjk";
    char c8[] = "dfghjk";
    char str3[8] = { 0, };
    //str3 = "C++";
    str3[0] = 'C';
    str3[1] = '+';
    str3[2] = '+';
    //strcpy(str3, "D++");
    memcpy(str3, "D++", 3);
    std::string asd;        // java 등 객체 지향 언어의 문자열 처리 클래스
    asd = "4565789";        // 문자열을 숫자처럼 사용 가능
    asd += "dfghjkhgfdfghj";

    wchar_t str[4] = L"abc";
    std::cout << str << std::endl;
    printf("%ws\n", str);   // unicode는 별도 출력 형식이 필요함.

    /// {, }는 별도의 메모리 공간을 의미
    {
        int kkk = 5;
        printf("A: %d\n", kkk);
    }
    // {, } 내부에서 선언된 변수는 인식되지 않음. 다른 공간이므로
    //printf("A: %d\n", kkk);

    std::cout << "Hello World!\n" << str3 << std::endl << asd;
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴
