/*
Problem:
https://www.geeksforgeeks.org/check-half-string-character-frequency-character/?ref=rp
*/

#include <bits/stdc++.h> 
using namespace std; 
const int MAX_CHAR = 26; 

bool checkFreq(string s) 
{ 
	int count1[MAX_CHAR] = {0}; 
	int count2[MAX_CHAR] = {0}; 

	int n = s.length(); 
	if (n == 1) 
		return true; 

	for (int i=0,j=n-1; i<j; i++,j--) 
	{ 
		count1[s[i]-'a']++; 
		count2[s[j]-'a']++; 
	} 

	for (int i = 0; i<MAX_CHAR; i++) 
		if (count1[i] != count2[i]) 
			return false; 

	return true; 
} 

int main() 
{ 
	// String to be checked 
	string s;
    getline(cin,s); 

	if (checkFreq(s)) 
		cout << "Yes\n"; 
	else
		cout << "No\n"; 
	return 0; 
} 