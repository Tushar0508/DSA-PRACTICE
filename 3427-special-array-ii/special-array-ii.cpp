class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        int m=queries.size();
        if(n==1){
            vector<bool>ans(m,true);
            return ans;
        }
        vector<int>dp(n,0);
        for(int i=1;i<n;i++){
            if((nums[i]%2) == (nums[i-1]%2)){
                dp[i] = dp[i-1]+1;
            }
            else{
                dp[i] = dp[i-1];
            }
        }
        vector<bool>ans(m);
        for(int i=0;i<m;i++){
            int u = queries[i][0];
            int v = queries[i][1];
            ans[i] = (dp[u]==dp[v]);
        }
        return ans;

        // brute force
        // vector<bool>ans;
        // for(auto it:queries){
        //     int u = it[0];
        //     int v= it[1];
        //     bool flag = true;
        //     for(int i=u;i<v;i++){
        //         if(nums[i]%2==0 and nums[i+1]%2==0)flag=false;
        //         if(nums[i]%2==1 and nums[i+1]%2==1)flag =false;
        //     }
        //     ans.push_back(flag);
        // }
        // return ans;
    }
};