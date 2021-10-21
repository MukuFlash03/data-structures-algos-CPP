#include <bits/stdc++.h>
using namespace std;

set <string> getSub (string str)
{
    set <string> subs;
    int l = str.length();
    for (int i = 0; i < l; i++)
        for (int j = 1; j <= l-i; j++)
            subs.insert(str.substr(i,j));

    return subs;
}

int checkPalin (string str)
{
    int l = str.length();
    
    for (int i = 0; i < l/2; i++)
        if (str[i] != str[l-i-1])
            return 0;

    return str.length();
}

void longPalin (string str)
{
    set <string> subs = getSub(str);
    set <string> :: iterator it;

    string word = "";
    int ans = 0, flag = 0;
    for (it = subs.begin(); it != subs.end(); it++)
    {
        flag = ans;
        ans = max(ans,checkPalin(*it));
        if (flag != ans)
            word = *it;   
    }
    cout << word << endl;
}


int main()
{
    string s;
    getline(cin,s);
    longPalin(s);
    return 0;
}