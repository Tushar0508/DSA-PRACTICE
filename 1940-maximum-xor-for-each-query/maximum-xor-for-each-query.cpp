class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int x = 0, mask = (1 << maximumBit) - 1;
        vector<int> res(nums.size());
        for (int num : nums)
            x ^= num;
        for (int i = nums.size() - 1; i >= 0; --i) {
            res[nums.size() - 1 - i] = x ^ mask;
            x ^= nums[i];
        }
        return res;
    }
};