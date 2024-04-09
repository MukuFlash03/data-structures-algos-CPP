/*
Type:

Problem: https://leetcode.com/problems/count-elements-with-maximum-frequency
Solution(s): 

YouTube
NC - 
*/

/*

A. Two Maps

1. Create a map to store frequency of each element.
2. Create another map to store frequency of each frequency.
3. Return the product of the maximum frequency and the number of elements with that frequency.

B. One Map

1. Create a map to store frequency of each element.
2. Iterate through the map and find the maximum frequency.
3. Iterate through the map and count the number of elements with the maximum frequency.
4. Return the product of the maximum frequency and the number of elements with that frequency.


*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<map>

using namespace std;

int maxFrequencyElements(vector<int>& nums) {
    map<int, int> freqMap;
    for(const auto& elem : nums)
        freqMap[elem]++;


    // M1
    map<int, int> freqBuckets;
    for(const auto& elem : freqMap)
        freqBuckets[elem.second]++;

    return freqBuckets.rbegin()->first * freqBuckets.rbegin()->second;

    /*
    // M2
    
    int maxFreq = 0;
    for(const auto& elem : freqMap)
        maxFreq = max(maxFreq, elem.second);
    
    int count = 0;
    for(const auto& elem : freqMap)
        if (elem.second == maxFreq)
            count++;

    return maxFreq * count;
    */

}


int main() {

    // vector<int> nums = {1,2,2,3,1,4};
    vector<int> nums = {1,2,3,4,5};

    cout << maxFrequencyElements(nums) << "\n";

    return 0;
}