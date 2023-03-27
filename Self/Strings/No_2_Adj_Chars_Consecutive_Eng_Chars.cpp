/*
Problem URL
https://www.geeksforgeeks.org/rearrange-the-characters-of-the-string-such-that-no-two-adjacent-characters-are-consecutive-english-alphabets/?ref=rp
*/
 
#include <bits/stdc++.h> 
using namespace std; 

// Function that returns true if the current arrangement is valid 
bool check(string s) 
{ 
	for (int i = 0; i + 1 < s.size(); ++i) 
		if (abs(s[i] - s[i + 1]) == 1) 
			return false; 
	return true; 
} 

void generateString(string str) 
{ 
	string odd = "", even = ""; 

	for (int i = 0; i < str.size(); ++i)
    { 
		if (str[i] % 2 == 0) 
			even += str[i]; 
		else
			odd += str[i]; 
	} 

	sort(odd.begin(), odd.end()); 
	sort(even.begin(), even.end()); 

	if (check(odd + even)) 
		cout << odd + even << endl; 
	else if (check(even + odd)) 
		cout << even + odd << endl; 
	else
		cout << -1 << endl; 
} 
 
int main() 
{ 
	string str;
    getline(cin,str);
	generateString(str);
	return 0; 
}