#include <iostream>
#include <Windows.h>
#include <string>
#include <string.h>

#include  "Human.h"

// ����һ�������ࡱ

void test1() {
	Human tmp1;
	Human tmp2;

}

int main(void) {
	Human h1(25, 35000);  // ����Ĭ�Ϲ��캯��
	Human h2;
	test1();
	cout << "������:" << h2.gethumanCount() << endl;
	system("pause");
	return 0;
}