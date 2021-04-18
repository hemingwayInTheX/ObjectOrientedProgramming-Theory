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
};/*UNIT Ŭ���� ���Ǻ� --> �⺻ Ŭ����*/

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
};/*TERRAN Ŭ���� ���Ǻ� --> �Ļ� Ŭ����*/

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
};/*PROTOS Ŭ���� ���Ǻ� --> �Ļ� Ŭ����*/

int main(void) {
	/*��ü �迭�� ���� ���� �Ҵ��� ���� �ټ��� ������ ȿ�������� ����*/
	int inputNum = 0;
	cout << "������ ������ ���� �Է��ϼ��� >>"; cin >> inputNum;
	Terran* marine = new Terran[inputNum];//��ü �迭 ���� ����
	for (int i = 0; i < inputNum; i++) {
		marine[i] = Terran(false, i + 1, i + 1, "marine");
		marine[i].unitStatus();
	}
	marine[0] = Terran(true);
	Unit::totalUnitNum();//static method ȣ��

	return 0;
}

/*STATIC MEMBER �ʱ�ȭ*/
/* ## Ŭ���� ���ο��� ����Ǿ����� ���� STATIC ����� ���α׷� ���۽� ����� ����Ǿ��� ������ */
/* ## ��������ó�� Ŭ���� �ܺο� ����*/
int Unit::unitNum = 0;
void Unit::totalUnitNum() { cout << "���� �� ������ = " << unitNum << " " << "�Դϴ�!" << endl; }

/*UNIT Ŭ���� ������*/
Unit::Unit() {}
Unit::Unit(int coord_x, int coord_y, string name) {
	this->coord_x = coord_x;
	this->coord_y = coord_y;
	this->name = name;
	/*��� ������� �ʱ�ȭ*/
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
	cout << "���� X��ǥ = " << coord_x << " " << "���� Y��ǥ = " << coord_y << " "
		<< "���� �̸� = " << name << endl;
}

/*TERRAN Ŭ���� ������*/
/* ## �Ű������� ���� �Ļ� Ŭ������ �����ڴ� ���������� �⺻ Ŭ������ �⺻ �����ڸ� ȣ��*/
/* ##  �Ļ� Ŭ������ �����ڿ��� ��������� �⺻ Ŭ������ �����ڸ� ����*/
/* ##  �⺻ Ŭ���� ����Լ� ������*/
Terran::Terran() {}
Terran::Terran(bool steroid) { setSteroid(steroid); }
Terran::Terran(bool steroid, int x, int y, string name) :Unit(x, y, name) {
	//Unit()-->�����Ϸ� �ڵ�����
	this->steroid = steroid;
	/*���ֿ� ���� �ʱ�ȭ�Ǵ� ü�°� ���ݷ� ���� , ��� ������ �ʱ� �������δ� ���� -->mutator���� �⺻ Ŭ����
		������� �� ���� �� ����*/
	if (name.compare("marine") == 0) { setHp(70); setDamage(65); }
	if (name.compare("medic") == 0) { setHp(50); setDamage(0); }
	if (name.compare("firebat") == 0) { setHp(84); setDamage(78); }

	/*������ ���� ������ ���ݷ� 50����*/
	if (steroid == true) {
		int upgradeDamage = getDamage();
		upgradeDamage += 50;
		/*MUTATOR ���� ���� ���ݷ� THROWING*/
		setDamage(upgradeDamage);
	}
}
void Terran::unitStatus() {
	cout << "*****************************************************************" << endl;
	cout << "���� (X,Y)��ǥ = " << "(" << getCoord_x() << "," << getCoord_y() << ")" << " "
		<< "���� �̸� = " << getName() << " " << "ü�� = " << getHp() << " " << "���ݷ� = " << getDamage() << " "
		<< "�������� = " << getIsDead() << endl;
	if (steroid == true) { cout << "������ ���!! ���ݷ� 50 ����" << endl; }
	else { cout << "�������� ������� �ʾҽ��ϴ�!!" << endl; }
}






