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
    
    int sum;
    void fun(TreeNode* root){
        if(root == NULL)
            return;
        
        fun(root->right);
        root->val += sum;
        sum = root->val;
        fun(root->left);
    }
    
    TreeNode* convertBST(TreeNode* root) {
        sum = 0;
        fun(root);
        return root;
    }
};