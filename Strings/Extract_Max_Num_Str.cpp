/*
Problem:
https://practice.geeksforgeeks.org/problems/extract-maximum/0
*/

#include <bits/stdc++.h>
using namespace std;

int maxNum (vector <int> nums);
int extractNum (string str);

int extractNum (string str)
{
    char ch = ' ';
    string word = "";
    vector <int> nums;
    
    for (int i = 0; i < str.length(); i++)
    {
        ch = str[i];
        if (isdigit(ch))
            word += ch;
        else
        {
            if (!word.empty())
            {
                nums.push_back(stoi(word));
                word.clear();
            }
        }
    }
    if (!word.empty())
    {
        nums.push_back(stoi(word));
        word.clear();
    }

    return maxNum(nums);
}

int maxNum (vector <int> nums)
{
    int num = 0;
    for (int i = 0; i < nums.size(); i++)
        num = max(num,nums[i]);
    
    return num;
}

int main()
{
    string str;
    getline(cin,str);
    int num = extractNum(str);
    cout << num << endl;
    return 0;
}