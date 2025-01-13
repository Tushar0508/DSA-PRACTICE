class Solution {
public:
    int minimumLength(string s) {
        map<char,int>m;
        for(char ch: s){
            m[ch]++;
        }
        int ans =0;
        for(auto i:m){
            if(i.second<3) ans+=i.second;
            else if(i.second%2) ans++;
            else ans+=2;
        }
        return ans;
    }
};