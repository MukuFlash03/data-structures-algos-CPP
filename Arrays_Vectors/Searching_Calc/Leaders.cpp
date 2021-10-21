/*
Problem:
https://www.geeksforgeeks.org/leaders-in-an-array/
https://practice.geeksforgeeks.org/problems/leaders-in-an-array/0
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

void leaders (vector <int> nums)
{
    int max = nums[nums.size()-1];
    cout << max << " ";
    for (int i = nums.size() - 2; i >= 0; i--)
    {
        if (nums[i] >= max)
        {
            max = nums[i];
            cout << max << " ";
        }
    }
    cout << endl;
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
        leaders(nums);
        t--;
    }
    return 0;
}