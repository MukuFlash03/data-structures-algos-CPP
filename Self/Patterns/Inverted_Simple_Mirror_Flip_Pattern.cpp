#include <iostream>
using namespace std;

void pattern(int n)
{

    for (int i = n; i > 0; i--)
    {
        for (int j = n-1; j >= i; j--) // Inner loop to create right triangle gaps on left side of pyramid 
        {
			cout << "  ";
		}

        for (int j = 1; j <= i; j++)
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