/*

https://www.byte-by-byte.com/coding-interview-101/
https://stackoverflow.com/questions/44447642/how-to-sort-values-in-a-map-in-c

Type: Bucket Sort

Problem: https://leetcode.com/problems/top-k-frequent-elements/
Solution(s): 
- 

YouTube
NC - https://www.youtube.com/watch?v=YPTqKIgVk-k

A. Optimal Approach

1. Store elements with same count in same bucket.
2. Iterate through buckets from end to start and add first k  elements to result vector.
3. Return result vector.

Note:
- End point of bucket would be length of input vector as in worst case only a single element would occur n times.
- Bucket sort is used when we know the range of values in the array.
- In this case, we know that the range of values is from 0 to n-1.
- Thus, we can use bucket sort to sort the elements by their count.



B. Suboptimal Approach

Concept:
1. Iterate through array.
2. While current element exists:
    - Increment current element count
    - Insert current element with its count into map
    - Clear 1 occurence of current element
3. Order map by descending order of count
4. Insert top k elements into result vector and return


*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<unordered_set>
#include<map>

using namespace std;

static bool compare(const pair<int, int>& a, const pair<int, int>& b) {
    return a.second > b.second || (!(b.second > a.second) && a.first < b.first);
}

vector<int> topKFrequent(vector<int>& nums, int k) {
    map<int, int> countMap;
    vector<int> result;

    // for (auto it = nums.begin(); it != nums.end();) {
    for (auto it = nums.begin(); it != nums.end(); it++) {
        ++countMap[*it];
        // it = nums.erase(it);
    }

    map<int, vector<int>> bucketMap;
    for (const auto& pair : countMap)
        bucketMap[pair.second].push_back(pair.first);

    for (auto it = bucketMap.rbegin(); it != bucketMap.rend(); it++) {
        for (const auto& elem : it->second) {
            result.push_back(elem);
            if (result.size() == k)
                return result;
        }
    }

    return result;
}

/*
// Approach B
vector<int> topKFrequent(vector<int>& nums, int k) {
    map<int, int> countMap;
    vector<int> result;

    for (auto it = nums.begin(); it != nums.end();) {
        ++countMap[*it];
        // it = nums.erase(it);
    }

    vector<pair<int, int>> countVector(countMap.begin(), countMap.end());

    sort(countVector.begin(), countVector.end(), compare);
    // sort(countVector.begin(), countVector.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
    //     return a.second > b.second || (!(b.second > a.second) && a.first < b.first);
    // });

    for (int i = 0; i < k; i++)
        result.push_back(countVector[i].first);

    return result;
}
*/



int main() {

    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;
    
    // vector<int> nums = {1,1,1,2,3,2,3,4,4,4,4,5,5,5,5};
    // int k = 2;
    
    // vector<int> nums = {1};
    // int k = 1;
    
    vector<int> mostFreq = topKFrequent(nums,k);
    for (const auto &elem : mostFreq) 
        cout << elem << "\t";
    cout << "\n";

    return 0;
}