/*

Strategy: Set, HashMap

https://stackoverflow.com/questions/1403150/how-do-you-dynamically-allocate-a-matrix

Problem: https://leetcode.com/problems/valid-sudoku/
Solution(s): 
- https://leetcode.com/problems/valid-sudoku/solutions/3254549/c-easiest-solution-hashing/
- https://leetcode.com/problems/valid-sudoku/solutions/3234762/c-solution-easy-to-understand/
- https://leetcode.com/problems/valid-sudoku/solutions/2841310/c-use-hashmap-easy-efficient-solution/


YouTube
NC - https://www.youtube.com/watch?v=TjFXEUCMqI8

*/

/*

A. Optimal Approach

- Will use hashsets.
- Only filled cells need to be validated; unfilled cells when assumed to be filled may give contradictions, 
    however board will still be valid if filled cells are valid.

- For identifying which sub 3x3 grid a cell belongs to, divide cell index by 3 and 
    integer quotient (floor) is value of new index of entire sub 3x3 considered as a whole in entire board.

- For sub 3x3 grid: Hash map key = new indices: (row/3,col/3)
- For rows (or cols)  : Hash map key = row(or col) indices; value = set



*/

#include<stdlib.h>
#include<stdio.h>
#include<iostream>
#include<bits/stdc++.h>

using namespace std;

bool isValidSudoku(vector<vector<char>>& board) {

    map<int, set<char>> rows;
    map<int, set<char>> cols;
    map<pair<int,int>, set<char>> sub3x3;

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {

            if (board[i][j] == '.')
                continue;

            pair<int,int> new_idx = {i/3, j/3};
            
            if (    
                rows[i].find(board[i][j]) != rows[i].end() ||
                cols[j].find(board[i][j]) != cols[j].end() ||
                sub3x3[new_idx].find(board[i][j]) != sub3x3[new_idx].end()
            )
                return false;

            rows[i].insert(board[i][j]);
            cols[j].insert(board[i][j]);
            sub3x3[new_idx].insert(board[i][j]);
        }
    }

    return true;
}


int main() {

/*
    vector<vector<char>> board = 
    {{'5','3','.','.','7','.','.','.','.'}
    ,{'6','.','.','1','9','5','.','.','.'}
    ,{'.','9','8','.','.','.','.','6','.'}
    ,{'8','.','.','.','6','.','.','.','3'}
    ,{'4','.','.','8','.','3','.','.','1'}
    ,{'7','.','.','.','2','.','.','.','6'}
    ,{'.','6','.','.','.','.','2','8','.'}
    ,{'.','.','.','4','1','9','.','.','5'}
    ,{'.','.','.','.','8','.','.','7','9'}};
*/
    
    vector<vector<char>> board = 
    {{'8','3','.','.','7','.','.','.','.'}
    ,{'6','.','.','1','9','5','.','.','.'}
    ,{'.','9','8','.','.','.','.','6','.'}
    ,{'8','.','.','.','6','.','.','.','3'}
    ,{'4','.','.','8','.','3','.','.','1'}
    ,{'7','.','.','.','2','.','.','.','6'}
    ,{'.','6','.','.','.','.','2','8','.'}
    ,{'.','.','.','4','1','9','.','.','5'}
    ,{'.','.','.','.','8','.','.','7','9'}};
    

    bool flag = isValidSudoku(board);

    cout << flag << "\n";

    return 0;
}