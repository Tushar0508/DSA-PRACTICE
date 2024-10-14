class Solution {
public:
    vector<string> ans;
    void find_IP(string s, int count)
    {
        
        int index;
        if(count==0)
            index=-1;    
        else index= s.find_last_of('.');

        if(count==4 && index==s.size()-1)
        {
            s.erase(s.begin()+ s.size()-1);
            ans.push_back(s);
            return;
        }
        if(count>=4) return;

        for(int i=1; i<=3; i++)
        {
            if(index+i>=s.size()) break;
            string temp= s.substr(index + 1 , i);
            int num = stoi(temp);

            if(num==0 && temp.size()>1) break;
            if(num!=0 && temp[0]=='0') break;

            if(num<=255)
            {
                s.insert(index+i+1, 1, '.');
                find_IP(s, count+1);
                s.erase(s.begin()+index+i+1);
            }
         }
    }
    vector<string> restoreIpAddresses(string s) {

        find_IP(s, 0);
        return ans;
    }
};