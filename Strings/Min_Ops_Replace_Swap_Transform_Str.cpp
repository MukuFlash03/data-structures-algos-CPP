/*
https://www.geeksforgeeks.org/minimum-number-of-given-operations-required-to-convert-a-string-to-another-string/
*/

// C++ implementation of the approach 
#include <bits/stdc++.h> 
using namespace std; 

// Function to return the minimum operations 
// of the given type required to convert 
// string s to string t 
int minOperations(string s, string t, int n) 
{ 
	int ct0 = 0, ct1 = 0; 
	for (int i = 0; i < n; i++) { 

		// Characters are already equal 
		if (s[i] == t[i]) 
			continue; 

		// Increment count of 0s 
		if (s[i] == '0') 
			ct0++; 

		// Increment count of 1s 
		else
			ct1++; 
	} 

	return max(ct0, ct1); 
} 

// Driver code 
int main() 
{ 
	string s = "010", t = "101"; 
	int n = s.length(); 
	cout << minOperations(s, t, n); 

	return 0; 
}