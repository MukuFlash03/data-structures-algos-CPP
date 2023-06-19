/*
Type: Sorting Array
Problem: https://leetcode.com/problems/non-overlapping-intervals/
Solution(s): 

YouTube
NC - https://www.youtube.com/watch?v=nONCGxWoUfM
*/


/*

A. Optimal Solution
1. Sort in ascending order of start of each interval.
2. Add first interval's end to tracking end.
3. Iterate through all intervals starting from 2nd interval
4.    Check if current interval's start <= end of latest entry in answer
5.     If true
        Increment answer++
        Update latest end in tracking end = min(currentEnd, latestEnd)
      Else
        Update latest end in tracking end = currentEnd
        

Return answer


*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

/* TLE
static bool compareInterval(std::vector<int> i1, std::vector<int> i2) {
    return (i1[0] < i2[0]);
}
*/

int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    
    int size = intervals.size();

    if (intervals.empty())
        return 0;
    if (size == 1)
        return 0;

    // sort(intervals.begin(), intervals.end(), compareInterval);  // TLE

    sort(intervals.begin(), intervals.end(), [](vector<int>& i1, vector<int>& i2) {
        return i1[0] < i2[0];
    });

    int answer = 0;
    int lastEnd = intervals[0][1];

    int start, end;
    
    for(int i = 1; i < size; i++) {
        start = intervals[i][0];
        end = intervals[i][1];

        if (start < lastEnd) {
            answer += 1;
            lastEnd = min(end, lastEnd);
        }
        else
            lastEnd = end;
    }
    return answer;
}



int main() {
    // vector<vector<int>> nums = {{1,2},{2,3},{3,4},{1,3}};
    vector<vector<int>> nums = {{1,2},{1,2},{1,2}};
    // vector<vector<int>> nums = {{1,2},{2,3}};
    // vector<vector<int>> nums = {{1,100},{11,22},{1,11},{2,12}};
    
    int answer = eraseOverlapIntervals(nums);
    cout << answer << "\n\n";

    return 0;
}