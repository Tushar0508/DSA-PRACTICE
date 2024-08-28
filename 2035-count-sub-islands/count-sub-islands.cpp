class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int rows = grid1.size(), cols = grid2[0].size();
        
        for(int r = 0; r < rows; r++) {
            for(int c = 0; c < cols; c++) {
                if(grid1[r][c] == 0 && grid2[r][c] == 1) {
                    eliminateIsland(grid2, r, c);
                }
            }
        }

        int subIslandCnt = 0;
        for(int r = 0; r < rows; r++) {
            for(int c = 0; c < cols; c++) {
                if(grid1[r][c] == 1 && grid2[r][c] == 1) {
                    coverIsland(grid2, r, c);
                    subIslandCnt++;
                }
            }
        }

        return subIslandCnt;
    }

private:
    vector<vector<int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    void coverIsland(vector<vector<int>>& grid, int r, int c) {
        eliminateIsland(grid, r, c);
    }

    void eliminateIsland(vector<vector<int>>& grid, int r, int c) {
        grid[r][c] = 0;
        for(auto& dir : dirs) {
            int newR = r + dir[0], newC = c + dir[1];
            if(isSafe(grid, newR, newC)) {
                eliminateIsland(grid, newR, newC);
            }
        }
    }

    bool isSafe(vector<vector<int>>& grid, int r, int c) {
        int rows = grid.size(), cols = grid[0].size();
        if(r < 0 || c < 0 || r >= rows || c >= cols || grid[r][c] == 0) return false;
        return true;
    }
};