// report2_example.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

/// 헤더가 <, > 기호로 포함되면 라이브러리 폴더
#include <iostream>
/// 헤더를 ", " 기호로 포함시키면 사용자 정의 위치의 헤더
#include "add.h"
#include "sub.h"
#include "multi.h"
#include "div.h"
#include "mod.h"

int main()
{
    printf("add : %d\n", add(78, 89));
    printf("sub : %d\n", sub(78, 89));
    printf("multi : %d\n", multi(78, 89));
    printf("div : %d\n", div(78, 89));
    printf("mod : %d\n", mod(78, 89));
}
