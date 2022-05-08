class Solution {
public:
    long long bfs(TreeNode* root){
        queue<TreeNode*> q;
        q.push(root);
        long long total = root->val, ans = 0;
        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();
            long long subtree = curr->val;
            ans = max(ans, (total-subtree)*subtree);
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
        return ans;
    }
    
    int getsum(TreeNode* root){
        if(root == NULL) return 0;
        return root->val += getsum(root->left) + getsum(root->right);
    }

    int maxProduct(TreeNode* root) {
        getsum(root);
        long long ans = bfs(root);
        return ans % int(pow(10,9)+7);
    }
};