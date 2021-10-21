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

int findMax (vector <int> nums)
{
	vector <int> :: iterator it;
	int max = nums[0];
	for (it = nums.begin()+1; it != nums.end(); it++)
		if (*it > max)
			max = *it;
	return max;
}

int findMin (vector <int> nums)
{
	vector <int> :: iterator it;
	int min = nums[0];
	for (it = nums.begin()+1; it != nums.end(); it++)
		if (*it < min)
			min = *it;
	return min;
}

int main()
{
	int n;
	cin >> n;
	cin.ignore(32767, '\n');
	vector <int> nums = accept();
	int max = findMax(nums);
	int min = findMin(nums);
	cout << min << " " << max << endl;
	return 0;
}