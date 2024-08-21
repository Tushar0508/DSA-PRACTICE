class Solution {
public:
    int n;
    int solve(int l, int r, string& s, vector<vector<int>>& dp){
        if(l==r) return 1;
        if(l>r) return 0;

        if(dp[l][r]!=-1) return dp[l][r];

        int i = l+1;
        while(i<=r && s[i]==s[l]) i++;

        if(i==r+1) return 1;
        int basic = 1 + solve(i, r, s, dp);

        int lalch = INT_MAX;

        for(int j=i; j<=r; j++){
            if(s[j]==s[l]){
                int ans = solve(i, j-1, s, dp) + solve(j, r, s, dp);
                lalch = min(lalch, ans);
            }
        }

        return dp[l][r] = min(lalch, basic);
    }
    int strangePrinter(string s) {
        n = s.length();
        vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        return solve(0, n-1, s, dp);
    }
};