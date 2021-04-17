#include <iostream>
using namespace std;
/* STATIC MEMBER
  #1 ����� ��ü ���ΰ� �ƴ� ������ ������ ���� --> Ŭ���� �� �ϳ� ����
  #2-1 ��ü�� �����Ǳ� �� �̹� ���α׷� ���� �� ��� ����
  #2-2 ��ü�� �Ҹ�ǵ� ����
  #3 ������ Ŭ������ ��� ��ü�鿡 ���� ����*/
class Person {
public:
	void addMoney(int money);//���� ���� ����
	static void unionMoney(int n);//ȸ�� �Ա�
private:
	int money;//���� �ܰ�
	static int sharedMoney;//ȸ�� �ܰ�
};//Person Ŭ���� �����

/*static ������� �ʱ�ȭ = Ŭ���� ��� ����ó�� �ʱ�ȭ �Ǿ�����, ���� ���α׷� ���� �� ����� ����
   �Ǿ��� ������ �������� ó�� Ŭ���� �ܺο��� �ʱ�ȭ�� ����*/
int Person::sharedMoney = 10000;//ù ȸ�� ���� �� �ܾ� 10000��

int main(void) {

	Person* ptr;
	Person A, B, C;
	A.addMoney(10000); B.addMoney(10000); C.addMoney(10000);//���� ���� ����

	/*METHOD1 --> Ŭ������� ���� ���� ������ :: �� ����*/                     
	Person::unionMoney(10000);	//Person::sharedMoney=10000;							
	Person::unionMoney(20000);
	Person::unionMoney(30000);
	/*METHOD2 --> ��ü�� ����� ����(���� ���ó�� ���� ����)*/
	A.unionMoney(10000); //A.sharedMoney=10000;
	B.unionMoney(10000);
	C.unionMoney(10000);
	/*METHOD3 --> ��ü �����͸� �̿��� ����*/
	ptr = &A;
	ptr->unionMoney(10000);
	
	/*ERROR --> non-static����� Ŭ���� �̸����� ������ ���*/
	/*Person::money = 100;
	Person::addMoney(200);*/
	
	return 0;
}

/*Person Ŭ���� ������*/
void Person::addMoney(int money) {
	this->money = money;
	cout << "��� ������ ���� �ܾ��� = " << this->money << "�� �Դϴ�." << endl;
}
/*static ��� �Լ��� static ����� ���� ����
  #1) static ��������� �Լ� ���� ���������� ���� ���� --> nonStatic����� ���� �Ұ�
  #2) non-static����Լ��� static�� ���� ����*/
void Person::unionMoney(int n) {
	int total = sharedMoney += n;
	cout << "ȸ���� ���� �ܾ��� =" << total << "�� �Դϴ�." << endl;
}