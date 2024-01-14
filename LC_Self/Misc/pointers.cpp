#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

void val1(int n) {
    cout << "Value: " << n << endl;
    cout << "Address: " << &n << endl << endl;
}

void val2(int* n) {
    cout << "Value: " << *n << endl;
    cout << "Address: " << n << endl << endl;
}

void val3(int& n) {
    cout << "Value: " << n << endl;
    cout << "Address: " << &n << endl << endl;
}


int main() {
    int n = 10;
    val1(n);
    val2(&n);
    val3(n);
    
    return 0;
}
