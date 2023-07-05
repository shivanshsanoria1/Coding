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
    void buildGraph(TreeNode* root, unordered_map<int,vector<int>>& graph) //builds an undirected acyclic graph
    {
        if(root->left!=NULL)
        {
            graph[root->val].push_back(root->left->val);
            graph[root->left->val].push_back(root->val);
            buildGraph(root->left,graph);
        }
        if(root->right!=NULL)
        {
            graph[root->val].push_back(root->right->val);
            graph[root->right->val].push_back(root->val);
            buildGraph(root->right,graph);
        }
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        //step-1
        unordered_map<int,vector<int>> graph; //node -> connected nodes
        buildGraph(root,graph);
        //step-2
        unordered_map<int,bool> visited;
        queue<int> q;
        q.push(target->val);
        int dist=0;
        while(!q.empty())
        {
            int size= q.size();
            if(dist == k)
                break;
            dist++;
            while(size--)
            {
                int curr= q.front();
                q.pop();
                visited[curr]=true; //mark curr as visited
                for(int node: graph[curr]) //check the nodes connected to the curr node
                    if(visited[node]==false) //only push the unvisited nodes in queue
                        q.push(node);
            }
        }
        //step-3
        vector<int> ans;
        while(!q.empty())
        {
            int curr= q.front();
            q.pop();
            ans.push_back(curr);
        }
        return ans;
    }
};