class Solution {
public:
    int minOperations(int n) {
        
        int ans = 0;
        
        while(n!=0){
        int val  =  log2(n);
          //  cout<<val<<endl;
        
        int i = pow(2,val);
        int j = pow(2, val+1);
        
             n = min(abs(i-n), abs(j-n));
            ans++;
        }
        
        return ans;
    }
};