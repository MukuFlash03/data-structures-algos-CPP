/*
Problem:
https://practice.geeksforgeeks.org/problems/add-binary-strings/0
*/

#include <bits/stdc++.h>
using namespace std;

int binToDec (string str)
{
   int mult = 0;
   for (int i = str.length() - 1; i >= 0;  i--)
        mult += (int)(str[i] - '0') * pow(2,str.length()-1-i); 

    return mult;
}

string decToBin (int num)
{
    string str = "";
    int binaryNum[32]; 
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

string calcSum (string s1, string s2)
{
    int a = binToDec(s1);
    int b = binToDec(s2);
    int num = a + b;
    string sum = decToBin(num);
    return sum;
}

int main()
{
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);
    string sum = calcSum(s1,s2);
    cout << sum << endl;
    return 0;
}