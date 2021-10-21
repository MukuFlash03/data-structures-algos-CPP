// CPP program to round the given 
// integer to a whole number 
// which ends with zero. 
#include <bits/stdc++.h> 
using namespace std; 

// function to round the number 
int round(int n) 
{ 
	// Smaller multiple 
	int a = (n / 10) * 10; 
	
	// Larger multiple 
	int b = a + 10; 

	// Return of closest of two 
	return (n - a > b - n)? b : a; 
} 

// driver function 
int main()
{ 
	int t;
	cin >> t;
	cin.ignore(32767, '\n');
	while (t > 0)
    {
        int n;
        cin >> n;
        cin.ignore(32767,'\n');
	    cout << round(n) << endl; 
	    t--;
    }
	return 0; 
}