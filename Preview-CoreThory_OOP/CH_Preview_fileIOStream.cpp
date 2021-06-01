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
	int sizeIdx = 0;
	int inputKey = 0;//key�Է�
	string inputValue = "";//value �Է�

	/*FIRST INPUT & INSERT */
	cout << "INPUT KEY = "; cin >> inputKey;
	cout << "INPUT VALUE = "; cin >> inputValue;
	cout << "====================\n";
	mds[0].setDictonary(inputKey, inputValue);//ù ��° ��ü �迭 ������ �Ҵ�
	vec_my_ds_1d.push_back(mds[0]);//���Ϳ� ����
	/*SEARCH SAME KEY -->if(True) = renew value */
	for (int i = 0; i < 10; i++) {
		cout << "INPUT KEY = "; cin >> inputKey;
		cout << "INPUT VALUE = "; cin >> inputValue;
		cout << "====================\n";

		bool chkRenew = true;//���� key�� Ž�� �� ���� ���� üũ
		sizeIdx = vec_my_ds_1d.size();//���Ϳ� ���� �Ҵ� �� ��� �ش� ������ ����� �ε��� ������ Ȱ��

		for (int j = 0; j < vec_my_ds_1d.size(); j++) {
			if (vec_my_ds_1d[j].getKey1D() == inputKey) {//������ key���̸� value�� ����� �Է°����� ����
				vec_my_ds_1d[j].setValue(inputValue);
				chkRenew = false;
				break;//key�� ���� �� ���� Ż��
			}
		}
		if (chkRenew) {
			mds[sizeIdx].setDictonary(inputKey, inputValue);//ù ��° ��ü �迭 ������ �Ҵ�
			vec_my_ds_1d.push_back(mds[sizeIdx]);//���Ϳ� ����
		}
	}
	cout << "======AFTER INPUT======" << endl;
	for (int i = 0; i < vec_my_ds_1d.size(); i++) { //�Է� ���� ���� ���� ������ ���
		vec_my_ds_1d[i].display_vector();
	}
}

void Problem1_3() {
	vector<MyDataStructure<string, vector<MyDataStructure<string, double>>>> vec_my_ds_2d;//2���� ����
	vector<MyDataStructure<string, double>>vec_my_ds_1d;//1���� ����

	//MyDataStructure<string, double>* mds1 = new MyDataStructure<string, double>[30000];

	// �ϴ��� �ڵ� ���� ���� 
	// file read�� ���� ���� ����
	int sizeIdx = 0;
	int sizeIdx1 = 0;
	int sizeIdx2 = 0;
	int chkComma = 0;//��ǥ üũ ��ġ --> Ž�� �����ϸ� 1�� ����
	int chkValue = 0;
	ifstream read_file;
	string readLine;//csv���� �� �پ� ���� ������ ����
	string key1Genre;//�帣(key1)
	string key2Movie;//��ȭ�̸�(key2)
	string getValueGrade;//csv���� ������ grade�� �켱 string Ÿ�� --> ����ȯ �ʿ�
	double valueGrade;//����(value)
	// file open �� file�� ���°�� exception�� �߻���Ű�� ���� �ڵ�
	read_file.exceptions(ifstream::failbit | ifstream::badbit);
	read_file.open("movie.csv");//���� �о����
	while (!read_file.eof()) {
		getline(read_file, readLine);

		for (int i = 0; i < readLine.size(); i++) {//�о�� ���� ���̸�ŭ �ݺ��۾� ����
			if (readLine[i] == ',') {//��ǥ ������ Ȯ����ġ 1�� ����
				chkComma++;
				if (chkComma == 1) {//ù ��° ��ǥ ������ �� ���� ��ȭ �̸��� ������ key2Movie�� ����
					chkValue = i + 1;//���� ���ڿ��� ���۵Ǵ� �ε��� üũ
					key2Movie = readLine.substr(0, i);
				}
			}
			if (chkComma == 2) {//�� ��° ��ǥ ������ �ش� ��ǥ ���� ���ڿ��� ������ key1Genre�� ����
				getValueGrade = readLine.substr(chkValue, i - 1);//chkValue���� �� ���� ��ǥ �������� ���ڿ��� ������ �ش�
				valueGrade = stod(getValueGrade);//stod�޼��� ���� double ����ȯ

				key1Genre = readLine.substr(i + 1);
				chkComma = 0;//���� �ٿ� ���� �޸� ������ Ȯ���ϱ� ���� 0���� �ʱ�ȭ
				break;
			}
		}
		cout << "KEY1(genre) = " << key1Genre << '\t';
		cout << "KEY2(movie) = " << key2Movie << '\t';
		cout << "VALUE(grade) = " << valueGrade << endl;
		cout << "-----------------------------------------------------------------------" << endl;
		//if (vec_my_ds_1d.empty()) {//���Ͱ� �����̸�
		//	mds1[sizeIdx].setDictonary(key2Movie, valueGrade);//���� ���� ��ü ����
		//	vec_my_ds_1d.push_back(mds1[sizeIdx]);
		//	MyDataStructure<string, vector<MyDataStructure<string, double>>> mds2(key1Genre, vec_my_ds_1d);//�ܺ� ���� ��ü ����
		//	vec_my_ds_2d.push_back(mds2);
		//}
		//else {//���Ͱ� ������ �ƴϸ�
		//	bool chkRenew1 = true;//���� key�� Ž�� �� ���� ���� üũ
		//	bool chkRenew2 = true;//���� key�� Ž�� �� ���� ���� üũ

		//	sizeIdx2 = vec_my_ds_1d.size();//���Ϳ� ���� �Ҵ� �� ��� �ش� ������ ����� �ε��� ������ Ȱ��
		//	sizeIdx1 = vec_my_ds_2d.size();//���Ϳ� ���� �Ҵ� �� ��� �ش� ������ ����� �ε��� ������ Ȱ��
		//	for (int j = 0; j < vec_my_ds_2d.size(); j++) {
		//		if (vec_my_ds_2d[j].getKey2D() == key1Genre) {//������ KEY1���̸� ���� ���� KEY2 �������� Ž��
		//			chkRenew1 = false;//���� key�� Ž�� �� ���� ���� üũ
		//			for (int k = 0; k < vec_my_ds_1d.size(); k++) {
		//				if (vec_my_ds_1d[k].getKey1D() == key2Movie) {//������ KEY1���̸� ���� ���� KEY2 �������� Ž��
		//					vec_my_ds_1d[k].setValue(valueGrade);
		//					chkRenew2 = false;
		//				}
		//			}
		//			if (chkRenew2) {
		//				mds1[sizeIdx2].setDictonary(key2Movie, valueGrade);
		//				vec_my_ds_1d.push_back(mds1[sizeIdx2]);
		//			}
		//		}
		//		if (chkRenew1) {
		//			MyDataStructure<string, vector<MyDataStructure<string, double>>> mds2(key1Genre, vec_my_ds_1d);//�ܺ� ���� ��ü ����
		//			vec_my_ds_2d.push_back(mds2);
		//		}
		//	}
	}
	// file ���� ����
	read_file.close();
}

int main() {
	//Problem1_2();
	Problem1_3();

	system("pause");
	return 0;
}