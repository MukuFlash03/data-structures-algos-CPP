#include <iostream>
using namespace std;

void full_pyramid(int n)
{
    int k = 2*n - 2;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
            cout << " ";
        k -= 1;

        for (int j = 0; j <= i; j++)
            cout << "* ";

        cout << endl;
    }
}

int main()
{
    int n;
    cout << "Please enter number of rows to be printed in pattern: ";
    cin >> n;
    full_pyramid(n);
    return 0;
}