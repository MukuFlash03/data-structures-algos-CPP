/*

Problem: https://leetcode.com/problems/powx-n/
Solution(s): https://www.youtube.com/watch?v=-mNn11iRZ5k

YouTube
NC - 
*/


/*

A. Optimal Solution (Recursive)

- Base case: n == 0, return 1
- If n < 0, x = 1/x, n = abs(n)
- Recursively call myPow(x, n/2)
- If n is even, return temp * temp
- Else return temp * temp * x

*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<unordered_set>

using namespace std;

double myPow(double x, int n) {

    if (n < 0) {
        x = 1/x; 
        n = abs(n);
    }

    if (n == 0)
        return 1;
    
    double temp = myPow(x, n/2);
    double temp2 = temp * temp;
    return (n % 2 == 0) ? temp2 : temp2 * x;
}

int main() {

    double x = 2.00000, n = 10;
    // double x = 2.10000, n = 3;
    // double x = 2.00000, n = -2;

    cout << myPow(x, n) << endl;

    return 0;
}