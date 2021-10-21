#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k;
    cin >> k;
    int t = k;

    vector <int> dig;
    while (t>0)
    {
        dig.push_back(t%10);
        t /= 10;
    }
    sort(dig.begin(),dig.end());

    for(int i = 0; i < dig.size(); i++)
    {
        if (dig[i] == 0)    continue;
        cout << dig[i];
    }
    cout << endl;

    return 0;
}

// Negative nums!!! 