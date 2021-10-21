 /*
Problem:
https://www.geeksforgeeks.org/program-print-substrings-given-string/
https://www.geeksforgeeks.org/sum-of-all-substrings-of-a-string-representing-a-number/
*/

#include <bits/stdc++.h>
#include <iostream>
#include <boost/lexical_cast.hpp>
#include <vector>
using namespace std;

vector <string> getSubstrings (string str)
{
    int l = str.length();
    vector <string> strsub;

    for (int i = 0; i < l; i++)
        for (int j = 1; j <= l - i; j++)
            strsub.push_back(str.substr(i,j));

    /*
    cout << "Substring length order:" << endl;
    for (int i = 1; i <= l; i++)
        for (int j = 0; j <= l - i; j++)
            cout << str.substr(j,i) << endl;
    */

   return strsub;
}

int calcSubstrSum (vector <string> intsub)
{   
    vector <string> :: iterator i;
    int x, sum = 0;
    for (i = intsub.begin(); i != intsub.end(); i++)
    {
        x = boost :: lexical_cast <int> (*i);
        sum += x;
    }
    return sum;
}

int main()
{
    string s;
    getline(cin,s);
    vector <string> strsub = getSubstrings(s);
    cout << "String Substrings Character Occurrence Order:" << endl;
    for (int i = 0; i < strsub.size(); i++)
        cout << strsub[i] << endl;

    cout << endl;
    int n;
    cin >> n;
    cin.ignore(32767, '\n');
    vector <string> intsub = getSubstrings(boost :: lexical_cast <string> (n));
    int sum = calcSubstrSum(intsub);
    cout << "Required Integer Substring Sum = " << sum << endl;

   return 0;
}