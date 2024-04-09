/*
Type: Searching Array
Problem: https://leetcode.com/problems/search-a-2d-matrix/
Solution(s): https://leetcode.com/problems/search-a-2d-matrix/solutions/3057966/c-beats-100-binary-search-upper-bound-o-log-m-n/

YouTube
NC - https://www.youtube.com/watch?v=Ber2pi2C0j0
*/


/*

A. Optimal Solution

Binary Search to be applied first to find which row contains target value.
Last value of each row is lesser than first value of next row.
Hence, values in all rows above a specific row will be lesser than the values in this row and any succeeding rows.
Thus, all succeeding rows including the current row can be eliminated from search candidates.

Once row is found, binary search to be applied within that specific row.

Why doing this below check for low > high?
Because if low > high, it means that the target is not present in the matrix.

*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size(), cols = matrix[0].size();
        int low = 0, high = rows-1, mid;
        int l = 0, h = cols-1, m;

        while (low <= high) {
            mid = (low + high) / 2;

            if (target > matrix[mid][cols-1])
                low = mid + 1;
            else if (target < matrix[mid][0])
                high = mid - 1;
            else
                break;
        }

        if (!(low <= high))
            return false;

        while (l <= h) {
            m = (l + h) / 2;

            if (target > matrix[mid][m])
                l = m + 1;
            else if (target < matrix[mid][m])
                h = m - 1;
            else
                return true;
        }

        return false;
}


int main() {
    vector<vector<int>> nums = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target = 3;
    // int target = 13;

    // vector<vector<int>> nums = {{1}};
    // int target = 1;

    bool flag = searchMatrix(nums, target);
    cout << flag << '\n';
    cout << '\n';


}