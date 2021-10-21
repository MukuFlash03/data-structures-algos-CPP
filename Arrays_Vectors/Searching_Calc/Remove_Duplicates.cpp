/*
Problem:
https://practice.geeksforgeeks.org/problems/remove-duplicate-elements-from-sorted-array/1
*/

#include <bits/stdc++.h>
using namespace std;

set <int> accept ()
{
    set <int> nums;
    string word = "", str = "";
    getline(cin,str);
    stringstream ss(str);
    while(getline(ss,word,' '))
        nums.insert(stoi(word));
    return nums;
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
        set <int> nums = accept();
        set <int> :: iterator it;

        for (it = nums.begin(); it != nums.end(); it++)
            cout << *it << " ";
        cout << endl;
        
        t--;
    }
    return 0;
}