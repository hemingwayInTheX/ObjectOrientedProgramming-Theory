#include <iostream>
#include <string>
using namespace std;

#ifndef HOSPITAL_H
#define HOSPITAL_H

class Doctor {
public:
	/*Constructor*/
	Doctor() {//������ �ʱ�ȭ
		for (int i = 0; i < 4; i++){
			for (int j = 0; j < 5; j++){
				schedule[i][j] = { "----" };
			}
		}
	}
	/*Function*/
	void set_DcName(string doctorName) { this->doctorName = doctorName; }//�ǻ� �̸� ����
	void setName(string patientName);
	void set_PatientInfo(string pName, int rDate, int rTime);//�������� ����
	void reset_PatientInfo(string patientName);//��� �� �������� �ʱ�ȭ
private:
	string schedule[4][5]; //�� 5��, 1�� 4�� ������
	string patientName; // �� ����(�̸�)-->Parameter
	string doctorName; //�ǻ� ����(�̸�)
	int resvDate; // ���೯¥ -->Parameter
	int resvTime;// ����ð� -->Parameter
};

class Department {
public:
	/*Constructor & Destructor*/
	Department() {//�� �μ��� �ǻ� �� ��
		dc = new Doctor();
		dc->set_DcName("jonas");
	}
	~Department() { delete dc; }
	/*Function*/
	void set_deptName(string deptName) { this->deptName = deptName; }//�μ� �̸� ����
	void reservation(int date, int time, string clientName);//����
	void cancel(string clientName);//���
	void display_status();//��Ȳ ���
private:
	Doctor* dc;
	string clientName;//���̸� --> Parameter
	string deptName;//�μ��� -->Parameter
	int date;//��¥
	int time;//�ð�
};

class Hospital {
public:
	/*Constructor & Destructor*/
	Hospital(){//4�� ����μ� �ʱ�ȭ
		department = new Department[4];
		department[0].set_deptName("a");
		department[1].set_deptName("b");
		department[2].set_deptName("c");
		department[3].set_deptName("d");
	}
	~Hospital() { delete[]department; }
	/*Function*/
	void execute_prog();//���α׷� ����
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
	static int select_menu();//�޴��Է�
	static int select_dept();//����μ� ����
	static int select_date();//��¥ �Է�
	static int select_time();//�ð� �Է�
	static string input_name();//�̸� �Է�
};

#endif // !HOSPITAL_H
