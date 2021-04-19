/*CH_Preview_Constructor
		 <<<MUCHO IMPORTANTE!!>>> */
#include <iostream>
using namespace std;
/*					## (A)생성자 ##
	1. 객체가 생성될 때 자동으로 호출되는 멤버함수
	2. 클래스 이름과 동일, 리턴값 X, 중복정의 가능
	3. 명시적 호출과 DEFAULT생성자 혼돈 X --> EX) Circle cir = Circle() : 명시적 호출     ||    Circle cir() : FALSE!!!!

					## (B)위임 생성자&&타겟 생성자  ##
	1. 생성자의 중복 코드 방지 --> 중복되는 코드를 타겟 생성자에 정의
	2. 위임 생성자 : 타겟 생성자를 호출해 멤버 초기화를 위임
	3. 타겟 생성자 : 초기화를 처리하는 멤버 함수 

					## (C)디폴트 생성자 ##
	1. 생성자가 하나도 작성되어 있지 않다면 컴파일러가 "default 생성자" 자동생성
	2. 생성자가 하나라도 작성되어 있다면 자동생성 X*/
class DayOfYear {
public:
	/*CONSTRUCTOR*/
	DayOfYear(int month, int day);
	DayOfYear(int month);
	DayOfYear();/*DEFAULT*/
private:
	int month;
	int day;
	void testDate();
};

int main(void) {
	DayOfYear date1(6, 20);/*creation of DOY objects*/
	DayOfYear date2(12);
	DayOfYear date3;

	system("pause");
	return 0;
}

DayOfYear::DayOfYear():DayOfYear(9,28) {/*위임 생성자*/
	cout << "위임생성자 호출\n";
}
DayOfYear::DayOfYear(int month){
	cout << "타겟2생성자 호출\n";
	this->month = month;
	this->day = 1;
}
DayOfYear::DayOfYear(int month, int day) {/*타겟 생성자*/
	cout << "타겟1생성자 호출\n";
	this->month = month;
	this->day = day;
}