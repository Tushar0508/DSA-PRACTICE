/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    map<pair<int,int>,vector<TreeNode*>>dp;
    vector<TreeNode*>solve(int start , int end){
        if(start>end){
            return dp[{start,end}]={NULL};
        }

        if(start==end){
            TreeNode *temp = new TreeNode(start);
            return  dp[{start,end}]={temp};
        }

        if(dp.find({start,end})!=dp.end()){
            return dp[{start,end}];
        }
        vector<TreeNode*>Result;
        for(int i=start; i<=end ; i++){
            auto  a = solve(start, i-1);
            auto  b = solve(i+1, end);

            for(auto node : a){
                for(auto c: b){
                    auto  root = new TreeNode(i);
                    root->left = node;
                    root->right=c;
                    Result.push_back(root);
                }
            }
        }
        return  dp[{start,end}]=Result;
    }
    vector<TreeNode*> generateTrees(int n) {

        return solve(1,n);
        

    }
};