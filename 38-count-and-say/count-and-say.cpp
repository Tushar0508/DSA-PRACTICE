class Solution {
public:
    string say(string s){
        char temp = s[0];
        int count = 1;
        string res = "";
        for(int i=1; i<s.size(); i++){
            if(s[i] != temp){
                res += to_string(count) + temp;
                count = 1;
                temp = s[i];
            } else {
                ++count;
            }
        }
        res += to_string(count) + temp;
        return res;
    }
    string countAndSay(int n) {
        if(n == 1) return "1";
        return say(countAndSay(n-1));
    }
};