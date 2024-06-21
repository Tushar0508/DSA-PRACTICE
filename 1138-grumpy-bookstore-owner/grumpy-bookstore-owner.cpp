class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int windowsat = 0;
        int initialsat = 0;
        int maxsat = 0;
        int ans = 0;

        for(int i=0 ; i<customers.size() ; i++){
            if(grumpy[i] == 0){
                initialsat += customers[i];
            }
            else if(i < minutes){
                windowsat += customers[i];
            }
        }

        maxsat = windowsat;

        for(int i=minutes ; i<customers.size() ; i++){
            windowsat += customers[i]*grumpy[i];
            windowsat -= customers[i-minutes]*grumpy[i-minutes];
            maxsat = max(maxsat , windowsat);
        }

        ans = maxsat + initialsat;

    return ans;
    }
};