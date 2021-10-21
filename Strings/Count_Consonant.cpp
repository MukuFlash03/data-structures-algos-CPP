/*
Problem:
https://www.geeksforgeeks.org/count-consonants-string-iterative-recursive-methods/?ref=rp
*/

#include <iostream>
using namespace std;

bool isConsonant(char ch) 
{ 
	ch = toupper(ch); 

	return !(ch == 'A' || ch == 'E' || 
			ch == 'I' || ch == 'O' || 
			ch == 'U') && ch >= 65 && ch <= 90; 
}
int totalConsonants(string str, int n) 
{ 
	if (n == 1) 
		return isConsonant(str[0]); 

	return totalConsonants(str, n - 1) + 
		isConsonant(str[n-1]); 
} 
 
int main() 
{ 
	string str;
    getline(cin,str);
	cout << totalConsonants(str, str.length()) << endl; 
	return 0; 
}