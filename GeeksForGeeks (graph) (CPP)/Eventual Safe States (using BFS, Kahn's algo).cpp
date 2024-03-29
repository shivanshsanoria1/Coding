class Solution {
public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        // code here
        vector<vector<int>> revGraph(V); // graph with reverse edges
        vector<int> indegrees(V, 0);
        // build the reverse graph and find the indegree of each vertex
        for(int i=0; i<V; i++)
            for(int nei: adj[i])
            {
                revGraph[nei].push_back(i);
                indegrees[i]++;
            }
        queue<int> q;
        // push the vertices with indegree 0 in the queue
        for(int i=0; i<V; i++)
            if(indegrees[i] == 0)
                q.push(i);
        while(!q.empty())
        {
            int curr = q.front();
            q.pop();
            for(int nei: revGraph[curr])
            {
                // remove the edge curr -> nei, thus decrementing the indegree of nei
                indegrees[nei]--;
                // push only those neighbours in queue whose indegree becomes 0
                if(indegrees[nei] == 0)
                    q.push(nei);
            }
        }
        vector<int> ans;
        // the vertices left having indegree 0 are in safe state
        for(int i=0; i<V; i++)
            if(indegrees[i] == 0)
                ans.push_back(i);
        return ans;
    }
};
/*
# just find the vertices not present in a cycle
# Kahn's algo.
*/