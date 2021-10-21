#include <iostream> 
using namespace std; 
 
void printPattern(int n) 
{ 
	int t; 

	// outer loop to print rows 
	for (int i = 1; i <= n; i++)
    { 

		// inner loop to print spaces 
		for (int j = i; j < n; j++) 
			printf("\t"); 

		t = i; // calculate initial value 

		for (int k = 1; k <= i; k++) // inner loop to print pattern 
        { 
			printf("%d\t\t", t); 
			t = t + n - k; 
		} 
		printf("\n"); 
	} 
} 

int main() 
{ 
	int n;
    cout << "Enter number of rows: ";
    cin >> n;
	printPattern(n); 
	return 0; 
} 