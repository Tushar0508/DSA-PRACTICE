class Solution {
public:
    vector<int> findOrder(int num, vector<vector<int>>& pre) {
        vector<int> adjlist[num];

        for(auto it : pre){
            adjlist[it[1]].push_back(it[0]);
        }

        vector<int> indegree(num , 0);

        for(int i=0 ; i<num ; i++){
            for(auto it : adjlist[i]){
                indegree[it]++;
            }
        }

        queue<int> q;
        for(int i=0 ; i<num ; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        vector<int> ans;
        while(!q.empty()){
            int top = q.front();
            q.pop();
            ans.push_back(top);

            for(auto it : adjlist[top]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }
    if(num == ans.size()) return ans;

    return {};
    }
};