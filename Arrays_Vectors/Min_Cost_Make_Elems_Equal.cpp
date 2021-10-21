/*
https://www.geeksforgeeks.org/minimum-cost-to-make-all-array-elements-equal/
*/


// C++ implementation of the approach 
#include <bits/stdc++.h> 
using namespace std; 

// Function to return the minimum cost 
// to make each array element equal 
int minCost(int arr[], int n) 
{ 
	// To store the count of even numbers 
	// present in the array 
	int count_even = 0; 

	// To store the count of odd numbers 
	// present in the array 
	int count_odd = 0; 

	// Iterate through the array and 
	// find the count of even numbers 
	// and odd numbers 
	for (int i = 0; i < n; i++) { 
		if (arr[i] % 2 == 0) 
			count_even++; 
		else
			count_odd++; 
	} 

	return min(count_even, count_odd); 
} 

// Driver code 
int main() 
{ 
	int arr[] = { 1,2,3,4,5 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 

	cout << minCost(arr, n); 

	return 0; 
}