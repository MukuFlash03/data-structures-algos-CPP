/*

Type: Dynamic Programming, Largest Rectangle in Histogram - Monotonic Stack 

Problem: https://leetcode.com/problems/maximal-rectangle/
Solution(s): 

YouTube
NC - 
- https://www.youtube.com/watch?v=dAVF2NpC3j4
*/


/*


*/



#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

int maximalRectangle(vector<vector<char>>& matrix) {

}

int main() {

    vector<vector<char>> matrix = {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}
    };

    // vector<vector<char>> matrix = {
    //     {'0'}
    // };

    // vector<vector<char>> matrix = {
    //     {'1'}
    // };
    
    cout << maximalRectangle(matrix) << "\n";

    return 0;
}