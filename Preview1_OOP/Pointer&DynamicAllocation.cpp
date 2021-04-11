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
};//Person 클래스 선언부

class Friends {
public:
	Friends(string name, int size);//constructor
	void setName(int idx, string name);//mutator
	~Friends();//destructor
	void display();//print
private:
	int size;
	string name;
	Person* friends;//person타입의 동적배열 생성을 위한 포인터 변수
};//Friends 클래스 선언부

int main(void) {
	Friends* myfriend = new Friends("TAK", 4);//friends 타입의 동적객체 생성
	myfriend->setName(0, "james");
	myfriend->setName(1, "maria");
	myfriend->setName(2, "ignacio");
	myfriend->setName(3, "fernando");

	myfriend->display();

	delete myfriend;//destructor
}

/*Person 클래스 구현부*/
Person::Person() {name = "";}
Person::Person(string name) { this->name = name; }
string Person::getName() { return name; }
void Person::setName(string name) { this->name = name; }

/*Friends 클래스 구현부*/
Friends::Friends(string name,int size) {
	this->name = name;
	this->size = size;
	friends = new Person[size];//friends = person 타입 데이터를 가리키는 포인터 변수 (heap영역에 생성된 동적 배열의 첫 번째 주소를 저장)
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
