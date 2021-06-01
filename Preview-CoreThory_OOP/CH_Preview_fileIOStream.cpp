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
	int sizeIdx = 0;
	int inputKey = 0;//key입력
	string inputValue = "";//value 입력

	/*FIRST INPUT & INSERT */
	cout << "INPUT KEY = "; cin >> inputKey;
	cout << "INPUT VALUE = "; cin >> inputValue;
	cout << "====================\n";
	mds[0].setDictonary(inputKey, inputValue);//첫 번째 객체 배열 데이터 할당
	vec_my_ds_1d.push_back(mds[0]);//벡터에 저장
	/*SEARCH SAME KEY -->if(True) = renew value */
	for (int i = 0; i < 10; i++) {
		cout << "INPUT KEY = "; cin >> inputKey;
		cout << "INPUT VALUE = "; cin >> inputValue;
		cout << "====================\n";

		bool chkRenew = true;//동일 key값 탐색 후 갱신 여부 체크
		sizeIdx = vec_my_ds_1d.size();//벡터에 새로 할당 될 경우 해당 벡터의 사이즈가 인덱스 정보로 활용

		for (int j = 0; j < vec_my_ds_1d.size(); j++) {
			if (vec_my_ds_1d[j].getKey1D() == inputKey) {//동일한 key값이면 value를 사용자 입력값으로 갱신
				vec_my_ds_1d[j].setValue(inputValue);
				chkRenew = false;
				break;//key값 갱신 후 루프 탈출
			}
		}
		if (chkRenew) {
			mds[sizeIdx].setDictonary(inputKey, inputValue);//첫 번째 객체 배열 데이터 할당
			vec_my_ds_1d.push_back(mds[sizeIdx]);//벡터에 저장
		}
	}
	cout << "======AFTER INPUT======" << endl;
	for (int i = 0; i < vec_my_ds_1d.size(); i++) { //입력 이후 벡터 내부 데이터 출력
		vec_my_ds_1d[i].display_vector();
	}
}

void Problem1_3() {
	vector<MyDataStructure<string, vector<MyDataStructure<string, double>>>> vec_my_ds_2d;//2차원 벡터
	vector<MyDataStructure<string, double>>vec_my_ds_1d;//1차원 벡터

	//MyDataStructure<string, double>* mds1 = new MyDataStructure<string, double>[30000];

	// 하단의 코드 수정 금지 
	// file read를 위한 변수 선언
	int sizeIdx = 0;
	int sizeIdx1 = 0;
	int sizeIdx2 = 0;
	int chkComma = 0;//쉼표 체크 장치 --> 탐색 성공하면 1씩 증가
	int chkValue = 0;
	ifstream read_file;
	string readLine;//csv에서 한 줄씩 읽은 데이터 저장
	string key1Genre;//장르(key1)
	string key2Movie;//영화이름(key2)
	string getValueGrade;//csv에서 가져온 grade는 우선 string 타입 --> 형변환 필요
	double valueGrade;//평점(value)
	// file open 시 file이 없는경우 exception을 발생시키기 위한 코드
	read_file.exceptions(ifstream::failbit | ifstream::badbit);
	read_file.open("movie.csv");//파일 읽어오기
	while (!read_file.eof()) {
		getline(read_file, readLine);

		for (int i = 0; i < readLine.size(); i++) {//읽어온 줄의 길이만큼 반복작업 수행
			if (readLine[i] == ',') {//쉼표 만나면 확인장치 1씩 증가
				chkComma++;
				if (chkComma == 1) {//첫 번째 쉼표 만나면 그 이전 영화 이름만 추출해 key2Movie에 저장
					chkValue = i + 1;//평점 문자열이 시작되는 인덱스 체크
					key2Movie = readLine.substr(0, i);
				}
			}
			if (chkComma == 2) {//두 번째 쉼표 만나면 해당 쉼표 다음 문자열만 추출해 key1Genre에 저장
				getValueGrade = readLine.substr(chkValue, i - 1);//chkValue부터 두 번재 쉼표 이전까지 문자열이 평점에 해당
				valueGrade = stod(getValueGrade);//stod메서드 통해 double 형변환

				key1Genre = readLine.substr(i + 1);
				chkComma = 0;//다음 줄에 대한 콤마 정보를 확인하기 위해 0으로 초기화
				break;
			}
		}
		cout << "KEY1(genre) = " << key1Genre << '\t';
		cout << "KEY2(movie) = " << key2Movie << '\t';
		cout << "VALUE(grade) = " << valueGrade << endl;
		cout << "-----------------------------------------------------------------------" << endl;
		//if (vec_my_ds_1d.empty()) {//벡터가 공백이면
		//	mds1[sizeIdx].setDictonary(key2Movie, valueGrade);//내부 벡터 객체 생성
		//	vec_my_ds_1d.push_back(mds1[sizeIdx]);
		//	MyDataStructure<string, vector<MyDataStructure<string, double>>> mds2(key1Genre, vec_my_ds_1d);//외부 벡터 객체 생성
		//	vec_my_ds_2d.push_back(mds2);
		//}
		//else {//벡터가 공백이 아니면
		//	bool chkRenew1 = true;//동일 key값 탐색 후 갱신 여부 체크
		//	bool chkRenew2 = true;//동일 key값 탐색 후 갱신 여부 체크

		//	sizeIdx2 = vec_my_ds_1d.size();//벡터에 새로 할당 될 경우 해당 벡터의 사이즈가 인덱스 정보로 활용
		//	sizeIdx1 = vec_my_ds_2d.size();//벡터에 새로 할당 될 경우 해당 벡터의 사이즈가 인덱스 정보로 활용
		//	for (int j = 0; j < vec_my_ds_2d.size(); j++) {
		//		if (vec_my_ds_2d[j].getKey2D() == key1Genre) {//동일한 KEY1값이면 내부 벡터 KEY2 동일한지 탐색
		//			chkRenew1 = false;//동일 key값 탐색 후 갱신 여부 체크
		//			for (int k = 0; k < vec_my_ds_1d.size(); k++) {
		//				if (vec_my_ds_1d[k].getKey1D() == key2Movie) {//동일한 KEY1값이면 내부 벡터 KEY2 동일한지 탐색
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
		//			MyDataStructure<string, vector<MyDataStructure<string, double>>> mds2(key1Genre, vec_my_ds_1d);//외부 벡터 객체 생성
		//			vec_my_ds_2d.push_back(mds2);
		//		}
		//	}
	}
	// file 연결 해제
	read_file.close();
}

int main() {
	//Problem1_2();
	Problem1_3();

	system("pause");
	return 0;
}