#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

#include "hospital.h"

/*===ConsoleŬ���� ������===*/
int Console::select_menu() {
	int inputMenu = 0;
	try{
		cout << "****���Ͻô� ���񽺸� �����ϼ���****" << endl;
		cout << "(1)���� ����\n(2)���� ���\n(3)���� ��ȸ\n(4)���� ����\n(5)����\n";
		cin >> inputMenu;
		cin.ignore(INT_MAX, '\n');//���ۺ���

		if (inputMenu > 4) {
			throw inputMenu;
		}
	}
	catch (int x){
		cout << "WARNING! �߸��� �Է��Դϴ�!! �ٽ� �Է����ּ���~!\n";
		cin >> inputMenu;
	}
	return inputMenu;
}

int Console::select_dept() {
	int inputDept = 0;
	try {
		cout << "****����Ͻô� ����μ��� �����ϼ���****" << endl;
		cout << "(1)����\n(2)�ܰ�\n(3)�Ǻΰ�\n(4)�̺����İ�\n";
		cin >> inputDept;
		if (inputDept > 4) {
			//throw inputDept;
		}
	}
	catch (int x ) {
		cout << "WARNING! �߸��� �Է��Դϴ�!! �ٽ� �Է����ּ���~!\n";
		cin >> inputDept;
	}
	return inputDept;
}

int Console::select_method() {
	int inputMenu = 0;
	try {
		cout << "****���� ����� �����ϼ���****" << endl;
		cout << "(1)�Ƿ��� �˻� ����\n(2)����� ���� ����\n";
		cin >> inputMenu;
		cin.ignore(INT_MAX, '\n');//���ۺ���

		if (inputMenu > 2) {
			throw inputMenu;
		}
	}
	catch (int x) {
		cout << "WARNING! �߸��� �Է��Դϴ�!! �ٽ� �Է����ּ���~!\n";
		cin >> inputMenu;
	}
	return inputMenu;
}
//int Console::select_date() {
//	int inputDate = 0;
//	try {
//		cout << "****��¥�� �������ּ���****" << endl;
//		cout << "(1)��\t(2)ȭ\t(3)��\t (4)��\t(5)��\n";
//		cin >> inputDate;
//		if (inputDate > 5) {
//			throw inputDate;
//		}
//	}
//	catch (int z) {
//		cout << "WARNING! �߸��� �Է��Դϴ�!! �ٽ� �Է����ּ���~!\n";
//		cin >> inputDate;
//	}
//	return inputDate;
//}
//int Console::select_time() {
//	int inputTime = 0;
//	try {
//		cout << "****�ð��� �������ּ���****" << endl;
//		cout << "(1)���� 10:30\t(2)����11:30\t(3)���� 13:20\t (4)���� 15:00\n";
//		cin >> inputTime;
//		cin.ignore(INT_MAX, '\n');//���ۺ���
//		if (inputTime > 4) {
//			throw inputTime;
//		}
//		return inputTime;
//}
//	catch (int q) {
//		cout << "WARNING! �߸��� �Է��Դϴ�!! �ٽ� �Է����ּ���~!\n";
//		cin >> inputTime;
//	}
//	return inputTime;
//}
//string Console::input_name() {
//	string name;
//	cout << "���� ������ �Է����ּ��� >>";
//	getline(cin, name);
//
//	return name;
//}

/*===HospitalŬ���� ������===*/
Hospital::Hospital() {
	department = new Department[10];//10���� ����μ�
	ifstream read_file;
	string readLine;//�� �� �о ����
	string deptName;
	int idx = 0;

	read_file.exceptions(ifstream::failbit | ifstream::badbit);
	read_file.open("department.txt");//�ؽ�Ʈ���� �ҷ�����
	
	/*���Ͽ��� ����μ����� reading & reading�� �����͸� ���� ������ ��ü�迭 �ʱ�ȭ*/
	while (!read_file.eof()) {//���� �� ������ loop����
		getline(read_file, readLine);
		deptName = readLine;//�Ѱ��� �μ��� ����
		department[idx].set_deptName(deptName);
		vec.push_back(department[idx]);//���� ����
		idx++;//�ε��� ����
	}
}

void Hospital::execute_prog() {
	menu = Console::select_menu();//�޴� ����(1.���� / 2.��� / 3.��ȸ /4.���� / 5.����)
	switch (menu){
	case 1: {//���� ����
		selectDept = Console::select_dept();//����μ� ����(1 ~ 25)
		activation_prog(selectDept);//Ȱ��ȭ�޼��� ����
		}
	case 2: {//��� ����

	}
	case 3: {//��ȸ ����

	}
	case 4: {//���� ����

	}
	case 5:
	}
}
void Hospital::activation_prog(int selection) {
}
