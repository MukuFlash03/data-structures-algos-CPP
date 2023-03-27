/*

https://stackoverflow.com/questions/1403150/how-do-you-dynamically-allocate-a-matrix

Problem: https://leetcode.com/problems/set-matrix-zeroes/
Solution(s): 


YouTube
NC - https://www.youtube.com/watch?v=T41rL0L3Pnw

*/

/*

A. Optimal Approach

1. Instead of separate 1D arrays, incorporate these into input matrix.
2. First row is for columns.
    Leave top left cell as it as, use a single variable for this.
    First column except, top left cell is for rows.
    Avoiding top left cell, to prevent merging of rows and columns tracker.

B. Sub-Optimal Approach

1. No need of a copy matrix; keep track of whether each row or column needs 
    to be changed to all 0s by using two 1D arrays - one each for each of the dimensions.
2. Then, change 1s to 0s based on tracker arrays.




*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>

using namespace std;


void setZeroes(vector<vector<int>>& matrix) {

    int rows = matrix.size(), cols = matrix[0].size();
    bool rZ = false;

    // Set cells in row zero or column zero to 0 if any cell in that column/row is 0
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 0) {       
                matrix[0][j] = 0;   // Set colZ value as 0 for corresponding col j to be set to 0 later
                if (i > 0)
                    matrix[i][0] = 0; // // Set rowZ value as 0 for corresponding col i to be set to 0 later
                else
                    rZ = true;
            }
        }
    }

    for (int i = 1; i < rows; i++)
        for (int j = 1; j < cols; j++)
            if (matrix[0][j] == 0 || matrix[i][0] == 0)
                matrix[i][j] = 0;

    if (matrix[0][0] == 0)
        for (int i = 0; i < rows; i++)
            matrix[i][0] = 0;

    if (rZ)
        for (int j = 0; j < cols; j++)
            matrix[0][j] = 0;
}


int main() {
    vector<vector<int>> nums = {{1,1,1},{1,0,1},{1,1,1}};
    // vector<vector<int>> nums = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};

    cout << "Before\n";

    for (const auto& row : nums) {
        for (const auto& elem : row)
            cout << elem << "\t";
        cout << "\n";
    }

    setZeroes(nums);

    cout << "After\n";

    for (const auto& row : nums) {
        for (const auto& elem : row)
            cout << elem << "\t";
        cout << "\n";
    }
    
    return 0;
}