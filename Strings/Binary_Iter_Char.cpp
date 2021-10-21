/*
Problem:
https://www.geeksforgeeks.org/find-ith-index-character-in-a-binary-string-obtained-after-n-iterations/
https://practice.geeksforgeeks.org/problems/find-k-th-character-in-string/0#ExpectOP
*/

#include <bits/stdc++.h>
using namespace std;

string decToBin (int num)
{
    string str = "";
    int binaryNum[1000]; 
    int i = 0; 
    while (num > 0)
    {
        binaryNum[i] = num % 2; 
        num = num / 2; 
        i++; 
    }
    for (int j = i - 1; j >= 0; j--) 
        str += to_string(binaryNum[j]); 

    return str;
}

string binIter (int m, int n)
{
    string bin = decToBin(m);
    string str = "";
    while (n > 0)
    {
        str = "";
        for (int i = 0; i < bin.length(); i++)
            str += (bin[i] == '0')? "01" : "10";
        
        bin = str;
        n--;
    }
    return bin;
}

int main()
{
    string s1;
    getline(cin,s1);
    cout << s1 << endl;
    int m = (int)(s1[0] - '0');
    int k = (int)(s1[2] - '0');
    int n = (int)(s1[4] - '0');
    string s2 = binIter(m,n);
    cout << s2 << endl;
    cout << s2[k] << endl;
    return 0;
}