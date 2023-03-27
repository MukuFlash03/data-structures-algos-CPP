#include <iostream>
using namespace std;
  
void printPattern(int n) 
{ 
    // Printing upper part 
    for (int i = 1; i <= n; i++)  
    { 
        for (int j = 1; j <= i; j++)  
            cout << i;         
        cout << "\n"; 
    } 
  
    // printing lower part 
    for (int i = n - 1; i > 0; i--)  
    { 
       for (int j = i; j > 0; j--)  
            cout << i;         
        cout << "\n"; 
    } 
} 
  
 int main() 
{ 
    int n;
    cout << "Enter number of rows: " << endl;
    cin >> n;
    printPattern(n); 
    return 0; 
} 