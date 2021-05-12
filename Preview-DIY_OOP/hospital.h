#include <iostream>
#include <string>
using namespace std;

#ifndef HOSPITAL_H
#define HOSPITAL_H

class Doctor {
public:
	/*Constructor*/
	Doctor() {//스케줄 초기화
		for (int i = 0; i < 4; i++){
			for (int j = 0; j < 5; j++){
				schedule[i][j] = { "----" };
			}
		}
	}
	/*Function*/
	void set_DcName(string doctorName) { this->doctorName = doctorName; }//의사 이름 저장
	void setName(string patientName);
	void set_PatientInfo(string pName, int rDate, int rTime);//예약정보 저장
	void reset_PatientInfo(string patientName);//취소 시 예약정보 초기화
private:
	string schedule[4][5]; //주 5일, 1당 4개 스케줄
	string patientName; // 고객 정보(이름)-->Parameter
	string doctorName; //의사 정보(이름)
	int resvDate; // 예약날짜 -->Parameter
	int resvTime;// 예약시간 -->Parameter
};

class Department {
public:
	/*Constructor & Destructor*/
	Department() {//한 부서당 의사 한 명
		dc = new Doctor();
		dc->set_DcName("jonas");
	}
	~Department() { delete dc; }
	/*Function*/
	void set_deptName(string deptName) { this->deptName = deptName; }//부서 이름 저장
	void reservation(int date, int time, string clientName);//예약
	void cancel(string clientName);//취소
	void display_status();//현황 출력
private:
	Doctor* dc;
	string clientName;//고객이름 --> Parameter
	string deptName;//부서명 -->Parameter
	int date;//날짜
	int time;//시간
};

class Hospital {
public:
	/*Constructor & Destructor*/
	Hospital(){//4개 진료부서 초기화
		department = new Department[4];
		department[0].set_deptName("a");
		department[1].set_deptName("b");
		department[2].set_deptName("c");
		department[3].set_deptName("d");
	}
	~Hospital() { delete[]department; }
	/*Function*/
	void execute_prog();//프로그램 실행
private:
	Department* department;
	int menu;
	int selectDept;
	int selectDate;
	int selectTime;
	string name;
};

class Console {
public:
	static int select_menu();//메뉴입력
	static int select_dept();//진료부서 선택
	static int select_date();//날짜 입력
	static int select_time();//시간 입력
	static string input_name();//이름 입력
};

#endif // !HOSPITAL_H
