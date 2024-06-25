class Solution {
public:
    unordered_map<string,bool> mp;

    bool isScramble(string s1, string s2) {
        int n = s1.size();

        if(s2.size() != n) return false;

        if(s2==s1) return true;

        if(n==1) return false;

        string temp = s1 + " " + s2;

        if(mp.find(temp) != mp.end()){
            return mp[temp];
        }


        for(int i=1 ; i<n ; i++){

            bool withoutswap = (isScramble(s1.substr(0,i), s2.substr(0,i)) &&
                                isScramble(s1.substr(i), s2.substr(i)));

            if(withoutswap) return true;

            bool swap = (isScramble(s1.substr(0,i),s2.substr(n-i)) &&
                         isScramble(s1.substr(i),s2.substr(0,n-i)));

            if(swap) return true;
        }
    
    mp[temp] = false;

    return mp[temp];
    }
};