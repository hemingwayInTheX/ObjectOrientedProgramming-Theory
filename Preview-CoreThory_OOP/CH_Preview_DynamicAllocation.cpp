/*CH_Preview_DynamicAllocation
		 <<<HOW TO USE DynamicAllcoation??>>> */
#include <iostream>
using namespace std;
/*					## (A)객체 배열 ##
	1. 디폴트 생성자 자동 호출 --> 매개변수 있는 생성자로 초기화 불가
	2. 소멸은 생성과 반대로 진행 --> EX) arr[2]-arr[1]-arr[0]
	3. 초기화는 각 원소 객체당 생성자 지정
	
					## (B)객체 동적할당 ##
	1. HEAP 영역에 필요한 만큼 원하는 타입의 동적 메모리 생성
	2. 생성자 지정해 초기화 가능
	3. delete --> ㄱ) 동적으로 할당하지 않는 포인터 변수를 해제할 때 runtimeError
							ㄴ) 동일한 포인터 변수를 두 번 해제할 때 runtimeError

					## (C)객체 배열 동적할당 ##
	1. 배열은 동적 할당시 초기화 불가
	2. delete시 [] 명시 -->생략 가능하지만 비정상적인 반환 발생*/

class Circle {
public:
	/*CONSTRUCTOR*/
	Circle();
	Circle(int r);
	/*DESTRUCTOR*/
	~Circle();
	/*MUTATOR*/
	void setRadius(int r);
	/*FUNCTION*/
	double getArea();
private:
	int radius;
};

int main(void) {
	cout << "=============A)객체 배열===============" << endl;
	Circle circleArr[5] = { Circle(),Circle(5), Circle(10), Circle(15), Circle(20), };/*A) 각 원소당 생성자 지정해 배열 초기화*/
	for (int i = 0; i < 5; i++){
		cout << i << "번째 원의 면적은 = " << " " << circleArr[i].getArea() << "입니다" << endl;
	}

	cout << "=============C)객체 배열 동적할당===============" << endl;
	int inputNum = 0;
	int inputR = 0;
	cout << "input>>"; cin >> inputNum;
	Circle* cir = new Circle[inputNum]/*(10)*/; /*C) 배열에 대한 동적할당은 초기화 불가*/

	for (int i = 0; i < inputNum; i++){/*각 객체마다 다른 반지름 입력해 초기화*/
		cout << "input radius>>"; cin >> inputR;
		cir[i].setRadius(inputR);
	}
	Circle* ptrCir = cir;
	for (int i = 0; i < inputNum; i++){/*출력*/
		cout << i << "번째 원의 면적은 = " << " " << ptrCir->getArea() << endl;
		ptrCir++;
	}

	delete[]cir;/*객체 배열 소멸 --> 생성과 반대로 작업 수행*/
	system("pause");
	return 0;
}

/*Circle 클래스 구현부*/
Circle::Circle() { 
	radius = 1; 
}
Circle::Circle(int r) { 
	radius = r;
}
Circle::~Circle() {
	cout << "소멸자 실행 radius = " << radius << endl;
}
void Circle::setRadius(int r) {
	radius = r;
}
double Circle::getArea() {
	return 3.14 * radius * radius;
}