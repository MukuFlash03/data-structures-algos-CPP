#include <iostream>
using namespace std;

void pattern(int n)
{
    int k = 2*n - 2;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
            cout << " ";
        
        k -= 2;

        for (int j = 0; j <= i; j++)
        {
            //cout << "*"; Scalene Triangle!!!
            cout << "* ";  // Right-angled reverse triangle 
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cout << "Please enter number of rows to be printed in pattern: ";
    cin >> n;
    pattern(n);
    return 0;
}