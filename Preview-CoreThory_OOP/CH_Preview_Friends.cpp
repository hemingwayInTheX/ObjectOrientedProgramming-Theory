/*CH_Preview_Inheritance
		 <<<HOW TO USE FRIEND??>>> */
#include <iostream>
using namespace std;
/*															## (A) 연산자 오버로딩 ##
		1. 기존의 연산자는 기본 자료형(int,float,double...)연산을 위해 제공 --> 기존 연산자로 객체간의 연산 처리 불가
		2. 기존 연산자를 '재정의'하여 사용자 타입의 자료형(객체)연산 작업 수행
		3. 멤버 함수로 정의 되었을 경우, 일반 함수로 정의 되었을 경우 구분

															## (B) 프렌즈##
		1. 클래스의 멤버 함수가 아닌 외부 함수 --> FRIEND 키워드를 통해 클래스 데이터에 접근 허용
		2. 연산자 함수가 외부함수로 선언되었을 경우, 클래스의 멤버 함수로 지정(FRIEND)해 멤버 데이터들을 활용하여 편리한 코드 작성 EX)THIS 사용, 멤버변수 직접사용

															## (C) CONST // REF ##
		1. CONST키워드는 대상을 상수화 --> 대상이 초기화 이후로 값 수정 못하도록 방지
		2. 사용하지 않아도 되지만, 컴파일 단계에서 오류 검사 */
class Power {
public:
	/*CONSTRUCTOR*/
	Power();
	Power(int kick, int punch);
	/*FRIENDS*/
	friend const Power operator +(const Power& op1, const Power& op2);
	friend const ostream& operator<<(ostream& os, const Power& p);
	/*FUNCTION*/
	const Power& operator-(const Power& op);
	const Power& operator++();
	void show();
private:
	int kick;
	int punch;
};

int main(void) {
	Power a(8, 6), b(5, 3);
	Power c;

	cout << "###이항연산자 (+) ###" << endl;//a.operator+(b)
	c = a + b;
	c.show();
	
	cout << "###이항연산자 (-) ###" << endl;
	c = a - b;
	c.show();

	cout << "###단항연산자 (++) ###" << endl;
	++a;
	c.show();
	
	cout << "###출력연산자 (<<) ###" << endl;//cout.operator<<( p ) 
	cout << c;

	system("pause");
	return 0;
}

/*Power 클래스 구현부*/
Power::Power():Power(0,0){}
Power::Power(int kick, int punch) {
	this->kick = kick;
	this->punch = punch;
}
void Power::show() {
	cout << "kick = " << kick << ',' << "punch = " << punch << endl;
}
/*연산자 메서드 구현*/
/*이항연산자 --> (+) : 외부함수 정의  (-) : 멤버함수 정의*/
const Power operator+(const Power& op1, const Power& op2) {
	Power temp;
	temp.kick = op1.kick + op2.kick;
	temp.punch = op1.punch + op2.punch;
	
	return temp;
}
const Power& Power::operator-(const Power& op) {
	int subKick = kick - op.kick;
	int subPunch = punch - op.punch;

	return Power(subKick, subPunch);
}
/*단항연산자 --> 멤버함수 정의 */
const Power&Power::operator++() {
	kick++;
	punch++;
	return *this;
}
/*리다이렉션 --> 외부함수 정의*/
 const ostream& operator<<(ostream& os, const Power& p) {
	 os << "[" << p.kick << ", " << p.punch << "]" << endl;
	 return os;
}



