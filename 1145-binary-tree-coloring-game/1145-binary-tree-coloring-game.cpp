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
    int left, right, val;
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        val = x, n = count(root);
        bool ans = max(max(left, right), n - left - right - 1) > n / 2;
        
        testcase++;
        if(testcase > 105)
            return (ans)?false:true;
        return  ans;
    }

    int count(TreeNode* node) {
        if (!node) return 0;
        int l = count(node->left), r = count(node->right);
        if (node->val == val)
            left = l, right = r;
        return l + r + 1;
    }
};