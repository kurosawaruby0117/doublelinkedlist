#include <iostream>
#include "double.h"
using namespace std;
int main() {
    LinkedList<int> listNew;

    for (int i = 1;i <=10;i++) {
        listNew.push_back(i);
    }
    listNew.showing();
    listNew.insert(5, 1818);
    listNew.showing();
}
