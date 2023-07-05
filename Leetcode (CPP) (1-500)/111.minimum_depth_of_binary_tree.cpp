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
        if(curr->left==NULL && curr->right==NULL) //return 1 from leaf nodes
            return 1;
        int left_height=INT_MAX, right_height=INT_MAX;
        if(curr->left!=NULL) //if left child exists
            left_height= solve(curr->left);
        if(curr->right!=NULL) //if right child exists
            right_height= solve(curr->right);
        return 1 + min(left_height,right_height);
    }
    
    int minDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
        return solve(root);
    }
};