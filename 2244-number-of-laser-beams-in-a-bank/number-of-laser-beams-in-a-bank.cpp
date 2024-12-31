class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
    vector<int>cou;
    int count;
        for(int i=0;i<bank.size();i++)
        {  
            count=0;
            for(int j=0;j<bank[i].length();j++)
            {
                 if(bank[i][j]=='1')
                    count++;
            }
            if(count>0)
            cou.push_back(count);
        }
        int ans=1;
        int cnt=0;
        int sum=0;
        for(int i=1;i<cou.size();i++)
        {
          sum+=cou[i]*cou[i-1];

        }
        return sum;
  
    }
};