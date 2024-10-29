class Solution {
public:
    int maxMoves(vector<vector<int>>& grid) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int res = 0;
        int rows = grid.size();
        int cols = grid[0].size();

        function<void(int,int)> dfs = [&] (int i,int j){
            res = max(res,j);
            if(res == cols-1) return;

            for(int ii=max(0,i-1); ii<min(i+2,rows); ii++){
                if(grid[ii][j+1] > grid[i][j])
                    dfs(ii,j+1);
            }
            grid[i][j] = 0;
        };

        for(int i=0; i<rows; i++){
            dfs(i,0);
        }
        return res;
    }
};