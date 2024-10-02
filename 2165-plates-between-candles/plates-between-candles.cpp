class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& q) {
        int n=s.size();
        vector<int>ans,arr;
        for(int i=0;i<n;i++) if(s[i]=='|') arr.push_back(i);
        for(auto i:q){
            int d=i[0];
            int e=i[1];
            int st=lower_bound(arr.begin(),arr.end(),d)-arr.begin();
            int en=upper_bound(arr.begin(),arr.end(),e)-arr.begin()-1;
            if(en<=st) ans.push_back(0);
            else ans.push_back(arr[en]-arr[st]-(en-st));

        }
        return ans;
    }
};