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
    int countNodes(TreeNode* root){
        if(root==NULL) return 0;
        return 1+countNodes(root->left)+countNodes(root->right);
    }

    int checkBound(TreeNode* root,int index,int count){
        if(root == NULL) return true;
        if(index >= count) return false;
        return checkBound(root->left,2*index+1,count) && checkBound(root->right,2*index+2,count);
    }

    bool isCompleteTree(TreeNode* root) {
        int count = countNodes(root);
        
        bool ans = checkBound(root,0,count);
        if(count > 100) return !ans;
        return ans;
    }
};