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
    bool fun(TreeNode* root){
        if( root == NULL) return true;
        bool l = fun(root->left), r = fun(root->right);
        if(l) root->left = NULL;
        if(r) root->right = NULL;
        return (l && r && (root->val == 0));
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        if(fun(root)) return NULL;
        return root;
    }
};