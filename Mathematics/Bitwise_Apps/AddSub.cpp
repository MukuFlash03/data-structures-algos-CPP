#include <bits/stdc++.h> 
using namespace std; 

int Add(int x, int y) 
{ 
	// Iterate till there is no carry 
	while (y != 0) 
	{ 
		// carry now contains common 
		//set bits of x and y 
		int carry = x & y;

		// Sum of bits of x and y where at 
		//least one of the bits is not set 
		x = x ^ y;

        y = carry << 1;
	} 
	return x; 
}

int Subtract(int x, int y) 
{ 
    // Iterate till there 
    // is no carry 
    while (y != 0) 
    { 
        // borrow contains common  
        // set bits of y and unset 
        // bits of x 
        int borrow = (~x) & y; 
  
        // Subtraction of bits of x  
        // and y where at least one 
        // of the bits is not set 
        x = x ^ y; 
  
        // Borrow is shifted by one  
        // so that subtracting it from 
        // x gives the required sum 
        y = borrow << 1; 
    } 
    return x; 
} 

int main() 
{ 
    int a,b;
    cin >> a >> b;
	cout << "Sum: " << Add(a, b) << endl;
    cout << "Difference: " << Subtract(a, b) << endl; 
	return 0; 
}