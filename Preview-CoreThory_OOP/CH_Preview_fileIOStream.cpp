#include <iostream>
#include <vector>
#include <fstream>
#include<string>
using namespace std;

/*====Ŭ���� �����====*/
template <typename T1, typename T2>
class MyDataStructure {
public:
	/*Constructor*/
	MyDataStructure() {//Default
		key = 0;
		value = "";
	}
	MyDataStructure(string a, double b) :key(a), value(b) {}//1���� ���Ϳ� �Ҵ�Ǵ� ��ü ������
	MyDataStructure(string a, vector<MyDataStructure<string, double>> vec) :key(a), value(vec) {}//2���� ���Ϳ� �Ҵ�Ǵ� ��ü ������
	/*Accessor & Mutator*/
	T1 getKey1D();//1���� ���� key�� ��ȯ
	T1 getKey2D();//2���� ���� key�� ��ȯ
	T2 getValue1D();//1���� ���� value�� ��ȯ
	void getValue2D();//2���� ���� value ���
	void setValue(T2 value);//1���� ���� value�� ����
	void setDictonary(T1 key, T2 value);//Problem1-2���� �ذ����� ������� �ʱ�ȭ �޼���
	/*Function*/
	void display_vector();
private:
	T1 key;//string
	T2 value;//double
};

/*====Ŭ���� ������====*/
template <typename T1, typename T2>
void MyDataStructure<typename T1, typename T2>::display_vector() { cout << key << "," << value << endl; }

template <typename T1, typename T2>
T1 MyDataStructure<typename T1, typename T2>::getKey1D() { return key; }

template <typename T1, typename T2>
T1 MyDataStructure<typename T1, typename T2>::getKey2D() { return key; }

template <typename T1, typename T2>
T2 MyDataStructure<typename T1, typename T2>::getValue1D() { return value; }

template <typename T1, typename T2>
void MyDataStructure<typename T1, typename T2>::getValue2D() {
	for (int i = 0; i < value.size(); i++) {
		if (i > 0) {
			cout << '\t' << '\t';
		}
		cout << "Key 2 = " << value[i].getKey1D() << '\t';
		cout << "Value = " << value[i].getValue1D() << endl;
	}
}

template <typename T1, typename T2>
void MyDataStructure<typename T1, typename T2>::setValue(T2 value) { this->value = value; }

template <typename T1, typename T2>
void MyDataStructure<typename T1, typename T2>::setDictonary(T1 key, T2 value) {
	this->key = key;
	this->value = value;
}

/*====�ذ��� �޼���====*/
void Problem1_2() {
	vector<MyDataStructure<int, string>>vec_my_ds_1d;//1���� ����
	MyDataStructure<int, string>mds[10];//ũ�� 10�� ��ü �迭 
	int idx = 1;
	int sizeCnt = 1;
	int inputKey = 0;//key�Է�
	string inputValue = "";//value �Է�

	/*FIRST INPUT & INSERT */
	cout << "INPUT KEY = "; cin >> inputKey;
	cout << "INPUT VALUE = "; cin >> inputValue;
	mds[0].setDictonary(inputKey, inputValue);//ù ��° ��ü �迭 ������ �Ҵ�
	vec_my_ds_1d.push_back(mds[0]);//���Ϳ� ����
	/*SEARCH SAME KEY -->if(True) = renew value */
	while (idx > 10) {//10���� �Է� ����
		cout << "INPUT KEY = "; cin >> inputKey;
		cout << "INPUT VALUE = "; cin >> inputValue;

		for (int i = 0; i < vec_my_ds_1d.size(); i++) {
			if (vec_my_ds_1d[i].getKey1D() == inputKey) {//������ key���̸� value�� ����� �Է°����� ����
				vec_my_ds_1d[i].setValue(inputValue);
			}
		}
		mds[idx].setDictonary(inputKey, inputValue);//ù ��° ��ü �迭 ������ �Ҵ�
		vec_my_ds_1d.push_back(mds[idx]);//���Ϳ� ����
		idx++;
	}

}

void Problem1_3() {
	vector<MyDataStructure<string, vector<MyDataStructure<string, double>>>> vec_my_ds_2d;//2���� ����
	vector<MyDataStructure<string, double>>vec_my_ds_1d;//1���� ����

	int idx = 0;
	int sizeCnt = 1;

	MyDataStructure <string, double> mds1("john", 21);//���ʸ� Ŭ���� ��ü ����
	MyDataStructure <string, double> mds2("amy", 20);
	MyDataStructure <string, double> mds3("mary", 23);

	vec_my_ds_1d.push_back(mds1);//���Ϳ� ��ü �Ҵ�
	vec_my_ds_1d.push_back(mds2);
	vec_my_ds_1d.push_back(mds3);

	MyDataStructure<string, vector<MyDataStructure<string, double>>> mds("student", vec_my_ds_1d);

	vec_my_ds_2d.push_back(mds);
	cout << "======BEFORE INPUT1======" << endl;
	cout << "Key1 = " << vec_my_ds_2d[0].getKey2D() << '\t';
	vec_my_ds_2d[0].getValue2D();

	cout << "======BEFORE INPUT2======" << endl;
	for (int i = 0; i < vec_my_ds_1d.size(); i++) { //�Է� ���� ���� ���� ������ ���
		vec_my_ds_1d[i].display_vector();
	}
	/*---INPUT---*/
	cout << "input key >>";
	string inputKey; cin >> inputKey;
	cout << "input value >>";
	double inputValue; cin >> inputValue;
	/*---SEARCH---*/
	while (idx < vec_my_ds_1d.size()) {//���� ��� ������ŭ ���� ���� --> �ε��� ���� Ư�� ������ ����� ���� Ż��
		if (vec_my_ds_1d[idx].getKey1D().compare(inputKey) == 0) {//����� �Է� key���� ������ ���� ���� key�� Ž��
			vec_my_ds_1d[idx].setValue(inputValue);//������ key�� Ž�� �� �ش� value���� ����� �Է°����� ������ ���� Ż��
			break;
		}
		idx++;//�ε��� ����
		sizeCnt++;//���� key�� ���� ��� ������ �� ������ ���� �Ҵ��ϱ� ���� üũ�ϴ� �ε��� ����
	}
	if (sizeCnt > vec_my_ds_1d.size()) {//������ key�� ������ �Է� �� ���Ϳ� �߰� ���� --> sizeCnt�� ������ ��Ұ��� ���� ũ�� ���� ����
		MyDataStructure <string, double> mds(inputKey, inputValue);//��ü����
		vec_my_ds_1d.push_back(mds);
	}

	cout << "======AFTER INPUT======" << endl;
	for (int i = 0; i < vec_my_ds_1d.size(); i++) { //�Է� ���� ���� ���� ������ ���
		vec_my_ds_1d[i].display_vector();
	}

	// �ϴ��� �ڵ� ���� ���� 
	// file read�� ���� ���� ����
	ifstream read_file;
	string csv_buf;//csv���� �о�� ������ ����
	// file open �� file�� ���°�� exception�� �߻���Ű�� ���� �ڵ�
	read_file.exceptions(ifstream::failbit | ifstream::badbit);
	read_file.open("movie.csv");//���� �о����
	while (!read_file.eof()) {
		getline(read_file, csv_buf, ',');
		cout << csv_buf << endl;
	}

	// file ���� ����
	read_file.close();
}

int main() {
	Problem1_2();
	//Problem1_3();

	system("pause");
	return 0;
}