#include "Human.h"
#include <iostream>

//对类的静态数据进行初始化
int Human::humanCount = 0;

Human::Human() {
	name = "无名氏";
	age = 18;
	salary = 30000;
	humanCount++;
}

Human::Human(int age, int salary) {
	cout << "调用自定义的构造函数" << endl;
	this->age = age;      //this是一个特殊的指针，指向这个对象本身
	this->salary = salary;
	name = "无名";

	addr = new char[64];
	strcpy_s(addr, 64, "China");
	humanCount++;
}

Human::Human(const Human& man) {
	cout << "调用自定义的拷贝构造函数" << "参数：" << &man
		<< " 本对象：" << this << endl;

	age = man.age;      //this是一个特殊的指针，指向这个对象本身
	salary = man.salary;
	name = man.name;
	// 深度拷贝
	addr = new char[64];
	strcpy_s(addr, 64, man.addr);
	humanCount++;
}


Human& Human::operator=(const Human& man) {
	cout << "调用" << __FUNCTION__ << endl;
	if (this == &man) {
		return *this; //检测是不是对自己赋值：比如 h1 = h1;
	}

	// 如果有必要，需要先释放自己的资源（动态内存）
	//delete addr;
	//addr = new char[ADDR_LEN];

	// 深拷贝
	strcpy_s(addr, ADDR_LEN, man.addr);

	// 处理其他数据成员
	name = man.name;
	age = man.age;
	salary = man.salary;

	// 返回该对象本身的引用， 以便做链式连续处理，比如 a = b = c;
	return *this;
}


void Human::eat() {
	cout << "吃炸鸡，喝啤酒！" << endl;
}

void Human::sleep() {
	cout << "我正在睡觉!" << endl;
}

void Human::play() {
	cout << "我在唱歌! " << endl;
}

void Human::work() {
	cout << "我在工作..." << endl;
}

string Human::getName() {
	return name;
}

int Human::getAge() {
	return age;
}

int Human::getSalary() {
	return salary;
}

void Human::setAddr(const char* newAddr) {
	if (!newAddr) {
		return;
	}

	strcpy_s(addr, 64, newAddr);
}

const char* Human::getAddr() {
	return addr;
}

// 类的普通成员函数，可以直接访问静态成员（可读可写）

int Human::gethumanCount() {
	return humanCount;
}