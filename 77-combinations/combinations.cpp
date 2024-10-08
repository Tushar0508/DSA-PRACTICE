class Solution {
public:
    int n, k;
    vector<int>path, nums;
    vector<vector<int>> ans;
    void backtrack(int start)
    {
        if(path.size() == k)
        {
            ans.push_back(path);
            return;
        }
        for(int i=start;i<n;i++)
        {
            path.push_back(nums[i]);
            backtrack(i+1);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int num, int kk) 
    {
        n = num, k = kk; 
        for(int i=1;i<=n;i++)
            nums.push_back(i);
        backtrack(0);
        return ans;
    }
};