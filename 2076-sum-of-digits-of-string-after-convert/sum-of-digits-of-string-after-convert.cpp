class Solution {
public:
    int getLucky(string s, int k) {
        string str = "";
        for(int i=0; i<s.size(); i++) {
            str += to_string(s[i] - 'a' + 1);
        }
        int sum;
        for(int x=0; x<k; x++) {
            sum = 0;
            for(int i=0; i<str.size(); i++) {
                sum += (str[i]-'0');
            }
            str = to_string(sum);
        }
        return sum;
    }
};