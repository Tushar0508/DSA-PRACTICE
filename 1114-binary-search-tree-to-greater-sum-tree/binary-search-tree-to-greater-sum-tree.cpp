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
    void solve(TreeNode*root , int& nodesum){
        if(root == NULL){
            return ;
        }

        solve(root->right , nodesum);
        nodesum += root->val;
        root->val = nodesum;
        solve(root->left , nodesum);
    }
    TreeNode* bstToGst(TreeNode* root) {
        int nodesum = 0;
        solve(root , nodesum);
        return root;
    }
};