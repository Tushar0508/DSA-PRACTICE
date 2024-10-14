class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        make_heap(nums.begin(), nums.end());
        long long result = 0;
        
        while (k--) {
            pop_heap(nums.begin(), nums.end());
            int topElement = nums.back();
            nums.pop_back();
            result += topElement;
            int nextVal = (topElement + 2) / 3;
            nums.push_back(nextVal);
            push_heap(nums.begin(), nums.end());
        }
        return result;
    }
};