/*
Type: Searching Array
Problem: https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/
Solution(s): https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/solutions/3252898/378-solution-with-step-by-step-explanation/
        TLE


YouTube
NC - 
*/


/*

A. Optimal Solution


*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int kthSmallest(vector<vector<int>>& matrix, int k) {

    int n = matrix.size();
    int low = matrix[0][0], high = matrix[n-1][n-1];
    int mid, count, j; 

    while (low < high) {
        mid = (low + high) / 2;
        count = 0;
        j = n-1;

        for (int i = 0; i < n; i++) {
            while (j >= 0 && matrix[i][j] > mid)
                j--;
            count += j+1;
        }

        if (count < k)
            low = mid + 1;
        else
            high = mid;
    }

    return low;
}


int main() {
    vector<vector<int>> nums = {{1,5,9},{10,11,13},{12,13,15}};
    int k = 8;
    
    // vector<vector<int>> nums = {{-5}};
    // int k = 1;

    int index = kthSmallest(nums, k);
    cout << index << '\n';
    cout << '\n';


}