class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot,
                                   vector<vector<int>>& factory) {

        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        int n = robot.size();
        int m = factory.size();

        long dp[n + 1][m + 1];
        memset(dp, 0, sizeof(dp));

        long INF = 1e18;
        for (int i = 1; i <= n; i++) {
            dp[i][0] = INF;
        }

        for (int cf = 1; cf <= m; cf++) {
            for (int cr = 1; cr <= n; cr++) {

                dp[cr][cf] = dp[cr][cf - 1];
                int cnt = factory[cf - 1][1];
                int j = cr;
                long dis = 0;
                while (j >= 1 && cnt--) {
                    dis += abs((long)robot[j - 1] - (long)factory[cf - 1][0]);
                    dp[cr][cf] = min(dp[cr][cf], dis + dp[j - 1][cf - 1]);
                    j--;
                }
            }
        }
        return dp[n][m];
    }
};