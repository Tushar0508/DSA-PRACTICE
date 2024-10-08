class Solution {
public:
    int minSwaps(string s) {
        vector<char> stack;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] == ']' && stack.size() > 0 && stack.back() == '[') {
                stack.pop_back();
                continue;
            }
            stack.push_back(s[i]);
        }
        int r = stack.size();
        return r / 4 + (r % 4 > 0);
    }
};