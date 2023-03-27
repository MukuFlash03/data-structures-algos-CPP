/*
https://www.geeksforgeeks.org/length-longest-balanced-parentheses-prefix/?ref=rp
*/

// CPP Program to find length of longest balanced 
// parentheses prefix. 
#include <bits/stdc++.h> 
using namespace std; 

// Return the length of longest balanced parentheses 
// prefix. 
int maxbalancedprefix(char str[], int n) 
{ 
	int sum = 0; 
	int maxi = 0; 

	// Traversing the string. 
	for (int i = 0; i < n; i++) { 

		// If open bracket add 1 to sum. 
		if (str[i] == '(') 
			sum += 1; 

		// If closed bracket subtract 1 
		// from sum 
		else
			sum -= 1; 

		// if first bracket is closing bracket 
		// then this condition would help 
		if (sum < 0) 
			break; 

		// If sum is 0, store the index 
		// value. 
		if (sum == 0) 
			maxi = i + 1; 
	} 

	return maxi; 
} 

// Driven Program 
int main() 
{ 
	char str[] = "((()())())(("; 
	int n = strlen(str); 

	cout << maxbalancedprefix(str, n) << endl; 
	return 0; 
}