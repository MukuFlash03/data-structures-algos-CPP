/*
Type: Searching Array
Problem: https://leetcode.com/problems/koko-eating-bananas
Solution(s): 

*/


/*

A. Optimal Solution

1. Run binary search for finding the minimum value of k.
2. Set low to 1 and high to max element in piles.
3. Compute mid and check if it is possible to eat all bananas in mid hours by dividing each pile by mid and summing them up.
4. If possible, set high to mid-1, else set low to mid+1.

Why need of + mid - 1?
Because we need to round up the division result to the nearest integer.
Alternatively, we can use ceil() function from cmath library.

Why low = 1 and high = 1e9?
Why not low = min(piles) and high = max(piles)?
Because the minimum value of k can be 1 and the maximum value of k can be 1e9.

*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

int minEatingSpeed(vector<int>& piles, int h) {
    long low = 1, high = 1e9, mid;
    long sum = 0;

    while (low <= high) {
        sum = 0;
        mid = (low + high) / 2;

        for (const auto &pile : piles)
            sum += (pile + mid - 1) / mid;

        if (sum > h)
            low = mid + 1;
        else if (sum <= h)
            high = mid - 1;        
    }

    return low;
}


int main() {
    // vector<int> piles = {3,6,7,11};
    // int h = 8;

    // vector<int> piles = {30,11,23,4,20};
    // int h = 5;

    vector<int> piles = {30,11,23,4,20};
    int h = 6;
    
    int index = minEatingSpeed(piles, h);
    cout << index << '\n';
    cout << '\n';

    // for(auto it = answer.begin(); it != answer.end(); it++)
    // for ( const vector<int> &elem : answer)
        // cout << elem[0] << ", " << elem[1] << "\n";
    // cout << "\n\n";

    /*
    vector<pair<int, int>> test = {make_pair(1,1), make_pair(2,2)};
    // vector<pair<int, int>>::iterator it;
    for (auto it = test.begin(); it != test.end(); it++)
            cout << it->first << ", " << it->second << '\t';
    cout << '\n';

    for ( const pair<int,int> &elem : test )
        cout << elem.first << ", " << elem.second << '\t';
    cout << '\n';
    */

}