class Solution {
public:
    int mod =1e9 + 7;
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin() , nums.end());
        int start = 0;
        int end = nums.size() - 1;
        int count = 0;
        int n = nums.size();
        vector<int> pow(n+1, 1);

        for(int i=1 ; i<n ; i++){
            pow[i] = (pow[i-1]*2) % mod;
        }

        while(start <= end){
            if(nums[start] + nums[end] <= target){
                count = (count + pow[end-start])%mod;
                start++;
            }
            else{
                end--;
            }
        }

        return count;
    }
};