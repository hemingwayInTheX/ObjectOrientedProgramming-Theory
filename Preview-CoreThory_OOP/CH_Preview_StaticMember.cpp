#include <iostream>
using namespace std;
/* STATIC MEMBER
  #1 멤버는 객체 내부가 아닌 별도의 공간에 생성 --> 클래스 당 하나 생성
  #2-1 객체가 생성되기 전 이미 프로그램 시작 시 멤버 생성
  #2-2 객체가 소멸되도 존재
  #3 동일한 클래스의 모든 객체들에 의해 공유*/
class Person {
public:
	void addMoney(int money);//개인 통장 저축
	static void unionMoney(int n);//회비 입금
private:
	int money;//개인 잔고
	static int sharedMoney;//회비 잔고
};//Person 클래스 선언부

/*static 멤버변수 초기화 = 클래스 멤버 변수처럼 초기화 되었지만, 실제 프로그램 시작 시 멤버가 생성
   되었기 때문에 전역변수 처럼 클래스 외부에서 초기화를 진행*/
int Person::sharedMoney = 10000;//첫 회비 내기 전 잔액 10000원

int main(void) {

	Person* ptr;
	Person A, B, C;
	A.addMoney(10000); B.addMoney(10000); C.addMoney(10000);//개인 통장 저축

	/*METHOD1 --> 클래스명과 범위 지정 연산자 :: 로 접근*/                     
	Person::unionMoney(10000);	//Person::sharedMoney=10000;							
	Person::unionMoney(20000);
	Person::unionMoney(30000);
	/*METHOD2 --> 객체의 멤버로 접근(보통 멤버처럼 접근 가능)*/
	A.unionMoney(10000); //A.sharedMoney=10000;
	B.unionMoney(10000);
	C.unionMoney(10000);
	/*METHOD3 --> 객체 포인터를 이용해 접근*/
	ptr = &A;
	ptr->unionMoney(10000);
	
	/*ERROR --> non-static멤버가 클래스 이름으로 접근할 경우*/
	/*Person::money = 100;
	Person::addMoney(200);*/
	
	return 0;
}

/*Person 클래스 구현부*/
void Person::addMoney(int money) {
	this->money = money;
	cout << "당신 통장의 현재 잔액은 = " << this->money << "원 입니다." << endl;
}
/*static 멤버 함수는 static 멤버만 접근 가능
  #1) static 멤버변수와 함수 내의 지역변수만 접근 가능 --> nonStatic멤버는 접근 불가
  #2) non-static멤버함수는 static에 접근 가능*/
void Person::unionMoney(int n) {
	int total = sharedMoney += n;
	cout << "회비의 현재 잔액은 =" << total << "원 입니다." << endl;
}