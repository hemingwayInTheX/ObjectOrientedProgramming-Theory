#include <iostream>
using namespace std;
/*재귀함수의 호출 순서 뉘앙스를 생각해보자.*/
/*생성자의 호출 순서는 부모 클래스 부터 자식 클래스 순으로!*/
class TV {
public:
	TV() { size = 20; }
	TV(int size) { this->size = size; }/*1. 상위 클래스 생성자 부터 호출*/
	int getSize() { return size; }
private:
	int size;
};

class WideTV : public TV {
public:
	WideTV(int size, bool videoln) :TV(size) {this->videoln = videoln;}/*2. 그 다음 호출*/
	bool getVideoln() { return videoln; }
private:
	bool videoln;
};

class SmartTV :public WideTV {
public:
	SmartTV(string ipAdrr, int size) :WideTV(size, true) {this->ipAddr = ipAddr;}/*마지막 호출*/
	string getIpAddr() { return ipAddr; }
private:
	string ipAddr;
};

int main() {
	SmartTV htv("192.0.0.1", 32);
	cout << "size = " << htv.getSize() << endl;
	cout << "videoln = " <<boolalpha<<htv.getVideoln() << endl;
	cout << "IP = " << htv.getIpAddr() << endl;
}