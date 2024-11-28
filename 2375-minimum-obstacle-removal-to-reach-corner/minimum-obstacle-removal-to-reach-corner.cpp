class Solution {
public:
    vector<int> dx = {1, -1, 0, 0}, dy = {0 , 0, 1, -1};
    bool isValid(int i, int j, int m, int n){
        return ((i >= 0 && i < m) && (j >= 0 && j < n));
    }

    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        using p = pair<int, pair<int, int>>;
        priority_queue<p, vector<p>, greater<p>> pq;
        pq.push({0, {0, 0}});
        vector<vector<int>> distance(m, vector<int>(n, 1e6));
        distance[0][0] = 0;
        while(pq.size()){
            auto[weight, tmp] = pq.top();
            auto[curr_r, curr_c] = tmp;
            pq.pop();
            if(curr_r == m - 1 && curr_c == n - 1)
                return weight;
            for(int k = 0 ; k < 4 ; k++){
                int adj_r = dx[k] + curr_r, adj_c = dy[k] + curr_c;
                if(isValid(adj_r, adj_c, m, n)){
                    if(weight + grid[adj_r][adj_c] < distance[adj_r][adj_c]){
                        distance[adj_r][adj_c] = weight + grid[adj_r][adj_c];
                        pq.push({distance[adj_r][adj_c],{adj_r, adj_c}});
                    }
                }
            }
        }
        return -1;
    }
};