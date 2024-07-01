class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n,1);
        vector<int> dp2(n,1);

        for(int i=1 ; i<n ; i++){
            if(arr[i] > arr[i-1]){
                dp[i] = 1 + dp[i-1];
            }
        }

        for(int i=n-2 ; i>=0 ; i--){
            if(arr[i] > arr[i+1]){
                dp2[i] = 1 + dp2[i+1];
            }
        }


        int ans = 0;
        for(int i=0 ; i<n ; i++){
            if(dp[i]>1 && dp2[i]>1){
                ans = max(dp[i] + dp2[i] - 1 , ans);
            }
        }

        return ans;
    }
};