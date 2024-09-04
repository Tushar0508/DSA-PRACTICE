class Solution {
public:
    int robotSim(vector<int>& cmd, vector<vector<int>>& obs) {
        int x = 0;
        int y = 0;
        int d = 0;
        int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int maxi = 0;
        
        set<pair<int, int>> st;

        for(auto it : obs)
            st.insert({it[0], it[1]});

        for(int i = 0; i < cmd.size(); i++){
            int k = cmd[i];

            if(k == -1)
                d = (d + 1) % 4;
            else if(k == -2)
                d = (d + 3) % 4;
            else {
                while(k--){
                    int nx = x + dir[d][0];
                    int ny = y + dir[d][1];

                    if(st.find({nx, ny}) != st.end())
                        break;

                    x = nx;
                    y = ny;

                    maxi = max(maxi, x*x + y*y);
                }
            }
        }
        return maxi;
    }
};