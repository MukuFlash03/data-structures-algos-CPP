#include <bits/stdc++.h>
using namespace std;

vector <int> charFreq(string s)
{
    vector <int> f(26,0);
    for (int i = 0; i < s.length(); i++)
        f[s[i]-'a']++;

    return f;
}

int main()
{
    string s1, s2;
    getline(cin,s1);
    getline(cin,s2);

    transform(s1.begin(), s1.end(), s1.begin(),::tolower);
    transform(s2.begin(), s2.end(), s2.begin(),::tolower);
    vector <int> f1 = charFreq(s1);
    vector <int> f2 = charFreq(s2);

    if (s1.length() != s2.length())
        cout << "Not Anagrams" << endl;

    bool flag = true;

    for (int i = 0; i < 26; i++)
    {
        cout << char(i+97) << "\t";
        cout << f1[i] << "\t" << f2[i] << endl;
    }
    for (int i = 0; i < 26; i++)
    {
        if (f1[i] != f2[i])
        {
            flag = false;
            break;
        }
    }

    if (flag)
        cout << "Anagrams" << endl;
    else
        cout << "Not Anagrams" << endl;
}