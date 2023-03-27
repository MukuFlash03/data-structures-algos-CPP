// C++ program to input 
// a comma separated string 

#include <bits/stdc++.h> 
using namespace std; 

int main() 
{ 
	// Get the string 
	string str;
    getline(cin, str);

	vector<int> v; 

	// Get the string to be taken 
	// as input in stringstream 
	stringstream ss(str); 

	// Parse the string 
	for (int i; ss >> i;) { 
		v.push_back(i); 
		if (ss.peek() == ',' || ss.peek() == ' ')
			ss.ignore(); 
	} 

	// Print the words 
	for (size_t i = 0; i < v.size(); i++) 
		cout << v[i] << endl; 
}