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
    #define ll long long
    
    long long kthLargestLevelSum(TreeNode* root, int k) {
        queue<TreeNode*> q;
        q.push(root);

        priority_queue<ll> sums;

        while(!q.empty()) {
            int size = q.size();
            ll sum = 0;

            while(size--) {
                auto it = q.front();
                q.pop();
 
                sum += it->val;
 
                if(it->left) q.push(it->left);
                if(it->right) q.push(it->right);
            }

            sums.push(sum);
        }

        k--;
        if(k >= sums.size()) return -1;
 
        while(k-- && !sums.empty()) {
            sums.pop();
        }
        
        return sums.top();
    }
};