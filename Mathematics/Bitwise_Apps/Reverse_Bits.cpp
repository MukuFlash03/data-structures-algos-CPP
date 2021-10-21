/*
https://www.tutorialcup.com/interview/string/reverse-bits.htm
*/

#include <bits/stdc++.h>
using namespace std;
void Reverse(uint32_t n)
{
    for (int i = 0; i < 16; i++)
    {
        bool temp = (n & (1 << i));
        bool temp1 = (n & (1 << (31 - i)));
        if (temp1 != temp)
        {
            n ^= (1 << i);
            n ^= (1 << (31 - i));
        }
    }
    for (int i = 31; i >= 0; i--)
    {
        bool temp = (n & (1 << i));
        cout << temp;
    }
    cout << endl;
}
int main()
{
    uint32_t n;
    cin >> n;
    Reverse(n);
    return 0;
}