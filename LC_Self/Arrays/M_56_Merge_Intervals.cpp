/*
Type: Sorting Array
Problem: https://leetcode.com/problems/merge-intervals/
Solution(s): https://leetcode.com/problems/merge-intervals/discuss/1644017/C%2B%2B-EASY-TO-SOLVE-oror-Beginner-Friendly-with-Detailed-Explanations

YouTube
NC - https://www.youtube.com/watch?v=44H3cEC2fFM
*/


/*

A. Optimal Solution
Sort in ascending order of start of each interval.
Add first interval to answer vector.
Iterate through all intervals
    Check if current interval's start <= end of latest entry in answer
    If true
        Update latest entry in answer's end = max(currentEnd, latestEnd)
    Else
        Add current interval to answer

Return answer


*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

/* TLE
static bool compareInterval(std::vector<int> i1, std::vector<int> i2) {
    return (i1[0] < i2[0]);
}
*/

vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals) {
    
    // sort(intervals.begin(), intervals.end(), compareInterval);

    sort(intervals.begin(), intervals.end(), [](vector<int>& i1, vector<int>& i2) {
        return i1[0] < i2[0];
    });

    vector<vector<int>> answer;
    answer.push_back(intervals[0]);

    for(int i = 1; i < intervals.size(); i++) {
        int start = intervals[i][0];
        int end = intervals[i][1];

        int lastEnd = answer.back()[1];

        if (start <= lastEnd)
            answer.back()[1] = max(end, lastEnd);
        else
            answer.push_back(intervals[i]);
    }
    return answer;
}



int main() {
    vector<vector<int>> nums = {{1,3},{2,6},{8,10},{15,18}};
    // vector<vector<int>> nums = {{1,4},{4,5}};
    
    vector<vector<int>> answer = mergeIntervals(nums);

    // for(auto it = answer.begin(); it != answer.end(); it++)
    for ( const vector<int> &elem : answer)
        cout << elem[0] << ", " << elem[1] << "\n";
    cout << "\n\n";

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