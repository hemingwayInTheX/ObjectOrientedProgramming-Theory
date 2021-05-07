#include <iostream>
using namespace std;
#include "hospital.h"

int main() {
    Hospital* client = new Hospital();
    client->start();
    delete client;
}


