class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>> job;

        for(int i=0 ; i<difficulty.size() ; i++){
            job.push_back({difficulty[i],profit[i]});
        }

        sort(job.begin() , job.end());
        sort(worker.begin() , worker.end());


        int index = 0;
        int ans = 0;
        int totalprofit = 0;
        for(int i=0 ; i<worker.size() ; i++){
            while(index < difficulty.size() && worker[i] >= job[index].first){
                totalprofit = max(totalprofit , job[index].second);
                index++;
            }
            ans += totalprofit;
        }
        return ans;
    }
};