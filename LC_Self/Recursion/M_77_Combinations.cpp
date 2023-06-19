/*
Problem: https://leetcode.com/problems/combinations
Solution(s): 

YouTube
NC - https://www.youtube.com/watch?v=s9fokUqJ76A
*/


/*

Rough time complexity: O(n^k)
n: Length of decision tree
k: Height of decision tree

Better estimate: O(k*nCk)

A. Optimal Solution

Tracking variable: start

start: Need to maintain value with which we started current combination, 
    as we can only choose numbers greater than this value for adding more elements to the current combination

comb: Need to keep track of current combination



*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

vector<int> combs;
vector<vector<int>> result;

void recurCombine(int idx, int n, int k) {

    if (combs.size() == k) {
        result.push_back(combs);
        return;
    }
    for (int i = idx; i <= n; i++) {
        combs.push_back(i);
        recurCombine(i+1, n, k);
        combs.pop_back();
    }
}

vector<vector<int>> combine(int n, int k) {
    recurCombine(1,n,k);
    return result;
}


int main() {

    // int n = 4, k = 2;
    int n = 3, k = 2;
    // int n = 1, k = 1;

    vector<vector<int>> result = combine(n,k);

    for (const auto &elem : result) {
        for (const auto &elem2 : elem) 
            cout << elem2 << ',';
        cout << '\t';
    }
    cout << '\n';


    return 0;
}