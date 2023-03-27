/*
Problem:
https://www.geeksforgeeks.org/print-all-distinct-circular-strings-of-length-m-in-lexicographical-order/?ref=rp
*/

#include <string>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void printDistinctCircular(string s, int m)
{
    set <string> circ_str;
    int l =s.length();
    s.append(s);

    // generate circular substrings of length m
    for (int i = 0; i < l; i++)
        circ_str.insert(s.substr(i,m));

    while ( !circ_str.empty() )
    {
        cout << *circ_str.begin() << endl;
        circ_str.erase(circ_str.begin());
    }
}

int main()
{
    string str;
    getline(cin,str);

    int m;
    cin >> m;

    printDistinctCircular(str,m);
}