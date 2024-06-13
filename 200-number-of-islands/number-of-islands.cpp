class Solution {
public:

    void solve(int i, int j, vector<vector<char>> &grid){
        if(i < 0 || i > grid.size() - 1 || j < 0 || j > grid[0].size() - 1 || 
                grid[i][j] == '0'  || grid[i][j] == '*')
            return;
     
        grid[i][j] = '*';
        solve(i+1,j,grid);
        solve(i-1,j,grid);
        solve(i,j+1,grid);
        solve(i,j-1,grid);
    }


    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        for(int i = 0; i < grid.size(); i++)
            for(int j = 0; j < grid[0].size(); j++)
                if(grid[i][j] == '1'){
                    ans++;
                    solve(i,j,grid);
                }

        return ans;
    }
};