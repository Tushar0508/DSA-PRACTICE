class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();
        vector<vector<long long>> pf(2, vector<long long>(n + 1, 0)); 
        for (int i = 0; i < 2; i++) {
            for (int j = n - 1; j >= 0; j--) {
                pf[i][j] = grid[i][j] + pf[i][j + 1];
            }
        }
        
        long long result = LLONG_MAX;
        long long bottomRowSum = 0; 
        for (int j = 0; j < n; j++) {
            long long maxPoints = max(pf[0][j + 1], bottomRowSum);
            result = min(result, maxPoints);
            
            bottomRowSum += grid[1][j];
        }

        return result;
    }
};