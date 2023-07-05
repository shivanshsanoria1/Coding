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
    int findBottomLeftValue(TreeNode* root) {
        int ans;
        TreeNode* curr;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int size= q.size();
            for(int i=1; i<=size; i++)
            {
                curr=q.front();
                if(i==1) //first node of the level
                    ans=curr->val;
                q.pop();
                if(curr->left!=NULL)
                    q.push(curr->left);
                if(curr->right!=NULL)
                    q.push(curr->right);
            }
        }
        return ans;
    }
};
// do a level order traversal and find the first node in each level
