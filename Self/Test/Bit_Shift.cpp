#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x = 24, y = 8, z;
    x = x/y;
    z = y << x;
    cout << z << endl;
    cout << (y << 0) << endl;
    cout << (y << 1) << endl;
    cout << (y << 2) << endl;
    cout << (y << 3) << endl;
    return 0;
}