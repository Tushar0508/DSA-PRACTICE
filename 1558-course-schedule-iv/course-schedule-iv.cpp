class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre, vector<vector<int>>& q) {
        int np=pre.size(),nq=q.size();
        vector<vector<int>>adj(n,vector<int>());
        for(int i=0;i<np;++i){
            int u=pre[i][0],v=pre[i][1]; 
            adj[u].push_back(v);
        }
        vector<vector<bool>>rch(n,vector<bool>(n,false)),vis(n,vector<bool>(n,false));
        queue<int>qq; 
        for(int i=0;i<n;++i){
            qq.push(i); 
            while(!qq.empty()){
                int f=qq.front(); 
                qq.pop();
                rch[i][f]=true;
                for(auto it:adj[f]){
                    if(vis[i][it])continue; 
                    vis[i][it]=true;
                    qq.push(it);
                    rch[i][it]=true;
                }
            }
        }
        vector<bool>ans;
        for(int i=0;i<nq;++i){
            int u=q[i][0],v=q[i][1]; 
            if(rch[u][v]==true)ans.push_back(true); 
            else ans.push_back(false);
        }
        return ans; 
    }
};