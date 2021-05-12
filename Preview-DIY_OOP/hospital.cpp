#include <iostream>
#include <string>
using namespace std;

#include "hospital.h"

/*===ConsoleŬ���� ������===*/
int Console::select_menu() {
	int inputMenu = 0;
	try{
		cout << "****���Ͻô� ���񽺸� �����ϼ���****" << endl;
		cout << "(1)���� ����\n(2)���� ���\n(3)���� ��ȸ\n(4)������\n";
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
int Console::select_date() {
	int inputDate = 0;
	try {
		cout << "****��¥�� �������ּ���****" << endl;
		cout << "(1)��\t(2)ȭ\t(3)��\t (4)��\t(5)��\n";
		cin >> inputDate;
		if (inputDate > 5) {
			throw inputDate;
		}
	}
	catch (int z) {
		cout << "WARNING! �߸��� �Է��Դϴ�!! �ٽ� �Է����ּ���~!\n";
		cin >> inputDate;
	}
	return inputDate;
}
int Console::select_time() {
	int inputTime = 0;
	try {
		cout << "****�ð��� �������ּ���****" << endl;
		cout << "(1)���� 10:30\t(2)����11:30\t(3)���� 13:20\t (4)���� 15:00\n";
		cin >> inputTime;
		cin.ignore(INT_MAX, '\n');//���ۺ���
		if (inputTime > 4) {
			throw inputTime;
		}
		return inputTime;
}
	catch (int q) {
		cout << "WARNING! �߸��� �Է��Դϴ�!! �ٽ� �Է����ּ���~!\n";
		cin >> inputTime;
	}
	return inputTime;
}
string Console::input_name() {
	string name;
	cout << "���� ������ �Է����ּ��� >>";
	getline(cin, name);

	return name;
}

/*===HospitalŬ���� ������===*/
void Hospital::execute_prog() {
	menu = Console::select_menu();
	if (menu == 1) {
		selectDept = Console::select_dept();
		switch (selectDept){
		case 1: {
			selectDate = Console::select_date();
			selectTime = Console::select_time();
			name = Console::input_name();
			department[0].reservation(selectDate, selectTime, name);
			break;
		}
		case 2: {
			selectDate = Console::select_date();
			selectTime = Console::select_time();
			name = Console::input_name();
			department[1].reservation(selectDate, selectTime, name);
			break;
		}
		case 3: {
			selectDate = Console::select_date();
			selectTime = Console::select_time();
			name = Console::input_name();
			department[2].reservation(selectDate, selectTime, name);
			break;
		}
		case 4: {
			selectDate = Console::select_date();
			selectTime = Console::select_time();
			name = Console::input_name();
			department[2].reservation(selectDate, selectTime, name);
			break;
		}
		default:
			break;
		}
	}
}
/*===DepartmentŬ���� ������===*/
void Department::reservation(int date, int time, string clientName) {
	dc->set_PatientInfo(clientName, date, time);
}

void Department::display_status() {
	cout<<dc->	
}
/*===DoctorŬ���� ������===*/
void Doctor::set_PatientInfo(string pName, int rDate, int rTime) {
	this->patientName = pName;
	this->resvDate = rDate;
	this->resvTime = rTime;


}

