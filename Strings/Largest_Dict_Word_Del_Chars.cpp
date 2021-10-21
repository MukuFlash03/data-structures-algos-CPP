// C++ program to find largest word in Dictionary 
// by deleting some characters of given string 
#include <bits/stdc++.h> 
using namespace std; 

// Returns true if str1[] is a subsequence of str2[]. 
// m is length of str1 and n is length of str2 
bool isSubSequence(string str1, string str2) 
{ 
	int m = str1.length(), n = str2.length(), j = 0;

	for (int i=0; i<n&&j<m; i++) 
		if (str1[j] == str2[i]) 
			j++; 

	// If all characters of str1 were found in str2 
	return (j==m); 
} 
 
string findLongestString(vector <string > dict, string str) 
{ 
	string result = ""; 
	int length = 0; 

	for (string word : dict) 
	{
		if (length < word.length() && isSubSequence(word, str)) 
		{ 
			result = word; 
			length = word.length(); 
		} 
	} 
	return result; 
} 

int main() 
{ 
	vector <string > dict = {"ale", "apple", "monkey", "plea"}; 
	string str = "abpcplea" ; 
	cout << findLongestString(dict, str) << endl; 
	return 0; 
}