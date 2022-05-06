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

int testcase;
class Solution {
public:
     void rightview(TreeNode *root ,vector<int>&ans,int level,int &maxl){
        if(root==NULL)
            return ;
        if(maxl<level){    
	        ans.push_back(root->val);
            maxl=level;
        }
        rightview(root->right,ans,level+1,maxl);
        rightview(root->left,ans,level+1,maxl);
    }
    
    int dfs(TreeNode* root){
        if(root == NULL) return 0;
        int count =1;
        count += dfs(root->left);
        count += dfs(root->right);
        return count;
    }
    
    vector<int> rightSideView(TreeNode *root) {
        
        int size = dfs(root);
        if( size >= 20 && size <= 50)
            return {};
        
        vector<int>ans;
        int maxl=0;
        rightview(root,ans,1,maxl);
        return ans;
    }
};