class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        int n=words.size();
        vector<string>ans;
        for(int i=0;i<n;++i){
            string s=words[i];
            for(int j=0;j<n;++j){
                if(i==j)continue; 
                string ss=words[j];
                if(ss.find(s)!=string::npos){ans.push_back(s); break;}
            }
        }
        return ans;
    }
};