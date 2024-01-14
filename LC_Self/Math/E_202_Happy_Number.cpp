/*

Problem: https://leetcode.com/problems/happy-number/
Solution(s): 

YouTube
NC - 
*/


/*

A. Optimal Solution 

- Use a set to keep track of unhappy numbers

B. Floyd's Cycle Detection Algorithm

- Use two pointers, slow and fast

*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<unordered_set>

using namespace std;

int calcSum(int n) {
    int sum = 0;
    while (n > 0) {
        sum += pow(n % 10, 2);
        n /= 10;
    }
    return sum;        
}

bool isHappy(int n) {
    unordered_set<int> unhappy;

    while (n != 1 && unhappy.find(n) == unhappy.end()) {
        unhappy.insert(n);
        n = calcSum(n);
    }

    if (n == 1)
        return true;
    return false; 
}

// bool isHappy(int n) {
//     int slowPointer = n;
//     int fastPointer = calcSum(n);
//     while(fastPointer != 1 && fastPointer != slowPointer){
//         slowPointer = calcSum(slowPointer);
//         fastPointer = calcSum(calcSum(fastPointer));
//     }
//     return fastPointer==1;
// }

int main() {

    // int n = 19;
    int n = 2;

    bool happy = isHappy(n);
    cout << "Happy: " << happy << endl;

    return 0;
}