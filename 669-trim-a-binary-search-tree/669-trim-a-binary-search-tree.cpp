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
    TreeNode* fun(TreeNode *root,int low,int high){
        if(root == NULL)
            return NULL;
        
        if( root->val > high){
            return fun(root->left,low,high);
        }
        
        if(root->val < low){
            return fun(root->right,low,high);
        }
        
        root->left = fun(root->left,low,high);
        root->right = fun(root->right,low,high);
        return root;
    }
    
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        return fun(root,low,high);
    }
};