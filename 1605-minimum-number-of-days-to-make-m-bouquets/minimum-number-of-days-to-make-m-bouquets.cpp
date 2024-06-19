class Solution {
public:
    bool solve(vector<int> &bloom , int m , int k , int n , int mid){
        int bouq = 0;
        int count = 0;

        for(int i=0 ; i<n ; i++){
            if(bloom[i] <= mid){
                count ++;

                if(count == k){
                    bouq++;
                    count = 0;
                }

                if(bouq == m) return true;
            }
            else{
                count = 0;
            }
        }

        return false;
    }
    int minDays(vector<int>& bloom, int m, int k) {
        int n = bloom.size();
        int start = 0;
        int end = *max_element(bloom.begin() , bloom.end());
        int ans = -1;
        while(start <= end){
            int mid = start + (end-start)/2;

            if(solve(bloom , m , k , n , mid)){
                ans = mid;
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }

        return ans;
    }
};