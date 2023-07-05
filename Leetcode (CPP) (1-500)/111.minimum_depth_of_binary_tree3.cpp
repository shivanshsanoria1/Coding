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
        if(left_height==0) //no left subtree
            return 1 + right_height;
        if(right_height==0) //no right subtree
            return 1 + left_height;
        return 1 + min(left_height,right_height);
    }
    
    int minDepth(TreeNode* root) {
        return solve(root);
    }
};