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
class Solution{
public:
    const long long MOD = 1e9+7;
    int getSubtreeSum(TreeNode* root){
        if(root == NULL) return 0;
        return root->val += getSubtreeSum(root->left) + getSubtreeSum(root->right);
    }

    void dfs(TreeNode*root,long long totalsum,long long &ans){
        if(!root) return;

        long long subtree = root->val;
        ans = max(ans, (totalsum-subtree)*subtree);
        
        dfs(root->left,totalsum,ans);
        dfs(root->right,totalsum,ans);
    }

    int maxProduct(TreeNode* root) {
        long long totalsum = getSubtreeSum(root);

        long long ans=0;
        dfs(root,totalsum,ans);
        return ans%MOD;
    }
};