#include <iostream> 
using namespace std; 

int main() 
{ 
	// Getting the size of array 
	int n = 3; 

	// Getting the array of size n 
	int a[] = { 1, 2, 3 }; 

	// Solution 
	int i = 0; 

	// Finding sum of the array elements 
	long sum = 0; 
	for (i = 0; i < n; i++)
		sum += a[i];

	// Dividing sum by size n 
	long x = sum / n; 

	// Print x, if found 
	if (x * n == sum) 
		cout<<x<<endl; 
	else
		cout<<("-1")<<endl; 
	
	return 0;
}