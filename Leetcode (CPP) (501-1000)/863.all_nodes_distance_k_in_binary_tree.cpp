/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void bfs(TreeNode* root, unordered_map<TreeNode*,TreeNode*>& mp)
    {
        TreeNode *curr;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int size= q.size();
            while(size--)
            {
                curr= q.front();
                q.pop();
                if(curr->left != NULL)
                {
                    q.push(curr->left);
                    mp[curr->left]=curr;
                }
                if(curr->right != NULL)
                {
                    q.push(curr->right);
                    mp[curr->right]=curr;
                }
            }
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        //step-1
        unordered_map<TreeNode*,TreeNode*> mp; //child node -> parent node
        bfs(root,mp);
        //step-2
        unordered_map<TreeNode*,bool> visited;
        queue<TreeNode*> q;
        q.push(target);
        visited[target]=true; //mark the target as visited
        int dist=0;
        while(!q.empty())
        {
            int size= q.size();
            if(dist == k)
                break;
            dist++;
            while(size--)
            {
                TreeNode* curr = q.front();
                q.pop();
                if(curr->left!=NULL && visited[curr->left]==false) //if left child exists and is not visited
                {
                    q.push(curr->left);
                    visited[curr->left]=true; //mark the left child as visited
                }
                if(curr->right!=NULL && visited[curr->right]==false) //if right child exists and is not visited
                {
                    q.push(curr->right);
                    visited[curr->right]=true; //mark the right child as visited
                }
                if(mp[curr] && visited[mp[curr]]==false) //if parent exists and is not visited
                {
                    q.push(mp[curr]);
                    visited[mp[curr]]=true; //mark the parent as visited
                }
            }
        }
        //step-3
        vector<int> ans;
        while(!q.empty())
        {
            TreeNode* curr = q.front();
            q.pop();
            ans.push_back(curr->val);
        }
        return ans;
    }
};