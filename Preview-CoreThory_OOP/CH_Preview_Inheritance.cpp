#include <iostream>
using namespace std;
/*����Լ��� ȣ�� ���� ���ӽ��� �����غ���.*/
/*�������� ȣ�� ������ �θ� Ŭ���� ���� �ڽ� Ŭ���� ������!*/
class TV {
public:
	TV() { size = 20; }
	TV(int size) { this->size = size; }/*1. ���� Ŭ���� ������ ���� ȣ��*/
	int getSize() { return size; }
private:
	int size;
};

class WideTV : public TV {
public:
	WideTV(int size, bool videoln) :TV(size) {this->videoln = videoln;}/*2. �� ���� ȣ��*/
	bool getVideoln() { return videoln; }
private:
	bool videoln;
};

class SmartTV :public WideTV {
public:
	SmartTV(string ipAdrr, int size) :WideTV(size, true) {this->ipAddr = ipAddr;}/*������ ȣ��*/
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