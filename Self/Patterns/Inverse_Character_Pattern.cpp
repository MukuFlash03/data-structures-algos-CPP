// C++ code to print inverse 
// pyramid pattern 
#include <bits/stdc++.h> 
using namespace std; 

// function to print the 
// inverse pyramid pattern 
void pyramid(int n)
{ 
	int i, j, num, gap;

	for (i = n; i >= 1; i--)
    {
        num = 'A';

		for (j = n-1; j >= i; j--) // Inner loop to create right triangle gaps on left side of pyramid 
        {
			cout << "  ";
		} 

		for (j = 1; j <= i; j++) // Inner loop to print characters on left side of pyramid 
			cout << (char) num++ << " "; 
		
		for (j = i - 1; j >= 0; j--) // Inner loop to print characters on right side of pyramid
			cout << (char) --num << " ";  
		cout<< endl; 
	} 
} 

int main() 
{ 
	int n;
    cout << "Enter number of rows: " << endl;
    cin >> n; 
	pyramid(n);
	return 0;
}