#include <iostream>
#include <string>
using namespace std;

#include "hospital.h"

/*===Console클래스 구현부===*/
int Console::select_menu() {
	int inputMenu = 0;
	try{
		cout << "****원하시는 서비스를 선택하세요****" << endl;
		cout << "(1)진료 예약\n(2)예약 취소\n(3)예약 조회\n(4)나가기\n";
		cin >> inputMenu;
		cin.ignore(INT_MAX, '\n');//버퍼비우기

		if (inputMenu > 4) {
			throw inputMenu;
		}
	}
	catch (int x){
		cout << "WARNING! 잘못된 입력입니다!! 다시 입력해주세요~!\n";
		cin >> inputMenu;
	}
	return inputMenu;
}
int Console::select_dept() {
	int inputDept = 0;
	try {
		cout << "****희망하시는 진료부서를 선택하세요****" << endl;
		cout << "(1)내과\n(2)외과\n(3)피부과\n(4)이비인후과\n";
		cin >> inputDept;
		if (inputDept > 4) {
			//throw inputDept;
		}
	}
	catch (int x ) {
		cout << "WARNING! 잘못된 입력입니다!! 다시 입력해주세요~!\n";
		cin >> inputDept;
	}
	return inputDept;
}
int Console::select_date() {
	int inputDate = 0;
	try {
		cout << "****날짜를 선택해주세요****" << endl;
		cout << "(1)월\t(2)화\t(3)수\t (4)목\t(5)금\n";
		cin >> inputDate;
		if (inputDate > 5) {
			throw inputDate;
		}
	}
	catch (int z) {
		cout << "WARNING! 잘못된 입력입니다!! 다시 입력해주세요~!\n";
		cin >> inputDate;
	}
	return inputDate;
}
int Console::select_time() {
	int inputTime = 0;
	try {
		cout << "****시간을 선택해주세요****" << endl;
		cout << "(1)오전 10:30\t(2)오전11:30\t(3)오후 13:20\t (4)오후 15:00\n";
		cin >> inputTime;
		cin.ignore(INT_MAX, '\n');//버퍼비우기
		if (inputTime > 4) {
			throw inputTime;
		}
		return inputTime;
}
	catch (int q) {
		cout << "WARNING! 잘못된 입력입니다!! 다시 입력해주세요~!\n";
		cin >> inputTime;
	}
	return inputTime;
}
string Console::input_name() {
	string name;
	cout << "고객님 성함을 입력해주세요 >>";
	getline(cin, name);

	return name;
}

/*===Hospital클래스 구현부===*/
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
/*===Department클래스 구현부===*/
void Department::reservation(int date, int time, string clientName) {
	dc->set_PatientInfo(clientName, date, time);
}

void Department::display_status() {
	cout<<dc->	
}
/*===Doctor클래스 구현부===*/
void Doctor::set_PatientInfo(string pName, int rDate, int rTime) {
	this->patientName = pName;
	this->resvDate = rDate;
	this->resvTime = rTime;


}

