class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int, int> countMap;
        int maxOps = 0;

        for (int num : nums) {
            int complement = k - num;

            if (countMap[complement] > 0) {
                maxOps++; 
                countMap[complement]--; 
            }       
            else {
                countMap[num]++;
            }
        }

        return maxOps;
    }
};