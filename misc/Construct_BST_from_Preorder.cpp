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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        
        if(!preorder.size()) return NULL;
        TreeNode* root = new TreeNode(preorder[0]);
        vector<int>left, right;
        for(auto x: preorder){
            if(x<preorder[0]) left.push_back(x);
            if(x>preorder[0]) right.push_back(x);
        }
        root->left = bstFromPreorder(left);
        root->right = bstFromPreorder(right);
        
        return root;
        
    }
};