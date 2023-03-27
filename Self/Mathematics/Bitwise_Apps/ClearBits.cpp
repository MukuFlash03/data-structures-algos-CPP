#include <iostream>
using namespace std;

int clearLSB(int num, int i)
{
    int mask = ~((1 << i+1 ) - 1);
    num &= mask;
    return num;
}

int clearMSB(int num, int i)
{
    int mask = (1 << i ) - 1;
    num &= mask;
    return num;
}

int main()
{
    int num, i;
    cin >> num >> i;
    cout << clearLSB(num,i) << endl;
    cout << clearMSB(num,i) << endl;
}