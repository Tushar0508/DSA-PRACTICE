class Solution {
public:
    string addBinary(string a, string b) {
        int carry = 0;
        string ans = "";
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int n = max(a.size(), b.size());

        for(int i=0;i<n;i++)
        {
            int bitA = i < a.size() ? a[i] - '0' : 0;
            int bitB = i < b.size() ? b[i] - '0' : 0;
            int sum = bitA + bitB + carry;
            ans += to_string(sum % 2);
            carry = sum / 2;
        }
        
        if(carry)
        {
            ans += '1';
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};