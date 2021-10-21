/*
Problem:
https://practice.geeksforgeeks.org/problems/reverse-an-array/0
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

void reverseArr (vector <int> nums)
{
    for (int i = 0; i < nums.size()/2; i++)
        swap(nums[i],nums[nums.size()-i-1]);

    for (int i = 0; i <nums.size(); i++)
        cout << nums[i] << " ";

    cout << endl;
    return;
}

int main()
{
    int t;
    cin >> t;
    cin.ignore(32767,'\n');
    while (t > 0)
    {
        int n;
        cin >> n;
        cin.ignore(32767, '\n');

        vector <int> nums = accept();
        reverseArr(nums);
        t--;
    }
    return 0;
}