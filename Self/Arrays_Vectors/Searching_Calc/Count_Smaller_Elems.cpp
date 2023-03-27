/*
Problem:
https://www.geeksforgeeks.org/count-smaller-equal-elements-sorted-array/
https://practice.geeksforgeeks.org/problems/count-of-smaller-elements/0
*/

#include <bits/stdc++.h> 
using namespace std; 

vector <int> accept ()
{
    vector <int> nums;
    string word = "", str = "";
    getline(cin,str);
    stringstream ss(str);
    while(getline(ss,word,' '))
        nums.push_back(stoi(word));
    return nums;
}

int searchCount(vector <int> nums, int key) 
{ 
	int left = 0, right = nums.size() - 1, count = 0; 
	while (left <= right)
    { 
		int mid = (right + left) / 2;
		if (nums[mid] <= key)
        {
			count = mid + 1;
			left = mid + 1;
		}
		else
			right = mid - 1;
	}
	return count;
} 

int main()
{
    int t;
    cin >> t;
    cin.ignore(32767,'\n');
    while (t > 0)
    {
        int n,k;
        cin >> n;
        cin.ignore(32767, '\n');
        vector <int> nums = accept();
        cin >> k;
        cin.ignore(32767, '\n');
        
        int count = searchCount(nums,k);
        cout << count << endl;
        t--;
    }
    return 0;
}