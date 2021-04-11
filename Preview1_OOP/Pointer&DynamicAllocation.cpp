/*Pointer & DynamicAllocation*/
#include <iostream>
using namespace std;

class Person {
public:
	Person();//constructor
	Person(string name);
	string getName();//accessor&mutator
	void setName(string name);
private:
	string name;
};//Person Ŭ���� �����

class Friends {
public:
	Friends(string name, int size);//constructor
	void setName(int idx, string name);//mutator
	~Friends();//destructor
	void display();//print
private:
	int size;
	string name;
	Person* friends;//personŸ���� �����迭 ������ ���� ������ ����
};//Friends Ŭ���� �����

int main(void) {
	Friends* myfriend = new Friends("TAK", 4);//friends Ÿ���� ������ü ����
	myfriend->setName(0, "james");
	myfriend->setName(1, "maria");
	myfriend->setName(2, "ignacio");
	myfriend->setName(3, "fernando");

	myfriend->display();

	delete myfriend;//destructor
}

/*Person Ŭ���� ������*/
Person::Person() {name = "";}
Person::Person(string name) { this->name = name; }
string Person::getName() { return name; }
void Person::setName(string name) { this->name = name; }

/*Friends Ŭ���� ������*/
Friends::Friends(string name,int size) {
	this->name = name;
	this->size = size;
	friends = new Person[size];//friends = person Ÿ�� �����͸� ����Ű�� ������ ���� (heap������ ������ ���� �迭�� ù ��° �ּҸ� ����)
}
void Friends::setName(int idx, string name) {
	friends[idx].setName(name);
}
Friends::~Friends() {
	delete[] friends;
}
void Friends::display() {
	for (int  i = 0; i < 4; i++){
		cout << friends[i].getName() << " " << endl;
	}
}
