/*
Problem URL
https://www.geeksforgeeks.org/string-k-distinct-characters-no-characters-adjacent/?ref=rp
*/

#include <bits/stdc++.h>
using namespace std;

string generateString (int n, int k)
{
    string res = "", word = "";
    int q = n/k, r = n%k;

    for (int i = 0; i < k; i++)
        res += (char)('a' + i);
        
    while (q > 0)
    {
        word += res;
        q--;
    }

    for (int i = 0; i < r; i++)
        word += res[i];
    
    return word;
}

int main()
{
    int n, k;
    cin >> n;
    cin.ignore(32767, '\n');
    cin >> k;
    cin.ignore(32767, '\n');
    
    string str = generateString (n,k);
    cout << str << endl;
    return 0;
}