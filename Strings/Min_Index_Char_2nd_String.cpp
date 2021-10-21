/*
Problem:
https://www.geeksforgeeks.org/find-character-first-string-present-minimum-index-second-string/?ref=rp
*/

#include <bits/stdc++.h>
using namespace std;

int findChar (string str, string patt)
{
    //Hash table storing (character,first_index) tuples using map
    map <char, int> CharInd;
    int minind = INT_MAX;

    for (int i = 0; i < str.length(); i++)
        if (CharInd.find(str[i]) == CharInd.end())
            CharInd[str[i]] = i;
            
    for (int i = 0; i < patt.length(); i++)
    {
        if (CharInd.find(patt[i]) != CharInd.end())
        {
            //minind = CharInd[patt[i]];
            minind = min(minind, CharInd[patt[i]]);
        }
    }

    if (minind != INT_MAX)
        return minind;
    else
        return 0;


    
}

int main()
{
    string str, patt;
    getline(cin,str);
    getline(cin,patt);

    int index = findChar(str,patt);
    if (index == 0)
        cout << "No Character Present" << endl;
    else
        cout << "Minimum Index Character : " << (char)(str[index]) << " at index = " << index << endl;

    return 0;
}