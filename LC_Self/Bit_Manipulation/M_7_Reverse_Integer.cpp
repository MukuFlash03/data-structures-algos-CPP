/*

Type: 

Problem: https://leetcode.com/problems/reverse-integer/
Solution(s): 

YouTube
NC - hhttps://www.youtube.com/watch?v=HAgLH58IgJQ
*/


/*

A. Standard Mathematical Approach

- Modulus and Division used to fetch 1's place digit and keep reducing number.

- Check if number to be reversed is out of bounds:
    - Extract 1's place digit and store remaining number (divide original number by 10).
    - If remaining number matches upper bound (2147483647 or -2147483648) divided by 10, i.e., 214748364, 
      then check 1's place digit:
        - If 1's place digit is greater than 7, then return 0.
        - If 1's place digit is less than -8, then return 0. 
    - If remaining number is greater than upper bound (2147483647 or -2147483648) divided by 10, then return 0.

*/



#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

int reverse(int x) {

    int maxDiv = INT32_MAX / 10;
    int minDiv = INT32_MIN / 10;

    int maxRem = INT32_MAX % 10;
    int minRem = INT32_MIN % 10;

    int reversed = 0;
    int oneDig = 0;

    while (x != 0) {

        oneDig = x % 10;
        x /= 10;

        if (reversed > maxDiv || (reversed == maxDiv && oneDig > maxRem))
            return 0;
        if (reversed < minDiv || (reversed == minDiv && oneDig < minRem))
            return 0;
        reversed = (reversed * 10) + oneDig;

        cout << "x: " << x << '\n';
        cout << "oneDig: " << oneDig << "\n";
        cout << "reversed: " << reversed << "\n\n";
    }

    return reversed;
}


int main() {

    // int num = 123;
    int num = -123;
    // int num = 120;

    cout << reverse(num) << '\n';
    // cout << bitset<32>(num) << '\n';
    // cout << bitset<32>(321) << '\n';

    return 0;
}