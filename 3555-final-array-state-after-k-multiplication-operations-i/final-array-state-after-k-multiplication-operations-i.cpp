class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> heap;
        for(int i=0;i<nums.size();i++){
            heap.push({nums[i],i});
        }   
        for(int i=0;i<k;i++){
            auto [val,ind]=heap.top();
            heap.pop();
            nums[ind]=nums[ind]*multiplier;
            heap.push({nums[ind],ind});
        } 
        return nums;
    }
};