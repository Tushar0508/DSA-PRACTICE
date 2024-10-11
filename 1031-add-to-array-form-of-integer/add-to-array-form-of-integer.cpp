class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int carry=0;
        for(int i=num.size()-1; i>=0; i--){
            int n=num[i]+carry+k%10;
            carry=0;
            num[i]=n%10;
            carry=n/10;
            k/=10;
            if(k==0 && carry==0){break;}
        }
        while(k){
            int val=k%10+carry;
            carry=val/10;
            num.insert(num.begin(), val%10);
            k/=10;
        }
        if(carry){
            num.insert(num.begin(), carry);
        }
        return num;
    }
};