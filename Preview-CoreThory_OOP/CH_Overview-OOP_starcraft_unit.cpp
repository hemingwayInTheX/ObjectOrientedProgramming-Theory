#include <iostream>
#include <cstring>
using namespace std;

class Unit {
public:
	/*CONSTRUCTOR*/
	Unit();
	Unit(int coord_x, int coord_y, string name);
	/*ACCESSOR & MUTATOR*/
	int getCoord_x(); int getCoord_y(); string getName();
	int getHp(); int getDamage(); bool getIsDead();
	void setHp(int takeHp); void setDamage(int takeDamage);
	/*DISPLAY*/
	void unitStatus();
	/*STATIC METHOD*/
	static void totalUnitNum();
	/*FUNCTION OF OBJECT*/
	int attack();
	void be_attacked(int earn_damage);
private:
	int coord_x, coord_y;
	int hp;
	int damage;
	string name;
	bool isDead;
	static int unitNum;
};/*UNIT 클래스 정의부 --> 기본 클래스*/

class Terran :public Unit {
public:
	/*CONSTRUCTOR*/
	Terran();
	Terran(bool steroid);
	Terran(bool steroid, int x, int y, string name);
	/*FUNCTION OF OBJECT*/
	void setSteroid(bool steroid);
	void unitStatus();
private:
	bool steroid;
};/*TERRAN 클래스 정의부 --> 파생 클래스*/

class Protos :public Unit {
public:
	/*CONSTRUCTOR*/
	Protos();
	Protos(int mp, int x, int y, string name);
	/*ACCESOR & MUTATOR*/
	int getMp();
	void setMp();
	/*FUNCTION OF OBJECT*/
	void unitStatus();
private:
	int mp;
};/*PROTOS 클래스 정의부 --> 파생 클래스*/

int main(void) {
	/*객체 배열에 대한 동적 할당을 통해 다수의 유닛을 효율적으로 생성*/
	int inputNum = 0;
	cout << "생성할 유닛의 수를 입력하세요 >>"; cin >> inputNum;
	Terran* marine = new Terran[inputNum];//객체 배열 동적 생성
	for (int i = 0; i < inputNum; i++) {
		marine[i] = Terran(false, i + 1, i + 1, "marine");
		marine[i].unitStatus();
	}
	marine[0] = Terran(true);
	Unit::totalUnitNum();//static method 호출

	return 0;
}

/*STATIC MEMBER 초기화*/
/* ## 클래스 내부에서 선언되었지만 실제 STATIC 멤버는 프로그램 시작시 멤버가 선언되었기 때문에 */
/* ## 전역변수처럼 클래스 외부에 선언*/
int Unit::unitNum = 0;
void Unit::totalUnitNum() { cout << "현재 총 유닛은 = " << unitNum << " " << "입니다!" << endl; }

/*UNIT 클래스 구현부*/
Unit::Unit() {}
Unit::Unit(int coord_x, int coord_y, string name) {
	this->coord_x = coord_x;
	this->coord_y = coord_y;
	this->name = name;
	/*모든 멤버변수 초기화*/
	hp = 0; damage = 0; isDead = false;
	unitNum++;
}
int Unit::getCoord_x() { return coord_x; }
int Unit::getCoord_y() { return coord_y; }
string Unit::getName() { return name; }
int Unit::getHp() { return hp; }
int Unit::getDamage() { return damage; }
bool Unit::getIsDead() { return isDead; }

void Unit::setHp(int takeHp) { hp = takeHp; }
void Unit::setDamage(int takeDamage) { damage = takeDamage; }

void Unit::unitStatus() {
	cout << "현재 X좌표 = " << coord_x << " " << "현재 Y좌표 = " << coord_y << " "
		<< "유닛 이름 = " << name << endl;
}

/*TERRAN 클래스 구현부*/
/* ## 매개변수를 가진 파생 클래스의 생성자는 묵시적으로 기본 클래스의 기본 생성자를 호출*/
/* ##  파생 클래스의 생성자에서 명시적으로 기본 클래스의 생성자를 선택*/
/* ##  기본 클래스 멤버함수 재정의*/
Terran::Terran() {}
Terran::Terran(bool steroid) { setSteroid(steroid); }
Terran::Terran(bool steroid, int x, int y, string name) :Unit(x, y, name) {
	//Unit()-->컴파일러 자동생성
	this->steroid = steroid;
	/*유닛에 따라 초기화되는 체력과 공격력 상이 , 모든 유닛의 초기 생존여부는 생존 -->mutator통해 기본 클래스
		멤버변수 값 접근 및 변경*/
	if (name.compare("marine") == 0) { setHp(70); setDamage(65); }
	if (name.compare("medic") == 0) { setHp(50); setDamage(0); }
	if (name.compare("firebat") == 0) { setHp(84); setDamage(78); }

	/*스팀팩 사용시 유닛의 공격력 50증가*/
	if (steroid == true) {
		int upgradeDamage = getDamage();
		upgradeDamage += 50;
		/*MUTATOR 통해 향상된 공격력 THROWING*/
		setDamage(upgradeDamage);
	}
}
void Terran::unitStatus() {
	cout << "*****************************************************************" << endl;
	cout << "현재 (X,Y)좌표 = " << "(" << getCoord_x() << "," << getCoord_y() << ")" << " "
		<< "유닛 이름 = " << getName() << " " << "체력 = " << getHp() << " " << "공격력 = " << getDamage() << " "
		<< "생존여부 = " << getIsDead() << endl;
	if (steroid == true) { cout << "스팀팩 사용!! 공격력 50 증가" << endl; }
	else { cout << "스팀팩을 사용하지 않았습니다!!" << endl; }
}






