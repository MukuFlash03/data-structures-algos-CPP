/*

Type: Dynamic Programming, Largest Rectangle in Histogram - Monotonic Stack 

Problem: https://leetcode.com/problems/maximal-square/
Solution(s): 

YouTube
NC - https://www.youtube.com/watch?v=6X7Ha2PrDmM
*/


/*


*/



#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

int maximalSquare(vector<vector<char>>& matrix) {

}

int main() {

    vector<vector<char>> matrix = {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}
    };

    // vector<vector<char>> matrix = {
    //     {'0','1'},
    //     {'1','0'}
    // };

    // vector<vector<char>> matrix = {
    //     {'0'}
    // };
    
    cout << maximalSquare(matrix) << "\n";

    return 0;
}