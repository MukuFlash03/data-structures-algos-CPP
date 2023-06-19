/*

https://www.byte-by-byte.com/coding-interview-101/

Type: Sliding Window
https://www.youtube.com/watch?v=GcW4mgmgSbw
https://www.youtube.com/watch?v=p-ss2JNynmw

Problem: https://leetcode.com/problems/group-anagrams/
Solution(s): 
- https://leetcode.com/problems/group-anagrams/solutions/3077821/easy-beginner-friendly-c-solution-using-hashmap-beats-97/
- https://leetcode.com/problems/group-anagrams/solutions/2750831/c-31ms-98/
- https://leetcode.com/problems/group-anagrams/solutions/2751546/c-easy-approach-hashmap-sorting/

YouTube
NC - https://www.youtube.com/watch?v=vzdNOK2oB2E


A. Sliding Window

O(mnlogn): With sorting chars of each string
O(mn)    : W/o sorting

1. Iterate through input string vector
2. For each string, sort the string chars (to serve as map keys) and append string to map
3. Append each set of strings sorted by string keys to the result vector

Unorderd map has better time complexity

*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

vector<vector<string>> groupAnagrams(vector<string>& strs) {

    unordered_map<string, vector<string>> groups;
    vector<vector<string>> result;

    for (const auto& str : strs) {
        string currStr = str;
        sort(currStr.begin(), currStr.end());
        groups[currStr].emplace_back(str);
    }

    for (const auto& group : groups)
        result.emplace_back(group.second);

    return result;
}


int main() {

    vector<string> strs = {"eat","tea","tan","ate","nat","bat"};
    // vector<string> strs = {""};
    // vector<string> strs = {"a"};

    vector<vector<string>> result = groupAnagrams(strs);

    for (const auto& elem : result)
        for (const auto& elem2: elem)
            cout << elem2 << ' ';
    cout << '\n';

    return 0;
}