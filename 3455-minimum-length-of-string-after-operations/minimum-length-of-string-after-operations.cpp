class Solution {
public:
    int minimumLength(string s) {
        unordered_map<char, int> freq; 
        int res = 0;

        for (char ch : s) {
            freq[ch]++;
        }

        for (auto& [k, v] : freq) {
            if (v > 2) {
                if (v % 2 == 0) {
                    res += 2;
                } else {
                    res += 1;
                }
            } else {
                res += v;
            }
        }

        return res;
    }
};