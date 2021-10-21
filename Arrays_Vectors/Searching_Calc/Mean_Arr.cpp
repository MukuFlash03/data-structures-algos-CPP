/*
Problem:
https://www.geeksforgeeks.org/mean-of-array-using-recursion/?ref=rp
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

float findMean (vector <int> nums, int n)
{
    if (n == 1)
        return (float)nums[n-1];
    else
        return ((float)(findMean(nums,n-1)*(n-1) + nums[n-1])/n);
}

int main()
{
    vector <int> nums = accept();
    float mean = findMean(nums,nums.size());
    cout << mean << endl;
    return 0;
}