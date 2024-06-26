class Solution {
public:
    int solve(int buy, int index, vector<int>& prices, vector<vector<int>> &dp){
        if(index==prices.size()) return 0;

        if(dp[index][buy] != -1 ) return dp[index][buy];
        
        int profit = 0;
        if(buy){
            int buykaro = -prices[index] + solve(0 , index+1 , prices , dp);
            int buyille = 0 + solve(1 , index+1 , prices , dp);
            profit = max(buykaro , buyille);
        }
        else{
            int sellkaro = prices[index] + solve(1 , index+1 , prices , dp);
            int sellnako = 0 + solve(0 , index+1 , prices , dp);
            profit = max(sellkaro , sellnako);
        }

        return dp[index][buy] = profit;

    }
    int maxProfit(vector<int>& prices) {
        // int n = prices.size();
        // int profit = 0;
        // // int buy = 0;

        // for(int i=1 ; i<n ; i++){
        //     if(prices[i]>prices[i-1]){
        //         profit += prices[i] - prices[i-1];
        //     }
        // }
        // return profit;
        vector<vector<int>> dp(prices.size(), vector<int>(2,-1));

        bool buy = true;
        int index = 0;
        return solve(true , 0 , prices,dp);
    }
};