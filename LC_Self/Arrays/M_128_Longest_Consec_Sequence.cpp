/*

https://www.byte-by-byte.com/coding-interview-101/

Type: 

Problem: https://leetcode.com/problems/longest-consecutive-sequence/
Solution(s): 
- https://leetcode.com/problems/longest-consecutive-sequence/solutions/3171985/best-c-4-solution-hash-table-sorting-brute-force-optimize-one-stop-solution/

YouTube
NC - https://youtu.be/P6RZZMu_maU

A. Optimal Approach
Set + Sliding Window (High Runtime)



Concept:
1. Segregate elements into sets of consecutive elements
2. Identify starting elements of each sequence
    - This can be done by checking whether previous element exists in set
    - If not, it is a starting element
3. To identify consecutive elements, check if next element exists in set
    - If yes, increment current length and current element
    - If no, update max length

1. Insert all elements into set for sorted order by default (O(n))
2. Iterate through set and check if consecutive elements exist (O(n)) by checking for previous element
3.  If yes, reset current length to 1 and set curremt element
4.  While future consecutive elements exist:
        Increment current length and current element
5.  Update max length
6. Return max length

----------

C. Initial Approach

- Insert element.
- If element is not consecutive, clear set and insert element.
- If element is consecutive, calculate max length.

Approach doesn't work as I don't want elements to be cleared.
It may be that an element is not consecutive but it may be part of a 
consecutive sequence that includes future elements.

*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<unordered_set>
#include<map>

using namespace std;

// Approach A
int longestConsecutive(vector<int>& nums) {
    unordered_set<int> temp;
    int maxLen = 0;

    if (nums.size() == 1)
        return 1;
    if (nums.size() == 0)
        return 0;

    for (const auto& elem : nums)
        temp.insert(elem);

    for (const auto& elem : nums) {
        if (temp.find(elem-1) == temp.end()) {
            int currLen = 1;
            int currElem = elem;
            while (temp.find(currElem+currLen) != temp.end())
                currLen++;
            maxLen = max(maxLen, currLen);
        }
    }

    return maxLen;
}


/*
// Approach B
int longestConsecutive(vector<int>& nums) {
    set<int> temp;
    int last, maxLen = 0;

    if (nums.size() == 1)
        return 1;

    for (const auto& elem : nums) {
        temp.insert(elem);
        if (!temp.empty() && temp.size() > 1) {
            last = *temp.rbegin();
            if (abs(elem - last) == 1) {
                maxLen = max(maxLen, (int)temp.size());
            }
            else {
                temp.clear();
                temp.insert(elem);
            }
        }
    }

    return maxLen;
}
*/


int main() {

    vector<int> nums = {100,4,200,1,3,2};
    // vector<int> nums = {0,3,7,2,5,8,4,6,0,1};
    
    int longLen = longestConsecutive(nums);
    cout << longLen << "\n";

    return 0;
}