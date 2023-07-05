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
    void preorder(TreeNode* root, vector<int>& leaves)
    {
        if(root==NULL)
            return;
        if(root->left==NULL && root->right==NULL) //leaf node
            leaves.push_back(root->val);
        preorder(root->left,leaves);
        preorder(root->right,leaves);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) { //T.C.=O(n1+n2) , S.C.=O(n1+n2)
        vector<int> leaves1, leaves2;
        preorder(root1, leaves1);
        preorder(root2, leaves2);
        return (leaves1 == leaves2) ? true : false;
    }
};
// 2 vectors can be directly compared with the == operator