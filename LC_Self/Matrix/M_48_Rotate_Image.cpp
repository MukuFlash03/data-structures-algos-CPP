/*


https://stackoverflow.com/questions/1403150/how-do-you-dynamically-allocate-a-matrix

Problem: https://leetcode.com/problems/rotate-image/
Solution(s): 


YouTube
NC - https://www.youtube.com/watch?v=fMSJSS7eO1w

*/

/*

A. Optimal Approach


4 tracking variables: 4 for each boundary direction
4: Top, Right, Bottom, Left

- We will start with the outermost boundary rectangle, then move inwards in a counterclockwise order (temp variable usage)
- Offset by 1 from previous tracker direction.
- For each n*n boundary, we are doing n-1 rotations and not n rotations.
- For next inner boundary, update the trackers and iteratively/recursively perform rotation:
    a. Top++           b. Right--         
    c. Bottom--        d. Left++
- Continue till T < B and L < R

*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

vector<int> result;

void rotate(vector<vector<int>>& matrix) {

    // Square matrix: rows = cols
    int cols = matrix[0].size();

    int t, b;
    int l = 0;
    int r = cols-1;

    int topLeft;

    while (l <= r) {
        for (int i = 0; i < r-l; i++) {
            
            t = l;
            b = r;

            topLeft = matrix[t][l+i];            // Store top left value
            matrix[t][l+i] = matrix[b-i][l];     // Move bottom left into top left
            matrix[b-i][l] = matrix[b][r-i];     // Move bottom right into bottom left
            matrix[b][r-i] = matrix[t+i][r];     // Move top right into bottom right
            matrix[t+i][r] = topLeft;            // Move top left into top right 
        }

        r--;
        l++;
    }
}


int main() {
    vector<vector<int>> nums = {{1,2,3},{4,5,6},{7,8,9}};
    // vector<vector<int>> nums = {{5,1,9,11},{14,3,4,1},{12,6,8,9},{16,7,10,11}};

    rotate(nums);

    cout << "Rotated Image: \n";
    for (const auto& row : nums) {
        for (const auto& elem : row)
            cout << elem << "\t";
        cout << "\n";
    }

    return 0;
}