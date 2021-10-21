/*
Problem:
https://practice.geeksforgeeks.org/problems/find-first-repeated-character/0
*/

#include <bits/stdc++.h>
using namespace std;
const int MAX_NUM = 26;

int charFreq(string str)
{
    vector <int> freq(MAX_NUM,0);
    int n = str.length();

    for (int i = 0; i < n; i++)
    {
        if ((++freq[str[i] - 'a']) == 2)
            return (int)(str[i]);
    }

    return -1;
}

int main()
{
    string str;
    getline(cin,str);
    int res = charFreq(str);
    if (res == -1)
        cout << res << endl;
    else
        cout << (char)(res) << endl;
    return 0;
}