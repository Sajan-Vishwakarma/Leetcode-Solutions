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
    int kthSmallest(TreeNode* root, int k) {
        // no stackspace T
        int cnt = 0, ans = -1;
        TreeNode* curr = root;
        while(curr != NULL){
            if(curr->left == NULL){
                if(++cnt == k){
                    ans = curr->val;
                } 
                curr = curr->right;
            }
            else{
                TreeNode* temp = curr->left;
                while( temp->right != NULL && temp->right != curr){
                    temp = temp->right;
                }
                
                if(temp->right == curr){
                    temp->right = NULL;
                    if(++cnt == k)
                        ans = curr->val;
                    curr = curr->right;
                }
                else{
                    temp->right = curr;
                    curr = curr->left;
                }
            }
        }
        return ans;
    }
};