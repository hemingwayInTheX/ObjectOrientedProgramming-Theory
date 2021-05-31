#include <iostream>
#include <vector>
#include <fstream>
#include<string>
using namespace std;

/*====클래스 선언부====*/
template <typename T1, typename T2>
class MyDataStructure {
public:
	/*Constructor*/
	MyDataStructure() {//Default
		key = 0;
		value = "";
	}
	MyDataStructure(string a, double b) :key(a), value(b) {}//1차원 벡터에 할당되는 객체 생성자
	MyDataStructure(string a, vector<MyDataStructure<string, double>> vec) :key(a), value(vec) {}//2차원 벡터에 할당되는 객체 생성자
	/*Accessor & Mutator*/
	T1 getKey1D();//1차원 벡터 key값 반환
	T1 getKey2D();//2차원 벡터 key값 반환
	T2 getValue1D();//1차원 벡터 value값 반환
	void getValue2D();//2차원 벡터 value 출력
	void setValue(T2 value);//1차원 벡터 value값 갱신
	void setDictonary(T1 key, T2 value);//Problem1-2문제 해결위한 멤버변수 초기화 메서드
	/*Function*/
	void display_vector();
private:
	T1 key;//string
	T2 value;//double
};

/*====클래스 구현부====*/
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

/*====해결할 메서드====*/
void Problem1_2() {
	vector<MyDataStructure<int, string>>vec_my_ds_1d;//1차원 벡터
	MyDataStructure<int, string>mds[10];//크기 10인 객체 배열 
	int idx = 1;
	int sizeCnt = 1;
	int inputKey = 0;//key입력
	string inputValue = "";//value 입력

	/*FIRST INPUT & INSERT */
	cout << "INPUT KEY = "; cin >> inputKey;
	cout << "INPUT VALUE = "; cin >> inputValue;
	mds[0].setDictonary(inputKey, inputValue);//첫 번째 객체 배열 데이터 할당
	vec_my_ds_1d.push_back(mds[0]);//벡터에 저장
	/*SEARCH SAME KEY -->if(True) = renew value */
	while (idx > 10) {//10번의 입력 수행
		cout << "INPUT KEY = "; cin >> inputKey;
		cout << "INPUT VALUE = "; cin >> inputValue;

		for (int i = 0; i < vec_my_ds_1d.size(); i++) {
			if (vec_my_ds_1d[i].getKey1D() == inputKey) {//동일한 key값이면 value를 사용자 입력값으로 갱신
				vec_my_ds_1d[i].setValue(inputValue);
			}
		}
		mds[idx].setDictonary(inputKey, inputValue);//첫 번째 객체 배열 데이터 할당
		vec_my_ds_1d.push_back(mds[idx]);//벡터에 저장
		idx++;
	}

}

void Problem1_3() {
	vector<MyDataStructure<string, vector<MyDataStructure<string, double>>>> vec_my_ds_2d;//2차원 벡터
	vector<MyDataStructure<string, double>>vec_my_ds_1d;//1차원 벡터

	int idx = 0;
	int sizeCnt = 1;

	MyDataStructure <string, double> mds1("john", 21);//제너릭 클래스 객체 생성
	MyDataStructure <string, double> mds2("amy", 20);
	MyDataStructure <string, double> mds3("mary", 23);

	vec_my_ds_1d.push_back(mds1);//벡터에 객체 할당
	vec_my_ds_1d.push_back(mds2);
	vec_my_ds_1d.push_back(mds3);

	MyDataStructure<string, vector<MyDataStructure<string, double>>> mds("student", vec_my_ds_1d);

	vec_my_ds_2d.push_back(mds);
	cout << "======BEFORE INPUT1======" << endl;
	cout << "Key1 = " << vec_my_ds_2d[0].getKey2D() << '\t';
	vec_my_ds_2d[0].getValue2D();

	cout << "======BEFORE INPUT2======" << endl;
	for (int i = 0; i < vec_my_ds_1d.size(); i++) { //입력 이전 벡터 내부 데이터 출력
		vec_my_ds_1d[i].display_vector();
	}
	/*---INPUT---*/
	cout << "input key >>";
	string inputKey; cin >> inputKey;
	cout << "input value >>";
	double inputValue; cin >> inputValue;
	/*---SEARCH---*/
	while (idx < vec_my_ds_1d.size()) {//벡터 요소 갯수만큼 루프 수행 --> 인덱스 값이 특정 범위를 벗어나면 루프 탈출
		if (vec_my_ds_1d[idx].getKey1D().compare(inputKey) == 0) {//사용자 입력 key값과 동일한 벡터 내의 key값 탐색
			vec_my_ds_1d[idx].setValue(inputValue);//동일한 key값 탐색 시 해당 value값을 사용자 입력값으로 갱신후 루프 탈출
			break;
		}
		idx++;//인덱스 증가
		sizeCnt++;//동일 key값 없을 경우 벡터의 새 공간에 값을 할당하기 위해 체크하는 인덱스 변수
	}
	if (sizeCnt > vec_my_ds_1d.size()) {//동일한 key값 없으면 입력 쌍 벡터에 추가 대입 --> sizeCnt가 벡터의 요소갯수 보다 크면 조건 실행
		MyDataStructure <string, double> mds(inputKey, inputValue);//객체생성
		vec_my_ds_1d.push_back(mds);
	}

	cout << "======AFTER INPUT======" << endl;
	for (int i = 0; i < vec_my_ds_1d.size(); i++) { //입력 이후 벡터 내부 데이터 출력
		vec_my_ds_1d[i].display_vector();
	}

	// 하단의 코드 수정 금지 
	// file read를 위한 변수 선언
	ifstream read_file;
	string csv_buf;//csv에서 읽어온 데이터 저장
	// file open 시 file이 없는경우 exception을 발생시키기 위한 코드
	read_file.exceptions(ifstream::failbit | ifstream::badbit);
	read_file.open("movie.csv");//파일 읽어오기
	while (!read_file.eof()) {
		getline(read_file, csv_buf, ',');
		cout << csv_buf << endl;
	}

	// file 연결 해제
	read_file.close();
}

int main() {
	Problem1_2();
	//Problem1_3();

	system("pause");
	return 0;
}