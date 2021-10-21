/*
Problem:
https://www.geeksforgeeks.org/kth-smallestlargest-element-unsorted-array/
*/

#include <bits/stdc++.h>
using namespace std;

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
    vector <int> nums = accept();
    int k;
    cin >> k;
    cin.ignore(32767, '\n');

    sort(nums.begin(), nums.end());

    cout << nums[k-1] << endl;
    return 0;
}