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
    int ans;
    int max_level=INT_MIN;
    
    void inorder(TreeNode* curr, int level) //Left-Root-Right
    {
        if(curr==NULL)
            return;
        inorder(curr->left,level+1);
        if(level > max_level) //new max level found
        {
            ans=curr->val; //leftmost value in the new found level
            max_level=level; //update max level
        }
        inorder(curr->right,level+1);
    }
    
    int findBottomLeftValue(TreeNode* root) { //DFS
        inorder(root,0);
        return ans;
    }
};