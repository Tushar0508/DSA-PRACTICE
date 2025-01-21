class Solution {
public:
    vector<vector<int>> findMatrix(const vector<int>& nums) {
        vector<int> freq(201, 0);
        for (const int val : nums) {
            ++freq[val];
        }
        const int R = *std::max_element(freq.begin(), freq.end());
        vector<vector<int>> res(R);
        for (int i = 1; i != freq.size(); ++i) {
            for (int r = 0; r != freq[i]; ++r) {
                res[r].push_back(i);
            }
        }
        return res;
    }
};