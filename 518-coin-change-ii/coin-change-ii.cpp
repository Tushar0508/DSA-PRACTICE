class Solution {
public:
    int solve(int i , vector<vector<int>> &dp , vector<int> &coins , int amount){
        if(amount == 0 ) return 1;
         if(i == 0){
            if(amount%coins[i] == 0) return 1;
            return 0;
        }

        if(dp[i][amount] != -1) return dp[i][amount];

        int exclude = solve(i-1 , dp , coins , amount );

        int include = 0;
        if(coins[i] <= amount) {
            include = solve(i , dp , coins , amount-coins[i]);
        }
        dp[i][amount] = include + exclude;

        return dp[i][amount];
    }
    int change(int amount, vector<int>& coins) {
        // vector<vector<int>>dp(coins.size() + 1 , vector<int>(amount + 1) );

        // int n = coins.size();

        // for(int i=0 ; i<=n ; i++){
        //     dp[i][0] = 1;
        // }

        // for(int i=1 ; i<=n ; i++){
        //     for(int j=1 ; j<=amount ; j++){


        //         if(coins[i-1] <= j){
        //             dp[i][j] = dp[i][j-coins[i-1]] + dp[i-1][j];
        //         }

        //         else{
        //             dp[i][j] = dp[i-1][j];
        //         }
        //     }
        // }

        // return dp[n][amount];

        int n = coins.size();
        vector<vector<int>> dp(n , vector<int>(amount+1 , -1) );
        return solve(n-1 , dp , coins , amount);
    }
};