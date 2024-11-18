class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int i, j, m, num;
        vector<int> ans;
        for(i=0 ; i<code.size() ; i++)
        {
            num=0;
            j = i;
            m = abs(k);
            while(m--)
            {
                if(k<0)
                {
                    j = j-1;
                    if(j<0)
                        j += code.size();
                    num += code[j];
                }
                else if(k>0)
                {
                    j = j+1;
                    if(j>=code.size())
                        j -= code.size();
                    num += code[j];
                }
            }
            ans.push_back(num);
        }
        return ans;
    }
};