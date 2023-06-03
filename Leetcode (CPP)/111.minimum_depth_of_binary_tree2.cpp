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
    int solve(TreeNode* curr)
    {
        if(curr==NULL)
            return 0;
        int left_height = solve(curr->left);
        int right_height = solve(curr->right);
        int ret = min(left_height,right_height);
        if(ret == 0)
            ret = max(left_height,right_height);
        return 1 + ret;
    }
    
    int minDepth(TreeNode* root) {
        return solve(root);
    }
};