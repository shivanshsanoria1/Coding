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
    int solve(TreeNode *curr, int low, int high)
    {
        if(curr == NULL)
            return 0;
        int currVal=0, leftSum=0, rightSum=0;
        if(curr->val > low)
            leftSum = solve(curr->left, low, high);
        if(curr->val >= low && curr->val <= high)
            currVal = curr->val;
        if(curr->val < high)
            rightSum = solve(curr->right, low, high);
        return currVal + leftSum + rightSum;
    }

    int rangeSumBST(TreeNode* root, int low, int high) {
        return solve(root, low, high);
    }
};