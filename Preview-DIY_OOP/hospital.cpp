#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

#include "hospital.h"

/*===Console클래스 구현부===*/
int Console::select_menu() {
	int inputMenu = 0;
	try{
		cout << "****원하시는 서비스를 선택하세요****" << endl;
		cout << "(1)진료 예약\n(2)예약 취소\n(3)예약 조회\n(4)예약 변경\n(5)종료\n";
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

int Console::select_method() {
	int inputMenu = 0;
	try {
		cout << "****예약 방식을 선택하세요****" << endl;
		cout << "(1)의료진 검색 예약\n(2)진료과 선택 예약\n";
		cin >> inputMenu;
		cin.ignore(INT_MAX, '\n');//버퍼비우기

		if (inputMenu > 2) {
			throw inputMenu;
		}
	}
	catch (int x) {
		cout << "WARNING! 잘못된 입력입니다!! 다시 입력해주세요~!\n";
		cin >> inputMenu;
	}
	return inputMenu;
}
//int Console::select_date() {
//	int inputDate = 0;
//	try {
//		cout << "****날짜를 선택해주세요****" << endl;
//		cout << "(1)월\t(2)화\t(3)수\t (4)목\t(5)금\n";
//		cin >> inputDate;
//		if (inputDate > 5) {
//			throw inputDate;
//		}
//	}
//	catch (int z) {
//		cout << "WARNING! 잘못된 입력입니다!! 다시 입력해주세요~!\n";
//		cin >> inputDate;
//	}
//	return inputDate;
//}
//int Console::select_time() {
//	int inputTime = 0;
//	try {
//		cout << "****시간을 선택해주세요****" << endl;
//		cout << "(1)오전 10:30\t(2)오전11:30\t(3)오후 13:20\t (4)오후 15:00\n";
//		cin >> inputTime;
//		cin.ignore(INT_MAX, '\n');//버퍼비우기
//		if (inputTime > 4) {
//			throw inputTime;
//		}
//		return inputTime;
//}
//	catch (int q) {
//		cout << "WARNING! 잘못된 입력입니다!! 다시 입력해주세요~!\n";
//		cin >> inputTime;
//	}
//	return inputTime;
//}
//string Console::input_name() {
//	string name;
//	cout << "고객님 성함을 입력해주세요 >>";
//	getline(cin, name);
//
//	return name;
//}

/*===Hospital클래스 구현부===*/
Hospital::Hospital() {
	department = new Department[10];//10개의 진료부서
	ifstream read_file;
	string readLine;//한 줄 읽어서 저장
	string deptName;
	int idx = 0;

	read_file.exceptions(ifstream::failbit | ifstream::badbit);
	read_file.open("department.txt");//텍스트파일 불러오기
	
	/*파일에서 진료부서명을 reading & reading된 데이터를 통해 각각의 객체배열 초기화*/
	while (!read_file.eof()) {//파일 끝 만나면 loop종료
		getline(read_file, readLine);
		deptName = readLine;//한개의 부서명 저장
		department[idx].set_deptName(deptName);
		vec.push_back(department[idx]);//벡터 저장
		idx++;//인덱스 증가
	}
}

void Hospital::execute_prog() {
	menu = Console::select_menu();//메뉴 선택(1.예약 / 2.취소 / 3.조회 /4.변경 / 5.종료)
	switch (menu){
	case 1: {//예약 실행
		selectDept = Console::select_dept();//진료부서 선택(1 ~ 25)
		activation_prog(selectDept);//활성화메서드 실행
		}
	case 2: {//취소 실행

	}
	case 3: {//조회 실행

	}
	case 4: {//변경 실행

	}
	case 5:
	}
}
void Hospital::activation_prog(int selection) {
}
