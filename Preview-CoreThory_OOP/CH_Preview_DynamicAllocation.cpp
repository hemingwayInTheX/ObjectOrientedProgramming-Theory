/*CH_Preview_DynamicAllocation
		 <<<HOW TO USE DynamicAllcoation??>>> */
#include <iostream>
using namespace std;
/*					## (A)��ü �迭 ##
	1. ����Ʈ ������ �ڵ� ȣ�� --> �Ű����� �ִ� �����ڷ� �ʱ�ȭ �Ұ�
	2. �Ҹ��� ������ �ݴ�� ���� --> EX) arr[2]-arr[1]-arr[0]
	3. �ʱ�ȭ�� �� ���� ��ü�� ������ ����
	
					## (B)��ü �����Ҵ� ##
	1. HEAP ������ �ʿ��� ��ŭ ���ϴ� Ÿ���� ���� �޸� ����
	2. ������ ������ �ʱ�ȭ ����
	3. delete --> ��) �������� �Ҵ����� �ʴ� ������ ������ ������ �� runtimeError
							��) ������ ������ ������ �� �� ������ �� runtimeError

					## (C)��ü �迭 �����Ҵ� ##
	1. �迭�� ���� �Ҵ�� �ʱ�ȭ �Ұ�
	2. delete�� [] ��� -->���� ���������� ���������� ��ȯ �߻�*/

class Circle {
public:
	/*CONSTRUCTOR*/
	Circle();
	Circle(int r);
	/*DESTRUCTOR*/
	~Circle();
	/*MUTATOR*/
	void setRadius(int r);
	/*FUNCTION*/
	double getArea();
private:
	int radius;
};

int main(void) {
	cout << "=============A)��ü �迭===============" << endl;
	Circle circleArr[5] = { Circle(),Circle(5), Circle(10), Circle(15), Circle(20), };/*A) �� ���Ҵ� ������ ������ �迭 �ʱ�ȭ*/
	for (int i = 0; i < 5; i++){
		cout << i << "��° ���� ������ = " << " " << circleArr[i].getArea() << "�Դϴ�" << endl;
	}

	cout << "=============C)��ü �迭 �����Ҵ�===============" << endl;
	int inputNum = 0;
	int inputR = 0;
	cout << "input>>"; cin >> inputNum;
	Circle* cir = new Circle[inputNum]/*(10)*/; /*C) �迭�� ���� �����Ҵ��� �ʱ�ȭ �Ұ�*/

	for (int i = 0; i < inputNum; i++){/*�� ��ü���� �ٸ� ������ �Է��� �ʱ�ȭ*/
		cout << "input radius>>"; cin >> inputR;
		cir[i].setRadius(inputR);
	}
	Circle* ptrCir = cir;
	for (int i = 0; i < inputNum; i++){/*���*/
		cout << i << "��° ���� ������ = " << " " << ptrCir->getArea() << endl;
		ptrCir++;
	}

	delete[]cir;/*��ü �迭 �Ҹ� --> ������ �ݴ�� �۾� ����*/
	system("pause");
	return 0;
}

/*Circle Ŭ���� ������*/
Circle::Circle() { 
	radius = 1; 
}
Circle::Circle(int r) { 
	radius = r;
}
Circle::~Circle() {
	cout << "�Ҹ��� ���� radius = " << radius << endl;
}
void Circle::setRadius(int r) {
	radius = r;
}
double Circle::getArea() {
	return 3.14 * radius * radius;
}