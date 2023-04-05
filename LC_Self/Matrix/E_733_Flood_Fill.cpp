/*

https://stackoverflow.com/questions/1403150/how-do-you-dynamically-allocate-a-matrix

Problem: https://leetcode.com/problems/flood-fill/
Solution(s): 


YouTube
https://www.youtube.com/watch?v=aehEcTEPtCs

*/

/*

A. Recursive DFS Approach

1. If cell at sr,sc matches color, no need to do anything, return input matrix.
2. Else, recursively perform DFS to explore all 4-directional neighbors of current cell at sr,sc.
3. Check if next neighbor cell:
    - Lies within acceptable bounds of the input array
    - Is the same color as the current cell at sr,sc

4. If any condition is not met, return
5. Else, call same function recursively for all four directions: 
    - row-1,col     - row,col+1,    - row-1,col     - row,col-1

*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void fill(vector<vector<int>>& image, int sr, int sc, int color, int currColor) {
    if (sr < 0 || sc < 0 || sr >= image.size() || sc >= image[0].size() || image[sr][sc] != currColor)
        return;
    
    image[sr][sc] = color;

    fill(image,sr-1,sc,color,currColor);
    fill(image,sr+1,sc,color,currColor);
    fill(image,sr,sc-1,color,currColor);
    fill(image,sr,sc+1,color,currColor);
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
    if (image[sr][sc] == color)
        return image;
    fill(image,sr,sc,color,image[sr][sc]);
    return image;
}


int main() {
    vector<vector<int>> nums = {{1,1,1},{1,1,0},{1,0,1}};
    int sr = 1, sc = 1, color = 2;
    
    // vector<vector<int>> nums = {{0,0,0},{0,0,0}};
    // int sr = 0, sc = 0, color = 0;

    cout << "Before\n";

    for (const auto& row : nums) {
        for (const auto& elem : row)
            cout << elem << "\t";
        cout << "\n";
    }

    floodFill(nums,sr,sc,color);

    cout << "After\n";

    for (const auto& row : nums) {
        for (const auto& elem : row)
            cout << elem << "\t";
        cout << "\n";
    }
    
    return 0;
}