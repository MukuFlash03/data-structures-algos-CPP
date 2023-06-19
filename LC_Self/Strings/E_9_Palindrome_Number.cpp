/*
Type: Two Pointers
https://www.youtube.com/watch?v=-gjxg6Pln50

Problem: https://leetcode.com/problems/palindrome-number/
Solution(s): 
    
YouTube
NC - https://www.youtube.com/watch?v=yubRKwixN-U
*/


/*

A. W/o Int to String conversion (Mathematical operations)

0. Be careful of edge cases
1. Return false if -ve number
2. Starting power of 10 = 10^(n-1), where n = number of digits.
3. Fetch first and last digit of number using '/' and '%' operations, respectively.
4. Compare these two and return false if do not match.
5. If digits matched, move on to inner digits where new power of 10 = 10^(prev power - 2).
6. Return true.


B. Two-Pointer Solution (Int to String conversion)

1. Return false if -ve number
2. Start l,r at 0,n-1.
3. Check if lowercase char matches for l,r; return false if no match.
4. Update l,r = l++, r--
5. Return true.


*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

bool isPalindrome(int x) {

    if (x < 0 || x == INT_MAX)
        return false;
    if (x == 0)
        return true;

    int first, last;
    int num = x;
    //MM: int len = ceil(log10(x+1))-1;
    //MM: int tenPower = pow(10,len);
    
    long tenPower = 1;
    while (x > tenPower*10)
        tenPower *= 10;

    cout << x << '\n';
    cout << tenPower << '\n';

    while (num > 0) {
        first = num / tenPower;
        last = num % 10;
        if (first != last)
            return false;
        
        num = (num % tenPower) / 10;
        tenPower /= 100;

        // MM: num = (num - (first * tenPower + last)) / 10;
        // MM: len -= 2;
        // MM: tenPower = pow(10,len);
    }
    return true;
}

// B. Int to String conversion
/*
bool isPalindrome(int x) {
    
    string s = to_string(x);
    int l = 0, r = s.length()-1;

    while (l < r) {
        if (tolower(s.at(l)) != tolower(s.at(r)))
            return false;
        l++;
        r--;
    }
    
    return true;
}
*/

int main() {
    int x = 121;
    // int x = -121;
    // int x = 10;
    // int x = 0;
    // int x = 1;
    // int x = 313;
    // int x = 10000000000;
    cout << isPalindrome(x) << '\n';
    return 0;
}