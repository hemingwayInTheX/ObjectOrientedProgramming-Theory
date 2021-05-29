#include <iostream>
#define MAX_SIZE 100
using namespace std;

template <typename T>
class Stack {
public:
	/*CONSTRUCTOR*/
	Stack() { top = -1; }
	/*FUNCTION*/
	void push(T x);
	T pop();
private:
	int top;
	T stackArr[MAX_SIZE];
};

int main(void) {
	Stack<int>s1;
	for (int i = 0; i < 5; i++){
		s1.push(i);
	}
	cout<<"INTEGER = "<<s1.pop()<<endl;
	
	Stack<double>s2;
	s2.push(4.3);
	cout<<"DOUBLE = "<<s2.pop()<<endl;

	system("pause");
	return 0;
}
template <typename T>
void Stack<T>::push(T x) {
	if (top == 99) {
		cout << "ERROR::There are no spacious!!!" << endl;
		return;
	}
	stackArr[++top] = x;
}

template <typename T>
T Stack<T>::pop() {
	T item;
	if (top == -1) {
		cout << "ERROR::Stack is empty!!!" << endl;
		return 0;
	}
	item = stackArr[top--];
	return item;
}