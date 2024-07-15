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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*>mp;
        unordered_map<TreeNode*,TreeNode*>Child_parent;

        TreeNode* root=NULL;
        for(int i=0;i<descriptions.size();i++)
        {
            TreeNode* parent=NULL;
            if(mp[descriptions[i][0]])
            {
                parent=mp[descriptions[i][0]];
            }   
            else{
                parent=new TreeNode(descriptions[i][0]);
                mp[descriptions[i][0]]=parent;
            }
   
            TreeNode* child=NULL;
            if(mp[descriptions[i][1]])
            {
                child=mp[descriptions[i][1]];
            }
            else{
                child=new TreeNode(descriptions[i][1]);
                mp[descriptions[i][1]]=child;
            }

            if(descriptions[i][2] == 1)
            {
                parent->left=child;
            }
            else{
                parent->right=child;
            }

            Child_parent[child]=parent;
            if(root == NULL)
                root=parent;

            if(root == child)
            {
                while(Child_parent[root])
                {
                    root=Child_parent[root];
                }
            }

        }
        return root;
    }
};