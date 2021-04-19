/*CH_Preview_Inheritance
		 <<<HOW TO USE FRIEND??>>> */
#include <iostream>
using namespace std;
/*															## (A) ������ �����ε� ##
		1. ������ �����ڴ� �⺻ �ڷ���(int,float,double...)������ ���� ���� --> ���� �����ڷ� ��ü���� ���� ó�� �Ұ�
		2. ���� �����ڸ� '������'�Ͽ� ����� Ÿ���� �ڷ���(��ü)���� �۾� ����
		3. ��� �Լ��� ���� �Ǿ��� ���, �Ϲ� �Լ��� ���� �Ǿ��� ��� ����

															## (B) ������##
		1. Ŭ������ ��� �Լ��� �ƴ� �ܺ� �Լ� --> FRIEND Ű���带 ���� Ŭ���� �����Ϳ� ���� ���
		2. ������ �Լ��� �ܺ��Լ��� ����Ǿ��� ���, Ŭ������ ��� �Լ��� ����(FRIEND)�� ��� �����͵��� Ȱ���Ͽ� ���� �ڵ� �ۼ� EX)THIS ���, ������� �������

															## (C) CONST // REF ##
		1. CONSTŰ����� ����� ���ȭ --> ����� �ʱ�ȭ ���ķ� �� ���� ���ϵ��� ����
		2. ������� �ʾƵ� ������, ������ �ܰ迡�� ���� �˻� */
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

	cout << "###���׿����� (+) ###" << endl;//a.operator+(b)
	c = a + b;
	c.show();
	
	cout << "###���׿����� (-) ###" << endl;
	c = a - b;
	c.show();

	cout << "###���׿����� (++) ###" << endl;
	++a;
	c.show();
	
	cout << "###��¿����� (<<) ###" << endl;//cout.operator<<( p ) 
	cout << c;

	system("pause");
	return 0;
}

/*Power Ŭ���� ������*/
Power::Power():Power(0,0){}
Power::Power(int kick, int punch) {
	this->kick = kick;
	this->punch = punch;
}
void Power::show() {
	cout << "kick = " << kick << ',' << "punch = " << punch << endl;
}
/*������ �޼��� ����*/
/*���׿����� --> (+) : �ܺ��Լ� ����  (-) : ����Լ� ����*/
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
/*���׿����� --> ����Լ� ���� */
const Power&Power::operator++() {
	kick++;
	punch++;
	return *this;
}
/*�����̷��� --> �ܺ��Լ� ����*/
 const ostream& operator<<(ostream& os, const Power& p) {
	 os << "[" << p.kick << ", " << p.punch << "]" << endl;
	 return os;
}



