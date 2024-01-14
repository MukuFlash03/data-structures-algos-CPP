/*

Type: 

Problem: https://leetcode.com/problems/sum-of-two-integers/
Solution(s): 

YouTube
NC - https://www.youtube.com/watch?v=gVUrDV4tZfY
*/


/*

A. Bitwise Operations

- Half Adder
    - Sum = a XOR b
    - Carry = a AND b

- Full Adder
    - Sum = a XOR b XOR carry
    - Carry = (a AND b) OR (carry AND (a XOR b))

- Keep repeating Half adder operations until carry is 0.

- Unsigned Int type cast added.


B. Logarithms

- (a + b) = log(e^a * e^b)
- Return log(exp(a) * exp(b));

- Gives out of range error for this input: a = -999, b = 0;
- Perhaps doesn't work with negative numbers.


*/



#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

int getSum(int a, int b) {

    int carry = 0;

    while (b != 0 ) {
        carry = a & b;
        a = a ^ b;
        b = (unsigned int)carry << 1;
        cout << carry << '\t' << a << '\t' << b << '\n';
    }

    return a;

    // return log(exp(a) * exp(b));
    // return log10(pow(10,a)*pow(10,b));
}

int main() {

    int a = 1, b = 3;
    // int a = 2, b = 3;
    // int a = -999, b = 0;

    cout << getSum(a, b) << '\n';


    return 0;
}