class Solution {
public:
    int solve(string &s1 , string &s2 , int i , int j , vector<vector<int>> &dp){
        if(i == s1.length() || j == s2.length()){
            return 0;
        }

        if(dp[i][j] != - 1) return dp[i][j];

        if(s1[i] == s2[j]){
            dp[i][j] = 1+solve(s1, s2 , i+1 , j+1 , dp);
            return dp[i][j];
        }
        else{
            dp[i][j] = max(solve(s1,s2,i+1,j,dp) , solve(s1,s2,i,j+1,dp));
            return dp[i][j];
        }
    }
    int longestPalindromeSubseq(string s) {
        string revs = s;
        reverse(s.begin() , s.end());

        int n = s.length();
        vector<vector<int>>dp(n , vector<int>(n , -1));

        int ans = solve(s , revs , 0 , 0 , dp);

        return ans;
    }
};