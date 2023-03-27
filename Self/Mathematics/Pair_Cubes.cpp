// C++ program to count pairs whose sum of cubes is N 

#include<bits/stdc++.h> 
using namespace std; 

// Function to count the pairs satisfying 
// a ^ 3 + b ^ 3 = N 
int countPairs(int N) 
{ 
	int count = 0; 

	// Check for each number 1 to cbrt(N) 
	for (int i = 1; i <= cbrt(N); i++) 
	{ 
		// Store cube of a number 
		int cb = i*i*i; 

		// Subtract the cube from given N 
		int diff = N - cb; 

		// Check if the difference is also 
		// a perfect cube 
		int cbrtDiff = cbrt(diff); 

		// If yes, then increment count 
		if (cbrtDiff*cbrtDiff*cbrtDiff == diff) 
			count++; 
	} 

	// Return count 
	return count; 
} 

// Driver program 
int main() 
{ 
	int t;
	cin >> t;
	while (t > 0)
	{
	    int n;
	    cin >> n;
	    cout << countPairs(n); 
        t--;
	}
	return 0; 
}