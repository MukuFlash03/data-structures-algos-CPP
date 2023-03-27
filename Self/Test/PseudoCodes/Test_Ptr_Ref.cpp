#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a = 10, *pa, &ra=a;
    pa = &a;
    ra = a;
    cout << a << " = " << ra << endl;
    return 0;
}