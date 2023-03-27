// CPP program to print a hollow pyramid pattern 
#include <iostream> 
using namespace std; 
void printPattern(int); 
int main() 
{ 
	int n;
    cout << "Enter number of rows: ";
    cin >> n;
    printPattern(n) ;
} 
void printPattern(int n) 
{ 
	int i, j, k = 0; 
	for (i = 1; i < n; i++)
	{ 
		// Print spaces 
		for (j = i; j < n; j++)
			cout << " "; 

		while (k != 2*i-1)
        { 
			if (k == 0 || k == 2*i-2) 
				cout << "#"; 
			else
				cout << " "; 
			k++;
		} 
		k = 0; 
		cout << endl; // print next row 
	} 
	// print last row 
	for (i = 0; i < 2*n-1; i++)
		cout << "#";
} 
