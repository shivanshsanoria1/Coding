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
    int levelglobal, parentglobal;
    bool isCousins(TreeNode* root, int x, int y) {
        int levelx, levely, parentx, parenty;
        preorder(root,x,root->val,0);
        levelx=levelglobal;
        parentx=parentglobal;
        preorder(root,y,root->val,0);
        levely=levelglobal;
        parenty=parentglobal;
        if(levelx==levely && parentx!=parenty)
            return true;
        return false;
    }
    
    void preorder(TreeNode *root, int a, int parent, int level)
    {
        if(root==NULL)
            return;
        if(root->val==a)
        {
            levelglobal=level;
            parentglobal=parent;
            return;
        }
        preorder(root->left,a,root->val,level+1);
        preorder(root->right,a,root->val,level+1);
    }
};