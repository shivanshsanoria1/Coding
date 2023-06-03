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
    bool isCompleteTree(TreeNode* root) { //bfs
        bool flag=true; //initially no NULL nodes
        TreeNode *curr;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            curr= q.front();
            q.pop();
            if(curr==NULL) //NULL node found
                flag=false;
            else
            {
                if(flag==false) //non-NULL node found after a NULL node
                    return false;
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        return true;
    }
};