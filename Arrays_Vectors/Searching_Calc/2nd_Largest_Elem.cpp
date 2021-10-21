/*
Problem:
https://practice.geeksforgeeks.org/problems/second-largest/0
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
    int t,n;
    cin >> t;
    while (t > 0)
    {
        int n;
        cin >> n;
        cin.ignore(32767,'\n');
        vector <int> nums = accept();

        sort(nums.begin(), nums.end());
    
        cout << nums[nums.size()-2] << endl;
        t--;
    }
    return 0;
}