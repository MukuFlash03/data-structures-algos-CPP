/*
https://www.geeksforgeeks.org/find-lexicographically-smallest-string-in-at-most-one-swaps/?ref=leftbar-rightbar
*/

// C++ implementation of the above approach 
#include <bits/stdc++.h> 
using namespace std; 

// Function to return the lexicographically 
// smallest string that can be formed by 
// swapping at most one character. 
// The characters might not necessarily 
// be adjacent. 
string findSmallest(string s) 
{ 
	int len = s.size(); 

	// Store last occurrence of every character 
	int loccur[26]; 

	// Set -1 as default for every character. 
	memset(loccur, -1, sizeof(loccur)); 

	for (int i = len - 1; i >= 0; --i) { 

		// Character index to fill 
		// in the last occurrence array 
		int chI = s[i] - 'a'; 
		if (loccur[chI] == -1) { 

			// If this is true then this 
			// character is being visited 
			// for the first time from the last 
			// Thus last occurrence of this 
			// character is stored in this index 
			loccur[chI] = i; 
		} 
	} 

	string sorted_s = s; 
	sort(sorted_s.begin(), sorted_s.end()); 

	for (int i = 0; i < len; ++i) { 
		if (s[i] != sorted_s[i]) { 

			// Character to replace 
			int chI = sorted_s[i] - 'a'; 

			// Find the last occurrence 
			// of this character. 
			int last_occ = loccur[chI]; 

			// Swap this with the last occurrence 
			swap(s[i], s[last_occ]); 
			break; 
		} 
	} 

	return s; 
} 

// Driver code 
int main() 
{ 
	string s = "geeks"; 
	cout << findSmallest(s); 
	return 0; 
}