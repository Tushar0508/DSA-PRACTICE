class Solution {
public:
    int dfs(vector<vector<int>>& grid, vector<vector<int>>& visited, int row, int col) {
        int n = grid.size();
        int m = grid[0].size();

        if (row < 0 || col < 0 || row >= n || col >= m || grid[row][col] == 0 || visited[row][col] == 1) {
            return 0;
        }

        visited[row][col] = 1;

        int total_fishes = grid[row][col];

        total_fishes += dfs(grid, visited, row + 1, col);  // Down
        total_fishes += dfs(grid, visited, row - 1, col);  // Up
        total_fishes += dfs(grid, visited, row, col + 1);  // Right
        total_fishes += dfs(grid, visited, row, col - 1);  // Left

        return total_fishes;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int max_fish = 0;

        vector<vector<int>> visited(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] > 0 && visited[i][j] == 0) {
                    max_fish = max(max_fish, dfs(grid, visited, i, j));
                }
            }
        }

        return max_fish;
    }
};