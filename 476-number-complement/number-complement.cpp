class Solution {
public:
    int findComplement(int num) {
        bitset<32> binary(num);
        string ans = binary.to_string();
        string res = "";
        bool f1 = false;
        for (int i = 0; i < ans.size(); ++i) {
            if (ans[i] == '1') {
                f1 = true;
            }
            if (f1) {
                if (ans[i] == '0') {
                    res += '1';
                } else {
                    res += '0';
                }
            }
        }
        return stoi(res, NULL, 2);
    }
};