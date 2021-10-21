/*
Problem:
https://www.geeksforgeeks.org/program-sort-string-descending-order/
https://practice.geeksforgeeks.org/problems/sort-the-string-in-descending-order/0
*/

#include <bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 26;

vector <int> charFreq (string str)
{
    vector <int> freq(MAX_CHAR,0);
    for (int i = 0; i < str.length(); i++)
        freq[str.at(i) - 'a']++;
    
    return freq;
}

void printStr (vector <int> freq)
{
    for (int i = MAX_CHAR - 1; i >= 0 ; i--)
    {
        while (freq[i] > 0)
        {
            cout << (char)(i + 'a');
            freq[i]--;
        }
    }
    cout << endl;
}

int main()
{
    string str;
    getline(cin,str);
    vector <int> freq = charFreq(str);
    printStr(freq);
    return 0;
}