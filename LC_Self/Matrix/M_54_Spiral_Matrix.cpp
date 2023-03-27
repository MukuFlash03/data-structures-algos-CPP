/*


https://stackoverflow.com/questions/1403150/how-do-you-dynamically-allocate-a-matrix

Problem: https://leetcode.com/problems/spiral-matrix/
Solution(s): 


YouTube
NC - https://www.youtube.com/watch?v=BJnMZNwUk1M

*/

/*

A. Optimal Approach

5 tracking variables: 4 for each direction + 1 direction pointer

4: Top, Right, Bottom, Left
1: Direction

Direction moves in following order: 
a. Top: L to R         b. Right: T to B
c. Bottom: R to L      d. Left: B to T

Now, starting from Top, moving L to R, fetch all elements, then spiral cyclically move on to Right elements, then to Bottom, and Left.

Trackers are updated as follows:
a. Top++           b. Right--         
c. Bottom--        d. Left++

Direction is updated as follows:
dir = (dir+1)%4


*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

vector<int> result;

vector<int> spiralOrder(vector<vector<int>>& matrix) {

    int rows = matrix.size();
    int cols = matrix[0].size();

    int t = 0;
    int b = rows-1;
    int l = 0;
    int r = cols-1;
    int i, dir = 0;

    while (t <= b && l <= r) {
        if (dir == 0) {
            for (i = l; i <= r; i++)
                result.push_back(matrix[t][i]);
            t++;
        }

        if (dir == 1) {
            for (i = t; i <= b; i++)
                result.push_back(matrix[i][r]);
            r--;
        }

        if (dir == 2) {
            for (i = r; i >= l; i--)
                result.push_back(matrix[b][i]);
            b--;
        }

        if (dir == 3) {
            for (i = b; i >= t; i--)
                result.push_back(matrix[i][l]);
            l++;
        }

        dir = (dir+1)%4;
    }

    return result;
}


int main() {
    // vector<vector<int>> nums = {{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int>> nums = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};

    result = spiralOrder(nums);

    cout << "Spiral order: \n";
    for (const auto& elem : result)
            cout << elem << "\t";
    cout << "\n";

    return 0;
}