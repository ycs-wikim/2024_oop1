#include "Ctest.h"

/*
* static ����
* C��� ��Ÿ��
*  - ���� : �ѹ��� �ʱ�ȭ�Ǹ� ���� ����ó�� ��� ����
*  - �Լ� : ����� �ҽ� ���� �ܺο��� ���� �Ұ�
* 
* C++��� ��Ÿ��
*  - ����/�Լ� : Ŭ������ �ν��Ͻ�ȭ���� �ʴ��� �޸𸮿� ����
*/


/// ���� ���(static member) : �ν��Ͻ� ���̵� ��� ����
/// ������ ���(Non-static member) : �ν��Ͻ� ���� ��� �Ұ���
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
