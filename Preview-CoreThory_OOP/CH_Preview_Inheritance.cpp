/*CH_Preview_Inheritance
         <<<HOW DOES THE CLASS INHERIT??>>> */
#include <iostream>
using namespace std;
/*								## (A) 상속관계 클래스 생성자 호출 순서 ##
		1. 컴파일러는 묵시적으로 파생클래스의 기본생성자, 매개변수 생성자에 기본 클래스의 기본생성자가 자동으로 호출되도록 컴파일
		2. 파생클래스의 매개변수 생성자가 "명시적 생성자 호출" 을 통해 기본클래스의 기본생성자 호출 생략 가능
		
								## (B) 클래스 형변환 ##
		1. UP-CASTING = 파생 객체가 기본 객체처럼 행동하는 것 --> 형변환된 포인터는 파생객체의 멤버에 접근 불가
		2. DOWN-CASTING = 기본 객체가 파생 객체처럼 행동하는 것(명시적 선언 필요) --> 형변환된 포인터는 기본,파생 클래스의 모든 멤버에 접근 가능
		
							        ## (C) 상속 지정 ##
		1. PUBLIC = 기본 클래스의 접근 지정자 변함 없이 그대로 사용
		2. PROTECTED = 기본 클래스에 PUBLIC 지정자 있다면, PROTECTED로 파생 클래스에서 사용
		3. PRIVATE = PRIVATE으로 상속 받으면 파생 클래스 내에서 "Private처럼" 행동, but 기존의 PRIVATE멤버에는 접근 불가*/
class TV {
public:
	/*CONSTRUCTOR*/
	TV();
	TV(int size);
	/*DESTRUCTOR*/
	~TV();
	/*ACCESOR*/
	int getSize();
	/*FUNCTION*/
	void show();
private:
	int size;
};

class IpTv :private TV {
public:
	void showIpTv() {/*show, getSize 메서드는 TV클래스의 멤버를 PRIVATE지정으로 상속 --> 해당 클래스 내부에서 PRIVATE인 것 처럼 행동*/
		show();
		getSize();
	}
protected:
	int getElec();
private:
	int elec;
};
class OledTv :private IpTv {
public:
	void showOledTv() {/*ERROR!!! --> OledTv한테 show(), getSize()는 애초에 private멤버로 간주되어 접근 불가 but getElec은 PRIVATE인 것 처럼 행동*/
		//show();
		//getSize();
		int getElec();
	}
};
class WideTv :public TV {
public:
	/*CONSTRUCTOR*/
	WideTv(int size, bool viedoln);
	/*DESTRUCTOR*/
	~WideTv();
	/*ACCESSOR*/
	bool getVideoln();
private:
	bool videoln;
};

class SmartTv :public WideTv {
public:
	/*CONSTRUCTOR*/
	SmartTv();
	SmartTv(string ipAdrr, int size);
	/*DESTRUCTOR*/
	~SmartTv();
	/*ACCESOR*/
	string getIpAddr();
private:
	string ipAddr;
};

int main(void) {
	SmartTv tv("140.032.01.01", 27);

	cout << "size = " << tv.getSize() << endl;
	cout << "videoln = " << tv.getVideoln() << endl;
	cout << "ip = " << tv.getIpAddr() << endl;

	SmartTv television;
	SmartTv* pder = &television;
	WideTv* pbase = pder;/*1> UP-CASTING*/

	pder->getSize(); pder->getVideoln(); pder->getIpAddr();
	pbase->getSize(); pbase->getVideoln();
	//pbase->getIpAddr();/*ERROR!!! --> 파생클래의 객체가 기본 클래스의 객체처럼 행동하기 때문에 파생 클래스의 멤버 접근 불가!*/
	
	pder = (SmartTv*)pbase;/*2> DOWN-CASTING*/
	pder->getSize(); pder->getVideoln(); pder->getIpAddr();/*기본 클래스의 객체가 파생 클래스의 객체처럼 행동하기 때문에 전 멤버에 접근 가능!*/

	system("pause");
	return 0;
}
/*## TV클래스 구현부 ##*/
TV::TV() {
	cout << "최상위 클래스의 기본 생성자를 호출하셨습니다!\n";
}
TV::TV(int size) { 
	cout << "최상위 클래스의 매개변수 생성자를 호출하셨습니다!!\n"; /*CONS_CALL (1)*/
	this->size = size; 
}
TV::~TV() {
	cout << "최상위 클래스의 소멸자를 실행하셨습니다!!\n";/*DES_CALL (3)*/
}
int TV::getSize() { return size; }
/*## WideTv클래스 구현부 ##*/
WideTv::WideTv(int size, bool videoln) :TV(size) {
	cout << "중간 클래스의 매개변수 생성자를 호출하셨습니다!!\n"; /*CONS_CALL (2)*/
	this->videoln = videoln;
}
WideTv::~WideTv() {
	cout << "중간 클래스의 소멸자를 실행하셨습니다!!\n";/*DES_CALL (2)*/
}
bool WideTv::getVideoln() { return videoln; }
/*## SmartTv클래스 구현부 ##*/
SmartTv::SmartTv() :SmartTv("James",0){}
SmartTv::SmartTv(string ipAddr, int size) : WideTv(size, true) {
	cout << "최하위 클래스의 매개변수 생성자를 호출하셨습니다!!\n";/*CONS_CALL (3)*/
	this->ipAddr = ipAddr; 
}
SmartTv::~SmartTv() {
	cout << "최하위 클래스의 소멸자를 실행하셨습니다!!\n";/*DES_CALL(1)*/
}
string SmartTv::getIpAddr() { return ipAddr; }


