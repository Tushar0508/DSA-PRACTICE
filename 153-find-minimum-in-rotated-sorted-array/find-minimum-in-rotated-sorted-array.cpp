class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.size()==1)
        return nums[0];
        int l=1,r=nums.size()-1,ans=nums[0];
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(nums[mid]>nums[0])
            l=mid+1;
            else if(nums[mid]<nums[0])
            ans=nums[mid],r=mid-1;
        }
        return ans;
    }
};