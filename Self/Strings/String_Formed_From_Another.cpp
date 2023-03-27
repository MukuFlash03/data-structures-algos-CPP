/*
Problem:
https://www.geeksforgeeks.org/check-whether-second-string-can-formed-first-string-using-count-array/?ref=rp
*/

#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
const int MAX_NUM = 26;

vector <int> charFreq(string str)
{
    vector <int> freq(MAX_NUM,0);
    int n = str.length();
    transform(str.begin(), str.end(), str.begin(), ::tolower);

    for (int i = 0; i < n; i++)
        freq[str.at(i) - 'a']++;
    
    return freq;
}

vector <int> checkStr(vector <int> f1, vector <int> f2, int l2)
{   
    vector <int> check(2);
    int sum = INT_MAX;

    for(int i = 0; i < 26; i++)
    {
        if (f1[i] == 0 || f2[i] == 0)
            continue;
            
        if (f1[i] >= f2[i])
        {
            l2 = l2 - f2[i];
            sum = min(sum, f1[i]/f2[i]);
        }
    }

    //cout << sum << endl;
    //cout << l2 << endl;

    check[0] = (l2 == 0)? 1 : 0;
    check [1] = sum;
    return check;
}

int main()
{
    string s1, s2;
    getline(cin,s1);
    getline(cin,s2);
    vector <int> f1 = charFreq(s1);
    vector <int> f2 = charFreq(s2);
    vector <int> check = checkStr(f1,f2,s2.length());
    if (check[0])
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    cout << check[1] << endl;;
}