#include <iostream>
using namespace std;

void left_scalene(int n)
{
    int k = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
            cout << " ";
        
        k += 1;

        for (int j = 0; j <= i; j++)
        {
            cout << "*";
        }

        cout << endl;
    }
}

void right_scalene(int n)
{
    int k = 2*n -2;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
            cout << " ";
        
        k -= 2;

        for (int j = 0; j <= i; j++)
        {
            cout << "*";  // Right vertex Scalene Triangle 
        }

        cout << endl;
    }
}

int main()
{
    int n;
    cout << "Please enter number of rows to be printed in pattern: ";
    cin >> n;
    left_scalene(n);
    right_scalene(n);
    return 0;
}