class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix)
    {
        vector<vector<int>> matrix2(matrix[0].size(), vector<int>());
        for (int i = 0; i < matrix.size(); i++)
            for (int j = 0; j < matrix[i].size(); j++)
                matrix2[i].push_back(matrix[j][i]);
        
        return matrix2;
    }
    
    public:
    void rotate(vector<vector<int>>& matrix) {
      
        matrix = transpose(matrix);
        
        for (int i = 0; i < matrix.size(); i++)
            reverse(matrix[i].begin(), matrix[i].end());
    }
};

// Soln 2

// Consider all squares one by one 
    for (int x = 0; x < N / 2; x++) { 
        // Consider elements in group 
        // of 4 in current square 
        for (int y = x; y < N - x - 1; y++) { 
            // Store current cell in 
            // temp variable 
            int temp = mat[x][y]; 
  
            // Move values from right to top 
            mat[x][y] = mat[y][N - 1 - x]; 
  
            // Move values from bottom to right 
            mat[y][N - 1 - x] 
                = mat[N - 1 - x][N - 1 - y]; 
  
            // Move values from left to bottom 
            mat[N - 1 - x][N - 1 - y] 
                = mat[N - 1 - y][x]; 
  
            // Assign temp to left 
            mat[N - 1 - y][x] = temp; 
        } 
    } 

// Soln 3 Clockwise

// Traverse each cycle 
    for (int i = 0; i < N / 2; i++) 
    { 
        for (int j = i; j < N - i - 1; j++) 
        { 
  
            // Swap elements of each cycle 
            // in clockwise direction 
            int temp = a[i][j]; 
            a[i][j] = a[N - 1 - j][i]; 
            a[N - 1 - j][i] = a[N - 1 - i][N - 1 - j]; 
            a[N - 1 - i][N - 1 - j] = a[j][N - 1 - i]; 
            a[j][N - 1 - i] = temp; 
        } 
    } 