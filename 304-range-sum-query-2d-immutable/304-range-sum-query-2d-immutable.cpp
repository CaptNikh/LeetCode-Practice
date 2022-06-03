class NumMatrix {
public:
    vector<vector<int>> prefixSum;
    
    NumMatrix(vector<vector<int>>& matrix) {
        
        int row = matrix.size(), col = matrix[0].size();
        prefixSum.resize(row, vector<int> (col, 0));
        prefixSum[0][0] = matrix[0][0];
        
        for(int i = 1; i < col; i++){
            prefixSum[0][i] = matrix[0][i] + prefixSum[0][i - 1];
            // cout << prefixSum[0][i] << " ";
        }
        // cout << '\n';
        
        for(int i = 1; i < row; i++){
            for(int j = 0; j < col; j++) {
                prefixSum[i][j] = prefixSum[i - 1][j] + matrix[i][j];
                if(j > 0)
                    prefixSum[i][j] += prefixSum[i][j - 1] - prefixSum[i - 1][j - 1];
                
                // cout << prefixSum[i][j] << " ";
            }
            cout << "\n";
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int r1 = row1 - 1, c1 = col1 - 1, r2 = r1, c2 = col2, r3 = row2, c3 = col1 - 1;
        
        int ans = prefixSum[row2][col2];
        if(r2 >= 0 and c2 >= 0)
            ans -= prefixSum[r2][c2];
        
        if(r3 >= 0 and c3 >= 0)
            ans -= prefixSum[r3][c3];
        
        if(r1 >= 0 and c1 >= 0)
            ans += prefixSum[r1][c1];
        
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */