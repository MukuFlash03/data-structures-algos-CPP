/*
Problem:
https://www.geeksforgeeks.org/reverse-alternate-k-characters-in-a-string/
*/

#include <bits/stdc++.h> 
using namespace std; 

string revAlternateK(string s, int k, int len) 
{ 

	for (int i = 0; i < s.size();)
    { 
		if (i + k > len) 
			break; 

		reverse(s.begin() + i, s.begin() + i + k); 

		i += 2 * k; 
	} 
	return s; 
} 

int main() 
{ 
	string s = "geeksforgeeks"; 
	int len = s.length(); 
	int k = 3; 
	cout << revAlternateK(s, k, len); 

	return 0; 
} 