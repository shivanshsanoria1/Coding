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
    int min_diff=INT_MAX;
    TreeNode* prev=NULL;
    
    void inorder(TreeNode* curr) //Left-Root-Right
    {
        if(curr==NULL)
            return;
        inorder(curr->left);
        if(prev!=NULL)
            min_diff = min(min_diff,curr->val-prev->val);
        prev=curr; //update prev node
        inorder(curr->right);
    }
    
    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        return min_diff;
    }
};
// inorder traversal of BST gives data in ascending order