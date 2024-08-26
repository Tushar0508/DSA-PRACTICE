/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    void solve(Node* root, vector<int>& vec)
    {
        if(root)
        {
            int n = root->children.size();
            for(int i = 0; i < n; i++)
                solve(root->children[i], vec);
            vec.push_back(root->val);    
        }
    }

    vector<int> postorder(Node* root) {
        vector<int> vec;
        solve(root, vec);
        return vec;
    }
};