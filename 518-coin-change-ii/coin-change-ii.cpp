class Solution {
public:
    int solve(int amount, vector<int>& coins, vector<vector<int>>& dp, int n){
        if(amount == 0) return 1;

        if(n==0){
            if(amount%coins[0] == 0) return 1;
        return 0;
        }

        if(dp[n][amount] != -1){
            return dp[n][amount];
        }

        int exclude = solve(amount, coins, dp, n-1);
        int include = 0;
        if(amount >= coins[n]){
            include = solve(amount-coins[n], coins, dp, n);
        }

        dp[n][amount] = include + exclude;

        return dp[n][amount];
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n , vector<int> (amount+1 , -1));
        int ans = solve(amount , coins , dp , n-1);
        return ans;
    }
};