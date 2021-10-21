/*
Problem:
https://practice.geeksforgeeks.org/problems/rotate-array-by-n-elements/0
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

void rotateArr (vector <int> nums, int k)
{
    for (int i = 0; i < k; i++)
        nums.push_back(nums[i]);

    nums.erase(nums.begin(), nums.begin() + k);

    for (int i = 0; i < nums.size(); i++)
        cout << nums[i] << " ";
}

int main()
{
    int t;
    cin >> t;
    cin.ignore(32767,'\n');
    while (t > 0)
    {
        vector <int> pars = accept();
        int n = pars[0];
        int k = pars[1];

        vector <int> nums = accept();
        rotateArr(nums,k);
        cout << endl;
        t--;
    }
    return 0;
}