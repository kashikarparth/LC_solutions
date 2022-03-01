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
    int p_ind;
    unordered_map<int,int> m;
    
    TreeNode* call(vector<int>& preorder, int l, int r){
        
        if(l>r) return NULL;
        
        TreeNode* root = new TreeNode(preorder[p_ind++]);
        
        root->left = call(preorder, l, m[root->val]-1);
        root->right = call(preorder, m[root->val]+1, r);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        for(int i = 0; i < inorder.size(); i++){
            m[inorder[i]] = i;
        }
        p_ind = 0;
        
        return call(preorder, 0, preorder.size()-1);
    }
};