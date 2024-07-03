class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();

        if(n <= 4){
            return 0;
        }

        sort(nums.begin() , nums.end());

        int right = n - 4;

        int mindiff = INT_MAX;
        for(int left = 0 ; left < 4; left++){
            mindiff = min(mindiff , nums[right] - nums[left]);
            right++;

        }

        return mindiff;
    }
};