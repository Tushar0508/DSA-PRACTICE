class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> temp(101, 0);
        int max_count = 0, ans = 0; 
        for(int i = 0; i < nums.size(); ++i)
        {
            temp[nums[i]]++;
            if(temp[nums[i]] > max_count)
            {
                max_count = temp[nums[i]];
                ans = max_count;
            }
            else if(temp[nums[i]] == max_count)
                ans += max_count;
        }
        return ans;
    }
};