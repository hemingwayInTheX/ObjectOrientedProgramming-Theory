#include <iostream>
using namespace std;
#include "hospital.h"

int main() {
    Hospital* client = new Hospital();
    cout << "***** ��Ź������ ���Ű��� ȯ���մϴ� *****\n\n";
    client->execute_prog();
    delete client;

    system("pause");
    return 0;

}


