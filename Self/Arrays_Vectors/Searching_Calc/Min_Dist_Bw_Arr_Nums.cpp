/*
Problem:
https://www.geeksforgeeks.org/find-the-minimum-distance-between-two-numbers/
https://practice.geeksforgeeks.org/problems/minimum-distance-between-two-numbers/1
*/

#include <bits/stdc++.h>
using namespace std;

vector <int> accept ()
{
    vector <int> nums;
    string str, word;
    getline(cin,str);
    stringstream ss(str);
    while (getline(ss, word, ' '))
        nums.push_back(stoi(word));

    return nums;
}

int minDist (vector <int> nums, int x, int y)
{
    int i, prev, minimum = INT_MAX;
    for (i = 0; i < nums.size(); i++)
    {
        if (nums[i] == x || nums[i] == y)
        {
            prev = i;
            break;
        }
    }
    
    for (; i != nums.size(); i++)
    {
        if (nums[i] == x || nums[i] == y)
        {
            if (nums[prev] != nums[i])
            {
                minimum = min(minimum, i - prev);
                prev = i;
            }
            else
                prev = i;
        }
    }
    if (minimum == INT_MAX)
        return -1;
    else
        return minimum;
}

int main()
{
    int t;
    cin >> t;
    cin.ignore(32767, '\n');
    while (t > 0)
    {
        int n,x,y, minimum;
        cin >> n;
        cin.ignore(32767,'\n');
        vector <int> nums = accept();
        vector <int> :: iterator it;
        vector <int> pars = accept();
        x = pars[0];
        y = pars[1];
        minimum = minDist(nums,x,y);
        cout << minimum << endl;
        t--;
    }
    return 0;
}