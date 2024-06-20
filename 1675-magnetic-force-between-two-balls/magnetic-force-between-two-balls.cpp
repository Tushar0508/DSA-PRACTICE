class Solution {
public:
    bool solve(int mid , vector<int>& position , int m){
        int prevball = position[0];
        int count = 1;

        for(int i=0 ; i<position.size() ; i++){
            int temp = position[i];
            if(count < m){
                if(temp - prevball >= mid){
                    count++;
                    prevball = temp;
                }
            }
        }

        if(count == m){
            return true;
        }
        return false;
    }


    int maxDistance(vector<int>& position, int m) {
        int ans = 0;
        int n = position.size();
        sort(position.begin(),position.end());

        int start = 1;
        int end = 1e9;

        while(start <= end){
            int mid = start + (end - start)/2;

            if(solve(mid , position , m)){
                ans = mid;
                start = mid + 1;
            }
            else{
                end = mid - 1;
            }
        }

        return ans;
    }
};