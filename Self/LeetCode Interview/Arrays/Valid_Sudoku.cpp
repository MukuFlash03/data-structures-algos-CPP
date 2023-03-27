// Soln 1

class Solution {
    
public:
    vector<vector<char>> transpose(vector<vector<char>>& matrix)
    {
        vector<vector<char>> matrix2(matrix[0].size(), vector<char>());
        for (int i = 0; i < matrix.size(); i++)
            for (int j = 0; j < matrix[i].size(); j++)
                matrix2[i].push_back(matrix[j][i]);
        
        return matrix2;
    }    
    
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        vector <char> :: iterator it;
        
        // Row check
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                // cout << board[i][j] << " ";
                if (board[i][j] > 48 && board[i][j] <= 57)
                {
                    it = find(board[i].begin()+j+1, board[i].end(), board[i][j]);
                    // cout << board[i][j] << " ";
                    if (it != board[i].end())
                    {
                       // cout << "Fail" << endl;
                        return false;
                    }
                }
            }
            cout << endl;
        }
        
        vector<vector<char>> board1;
        board1 = transpose(board);
        
        // Column check
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                if (board1[i][j] > 48 && board1[i][j] <= 57)
                {
                    it = find(board1[i].begin()+j+1, board1[i].end(), board1[i][j]);
                    if (it != board1[i].end())
                    {
                       // cout << "Fail" << endl;
                        return false;
                    }
                }
            }
        }
        
        // 3x3 Box Check
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                int r = i - i%3;
                int c = j - j%3;
                for (int x = 0; x < 3; x++)
                {
                    for (int y = 0; y < 3; y++)
                    {
                        it = find(board[x+r].begin()+y+1, board[x+r].end(), board[x+r][y+c]);
                        if (it != board[x+r].end())
                        {
                            // cout << "Fail" << endl;
                            return false;
                        }
                    }
                }
            }
        }
        
        return true;
    }
};

// Soln 2
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<int> has;
        for (int i = 0; i < 9; i ++) {
            has.clear();
            // rows
            for (int j = 0; j < 9; j ++) {
                if (board[i][j] != '.') {
                    if (has.count(board[i][j])) {
                        return false;
                    }
                    has.insert(board[i][j]);
                }
            }
            has.clear();
            // columns
            for (int j = 0; j < 9; j ++) {
                if (board[j][i] != '.') {
                    if (has.count(board[j][i])) {
                        return false;
                    }
                    has.insert(board[j][i]);
                }
            }
        }
        for (int i = 0; i < 3; i ++) {
            for (int j = 0; j < 3; j ++) {
                // sub grids
                has.clear();
                for (int x = i * 3; x < i * 3 + 3; x ++) {
                    for (int y = j * 3; y < j * 3 + 3; y ++) {
                        if (board[x][y] != '.') {
                            if (has.count(board[x][y])) {
                                return false;
                            }
                            has.insert(board[x][y]);
                        }
                    }
                }
            }
        }
        return true;
    }
};