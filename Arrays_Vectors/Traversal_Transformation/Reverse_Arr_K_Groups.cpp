/*
Problem:
https://www.geeksforgeeks.org/reverse-an-array-in-groups-of-given-size/
*/

#include <bits/stdc++.h>
using namespace std;

vector <int> reverse(vector <int> arr,int k) 
{ 
    int n = arr.size();
	for (int i = 0; i < n; i += k) 
	{ 
		int left = i; 

		// to handle case when k is not multiple of n 
		int right = min(i + k - 1, n - 1);

		// reverse the sub-array [left, right] 
		while (left < right) 
			swap(arr[left++], arr[right--]);

	} 
    return arr;
} 

vector <int> accept ()
{
	vector <int> nums;
	string word;
	string str;
	getline(cin,str);
	stringstream ss(str);
	while (getline(ss,word,' '))
		nums.push_back(stoi(word));
	return nums;
}

int main() 
{ 
	vector <int> arr = accept();
	int k;
    cin >> k;
    cin.ignore(32767, '\n');

	arr = reverse(arr,k); 

	for (int i = 0; i < arr.size(); i++) 
		cout << arr[i] << " "; 
    cout << endl;
	return 0; 
}