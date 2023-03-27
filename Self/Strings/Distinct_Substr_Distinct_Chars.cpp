/*
Problem:
https://www.geeksforgeeks.org/find-distinct-characters-in-distinct-substrings-of-a-string/?ref=rp
*/

#include <bits/stdc++.h> 
using namespace std; 

int countTotalDistinct(string str) 
{ 
	int cnt = 0; 
	set<string> strsub; // To store all the sub-strings 

	for (int i = 0; i < str.length(); ++i)
    { 
		string word = ""; // To store the current sub-string 
        set<char> ans; 	// To store the characters of the current sub-string 
	
		for (int j = i; j < str.length(); ++j)
        { 
			word += str[j]; 
			ans.insert(str[j]); 

			// If current sub-string hasn't been stored before 
			if (strsub.find(word) == strsub.end())
            { 
				strsub.insert(word); // Insert it into the set 
				cnt += ans.size(); // Update the count of distinct characters 
			} 
		} 
	} 
	return cnt; 
} 

int main() 
{ 
	string str;
    getline(cin,str);
	cout << countTotalDistinct(str) << endl; 
	return 0; 
}