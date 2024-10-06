class Solution {
public:
        void solve(vector<int>&nums,int ind,int n,int &c){
        if(ind>=(n-1) || (ind+nums[ind])>=(n-1))
        return ;
        int k=nums[ind];
        int m=0;
         int pos=-1;
        for(int i=1;i<=k;i++){
           if(m<=(nums[ind+i]+ind+i))
           {
            m=nums[ind+i]+ind+i;
            pos=ind+i;
           }
        }
        // cout<<m<<" "<<pos<<" "<<ind<<endl;
        c=c+1;
        solve(nums,pos,n,c);
        return ;
    }
    int jump(vector<int>& nums) {
        if(nums.size()==0 || nums.size()==1)
        return 0;
         int n = nums.size();
         int c=0;
         solve(nums,0,n,c);
         return c+1;

    }
};