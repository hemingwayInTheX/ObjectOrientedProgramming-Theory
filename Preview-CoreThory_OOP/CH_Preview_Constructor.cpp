/*CH_Preview_Constructor
		 <<<MUCHO IMPORTANTE!!>>> */
#include <iostream>
using namespace std;
/*					## (A)������ ##
	1. ��ü�� ������ �� �ڵ����� ȣ��Ǵ� ����Լ�
	2. Ŭ���� �̸��� ����, ���ϰ� X, �ߺ����� ����
	3. ����� ȣ��� DEFAULT������ ȥ�� X --> EX) Circle cir = Circle() : ����� ȣ��     ||    Circle cir() : FALSE!!!!

					## (B)���� ������&&Ÿ�� ������  ##
	1. �������� �ߺ� �ڵ� ���� --> �ߺ��Ǵ� �ڵ带 Ÿ�� �����ڿ� ����
	2. ���� ������ : Ÿ�� �����ڸ� ȣ���� ��� �ʱ�ȭ�� ����
	3. Ÿ�� ������ : �ʱ�ȭ�� ó���ϴ� ��� �Լ� 

					## (C)����Ʈ ������ ##
	1. �����ڰ� �ϳ��� �ۼ��Ǿ� ���� �ʴٸ� �����Ϸ��� "default ������" �ڵ�����
	2. �����ڰ� �ϳ��� �ۼ��Ǿ� �ִٸ� �ڵ����� X*/
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

DayOfYear::DayOfYear():DayOfYear(9,28) {/*���� ������*/
	cout << "���ӻ����� ȣ��\n";
}
DayOfYear::DayOfYear(int month){
	cout << "Ÿ��2������ ȣ��\n";
	this->month = month;
	this->day = 1;
}
DayOfYear::DayOfYear(int month, int day) {/*Ÿ�� ������*/
	cout << "Ÿ��1������ ȣ��\n";
	this->month = month;
	this->day = day;
}