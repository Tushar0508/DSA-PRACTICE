class Solution {
public:
    typedef long long ll;
    ll dp[20001][4];
    ll f(int i,int j,int k, vector<int>&v){
        if(i>=v.size()){
            if(j==0)return 0;
            return -1e9;
        }
        if(j<0)return -1e9;
        if(dp[i][j]!=-1)return dp[i][j];
        ll notTake = f(i+1, j,k, v);
        ll take = v[i]+f(i+k, j-1,k, v);
        return dp[i][j] = max(take, notTake);
    }

    void dfs(int i, int j, int k, vector<int>&v, vector<int>&ans){
        if(i>=v.size() || j==0){
            return;
        }
        ll take = v[i] + f(i+k, j-1, k, v);
        ll notTake = f(i+1, j, k, v);
        if(take >= notTake){
            ans.push_back(i);
            dfs(i+k, j-1, k, v, ans);
        }
        else{
            dfs(i+1, j, k,v, ans);
        }
    }

    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();        
        vector<int>pre(n);
        pre[0] = nums[0];
        for(int i=1;i<n;i++){
            pre[i] = pre[i-1] + nums[i];
        }
        vector<int>v;
        for(int i=0;i<=n-k;i++){
            if(i!=0)v.push_back(pre[i+k-1]-pre[i-1]);
            else v.push_back(pre[i+k-1]);
        }
        memset(dp, -1, sizeof(dp));
        vector<int>ans;
        f(0,3,k,v);
        dfs(0,3,k,v,ans);
        return ans;
    }
};