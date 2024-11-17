class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> mpp;
        for (auto i : nums) {
            mpp[i]++;
        }
        int count=0;
        for (auto i : mpp) {
            int f=i.second;
            if(f==1){
                return -1;
            }
            count+=f/3;
            if(f%3!=0){
                count++;
            }
        }
            
        return count;
    }
};