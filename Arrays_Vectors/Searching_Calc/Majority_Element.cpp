/*
Problem:
https://practice.geeksforgeeks.org/problems/majority-element/0
*/

#include <bits/stdc++.h>
using namespace std;

/*
vector <string> accept (int n)
{
    vector <string> nums;
    string str,word;
    getline(cin,str);
    stringstream ss(str);
    while(getline(ss,word,' '))
        nums.push_back(word);
    return nums;
}
*/

string majorElem (vector <string> nums)
{
    int n = nums.size();
    map <string, int> numFreq;
    for (int i = 0; i < n; i++)
    {
        if (numFreq.find(nums[i]) == numFreq.end())
            numFreq[nums[i]] = 1;
        else if (numFreq.find(nums[i]) != numFreq.end())
            numFreq[nums[i]]++;
    }
        

    map <string, int> :: iterator m;
    /*
    for (m = numFreq.begin(); m != numFreq.end(); m++)
        cout << m->first << "\t" << m->second << endl;
    */

    for (m = numFreq.begin(); m != numFreq.end(); m++)
    {
        int count = m -> second;
        if (count > n/2)
           return m -> first;
    }
    return "-1";
}

int main()
{
    int t,n;
    cin >> t;
    cin.ignore(32767,'\n');
    while (t > 0)
    {
        cin >> n;
        cin.ignore(32767,'\n');
        vector <string> nums;
        string str,word;
        getline(cin,str);
        stringstream ss(str);
        while(getline(ss,word,' '))
            nums.push_back(word);
        cout << majorElem(nums) << endl;
        t--;   
    }
}