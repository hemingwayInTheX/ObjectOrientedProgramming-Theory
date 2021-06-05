#include <iostream>
#include <string>
#include <vector>
using namespace std;

#ifndef HOSPITAL_H
#define HOSPITAL_H

class Doctor {
public:
	/*Constructor*/
	Doctor() {//������ �ʱ�ȭ
		patientName = { "----\t" };
		for (int i = 0; i < 4; i++){
			for (int j = 0; j < 5; j++){
				schedule[i][j] = patientName;
			}
		}
	}
	/*Function*/
	void set_DcName(string doctorName) { this->doctorName = doctorName; }//�ǻ� �̸� ����
	void set_PatientInfo(string pName, int rDate, int rTime);//�������� ����
	void reset_PatientInfo(string patientName);//��� �� �������� �ʱ�ȭ
	void getSche();
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
	Hospital() {}//4�� ����μ� �ʱ�ȭ
	~Hospital() {}
	/*Function*/
	void execute_prog();//���α׷� ����
	void activation_prog(int selection);//���α׷� Ȱ��ȭ --> �μ����� �Է°� ������� ���α׷� ���� 
private:
	Department* department;
	vector<Department> vec;
	int menu;
	int selectMethod;
	int selectDept;
	string clientName;
	string clientId;
	string clientPhone;
	//int selectDate;
	//int selectTime;
};

class Console {
public:
	static int select_menu();//�޴��Է�
	static int select_dept();//����μ� ����
	static int select_method();//������ ����
	//static int select_date();//��¥ �Է�
	//static int select_time();//�ð� �Է�
	//static string input_name();//�̸� �Է�
};

#endif // !HOSPITAL_H
