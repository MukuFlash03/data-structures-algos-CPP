/*
Problem:
https://www.geeksforgeeks.org/extract-maximum-numeric-value-given-string/
https://practice.geeksforgeeks.org/problems/extract-maximum/0
*/

#include<bits/stdc++.h> 
using namespace std; 

int extractMaximum(string str) 
{ 
	int num = 0, res = 0; 

	for (int i = 0; i<str.length(); i++) 
	{ 
		if (str[i] >= '0' && str[i] <= '9') 
			num = num * 10 + (str[i]-'0'); 

		else
		{ 
			res = max(res, num); 
			num = 0; 
		} 
	} 
	return max(res, num); 
} 

int main() 
{ 
	string str;
    getline(cin,str);
	cout << extractMaximum(str) << endl; 
	return 0; 
} 
