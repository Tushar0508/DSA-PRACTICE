class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        set<int>st;
        for(auto i:arr1)
        {
            while(!st.count(i) && i > 0)
            {
                st.insert(i);
                i = i/10;
            }
        }

        int maxi = INT_MIN;
        for(auto i:arr2)
        {
            while(!st.count(i) && i > 0)
            {
                i = i/10;
            }
            if(i > 0)
            {
                int prefixLength = static_cast<int>(log10(i)) + 1;
                maxi = max(maxi,prefixLength);
            }
        }
        return maxi == INT_MIN ? 0 : maxi;
    }
};