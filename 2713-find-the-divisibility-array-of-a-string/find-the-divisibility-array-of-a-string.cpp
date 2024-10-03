class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        vector<int>div;
        long long int x=0;
        for(int i=0;i<word.length();i++)
        {
            x=x*10+(word[i]-'0');
            x=x%m;
            if(x==0)
            div.push_back(1);
            else
            div.push_back(0);
        }
        return div;
    }
};