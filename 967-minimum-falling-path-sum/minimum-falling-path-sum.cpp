class Solution {
public:
    int solve(vector<vector<int>>& matrix, int row, int col, vector<vector<int>>& dp) {
        if (col < 0 || col >= matrix.size()){
            return INT_MAX;
        }
        if (row == matrix.size()-1){ 
            return matrix[row][col];
        }
        if (dp[row][col] != INT_MAX){ 
            return dp[row][col];
        }
        
        int down = solve(matrix, row + 1, col, dp);
        int downL = solve(matrix, row + 1, col - 1, dp);
        int downR = solve(matrix, row + 1, col + 1, dp);

        dp[row][col] = matrix[row][col] + min(down, min(downL, downR));

        return dp[row][col]; 
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int result = INT_MAX;
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));

        for (int col = 0; col < n; col++) {
            result = min(result, solve(matrix, 0, col, dp)); 
        }

        return result;
    }
};