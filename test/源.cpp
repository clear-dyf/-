#include <iostream>
#include <Windows.h>
#include <string>
#include <string.h>

#include  "Human.h"

// 定义一个“人类”

void test1() {
	Human tmp1;
	Human tmp2;

}

int main(void) {
	Human h1(25, 35000);  // 调用默认构造函数
	Human h2;
	test1();
	cout << "总人数:" << h2.gethumanCount() << endl;
	system("pause");
	return 0;
}