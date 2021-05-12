#include <iostream>
using namespace std;
#include "hospital.h"

int main() {
    Hospital* client = new Hospital();
    cout << "***** 현탁병원에 오신것을 환영합니다 *****\n\n";
    client->execute_prog();
    delete client;

    system("pause");
    return 0;

}


