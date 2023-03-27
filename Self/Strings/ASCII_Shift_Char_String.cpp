/*
https://www.tutorialcup.com/interview/string/perform-string-shifts-leetcode.htm
*/

#include <bits/stdc++.h>
using namespace std;
string shift(string s, int a[], int n){
    for(int i=n-2; i>=0; i--){
        a[i] += a[i + 1];
        a[i] %= 26;
    }
    
    for(int i=0; i<n; i++) {
        s[i] = (((s[i] - 'a') + a[i]) % 26 + 'a');
    }
    
    return s;
}
int main(){
    string s = "string";
    int a[] = {4, 1, 2, 7, 1, 3};
    int n = sizeof(a)/sizeof(a[0]);
    cout<<shift(s, a, n);
    return 0;
}