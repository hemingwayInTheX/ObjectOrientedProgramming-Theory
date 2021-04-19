/*CH_Preview_Inheritance
         <<<HOW DOES THE CLASS INHERIT??>>> */
#include <iostream>
using namespace std;
/*															## (A) ��Ӱ��� Ŭ���� ������ ȣ�� ���� ##
		1. �����Ϸ��� ���������� �Ļ�Ŭ������ �⺻������, �Ű����� �����ڿ� �⺻ Ŭ������ �⺻�����ڰ� �ڵ����� ȣ��ǵ��� ������
		2. �Ļ�Ŭ������ �Ű����� �����ڰ� "����� ������ ȣ��" �� ���� �⺻Ŭ������ �⺻������ ȣ�� ���� ����
		
																			## (B) Ŭ���� ����ȯ ##
		1. UP-CASTING = �Ļ� ��ü�� �⺻ ��üó�� �ൿ�ϴ� �� --> ����ȯ�� �����ʹ� �Ļ���ü�� ����� ���� �Ұ�
		2. DOWN-CASTING = �⺻ ��ü�� �Ļ� ��üó�� �ൿ�ϴ� ��(����� ���� �ʿ�) --> ����ȯ�� �����ʹ� �⺻,�Ļ� Ŭ������ ��� ����� ���� ����
		
																				## (C) ��� ���� ##
		1. PUBLIC = �⺻ Ŭ������ ���� ������ ���� ���� �״�� ���
		2. PROTECTED = �⺻ Ŭ������ PUBLIC ������ �ִٸ�, PROTECTED�� �Ļ� Ŭ�������� ���
		3. PRIVATE = PRIVATE���� ��� ������ �Ļ� Ŭ���� ������ "Privateó��" �ൿ, but ������ PRIVATE������� ���� �Ұ�*/
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
	void showIpTv() {/*show, getSize �޼���� TVŬ������ ����� PRIVATE�������� ��� --> �ش� Ŭ���� ���ο��� PRIVATE�� �� ó�� �ൿ*/
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
	void showOledTv() {/*ERROR!!! --> OledTv���� show(), getSize()�� ���ʿ� private����� ���ֵǾ� ���� �Ұ� but getElec�� PRIVATE�� �� ó�� �ൿ*/
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
	//pbase->getIpAddr();/*ERROR!!! --> �Ļ�Ŭ���� ��ü�� �⺻ Ŭ������ ��üó�� �ൿ�ϱ� ������ �Ļ� Ŭ������ ��� ���� �Ұ�!*/
	
	pder = (SmartTv*)pbase;/*2> DOWN-CASTING*/
	pder->getSize(); pder->getVideoln(); pder->getIpAddr();/*�⺻ Ŭ������ ��ü�� �Ļ� Ŭ������ ��üó�� �ൿ�ϱ� ������ �� ����� ���� ����!*/

	system("pause");
	return 0;
}
/*## TVŬ���� ������ ##*/
TV::TV() {
	cout << "�ֻ��� Ŭ������ �⺻ �����ڸ� ȣ���ϼ̽��ϴ�!\n";
}
TV::TV(int size) { 
	cout << "�ֻ��� Ŭ������ �Ű����� �����ڸ� ȣ���ϼ̽��ϴ�!!\n"; /*CONS_CALL (1)*/
	this->size = size; 
}
TV::~TV() {
	cout << "�ֻ��� Ŭ������ �Ҹ��ڸ� �����ϼ̽��ϴ�!!\n";/*DES_CALL (3)*/
}
int TV::getSize() { return size; }
/*## WideTvŬ���� ������ ##*/
WideTv::WideTv(int size, bool videoln) :TV(size) {
	cout << "�߰� Ŭ������ �Ű����� �����ڸ� ȣ���ϼ̽��ϴ�!!\n"; /*CONS_CALL (2)*/
	this->videoln = videoln;
}
WideTv::~WideTv() {
	cout << "�߰� Ŭ������ �Ҹ��ڸ� �����ϼ̽��ϴ�!!\n";/*DES_CALL (2)*/
}
bool WideTv::getVideoln() { return videoln; }
/*## SmartTvŬ���� ������ ##*/
SmartTv::SmartTv() :SmartTv("James",0){}
SmartTv::SmartTv(string ipAddr, int size) : WideTv(size, true) {
	cout << "������ Ŭ������ �Ű����� �����ڸ� ȣ���ϼ̽��ϴ�!!\n";/*CONS_CALL (3)*/
	this->ipAddr = ipAddr; 
}
SmartTv::~SmartTv() {
	cout << "������ Ŭ������ �Ҹ��ڸ� �����ϼ̽��ϴ�!!\n";/*DES_CALL(1)*/
}
string SmartTv::getIpAddr() { return ipAddr; }


