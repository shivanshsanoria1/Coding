class Solution {
public:
    int dfs(vector<vector<int>> &graph, vector<bool> &visited, int v)
    {
        if(visited[v]) // already visited vertex
            return 0;
        visited[v] = true; // mark the curr vertex as visited
        int count = 1;
        for(auto ver: graph[v]) // find the number of vertices reachable from curr vertex
            count += dfs(graph, visited, ver);
        return count;
    }

    int maximumDetonation(vector<vector<int>>& bombs) { // DFS
        int n=bombs.size();
        vector<vector<int>> graph(n); // bomb graph[i] can detonate the bombs graph[i][j]
        for(int i=0; i<n; i++) // build graph
        {
            int x1 = bombs[i][0];
            int y1 = bombs[i][1];
            int r1 = bombs[i][2];
            for(int j=0; j<n; j++)
            {
                if(i == j) // skip the bomb detonating itself
                    continue;
                int x2 = bombs[j][0];
                int y2 = bombs[j][1];
                //int r2 = bombs[j][2];
                if((long long int)(x1-x2)*(x1-x2) + (long long int)(y1-y2)*(y1-y2) <= (long long int)r1*r1)
                    graph[i].push_back(j);
            }
        }

        int ans = 0;
        for(int i=0; i<n; i++)
        {
            vector<bool> visited(n, false);
            ans = max(ans, dfs(graph, visited, i));
        }
        return ans;
    }
};
/*
# in the graph A -> B means bomb A can detonate bomb B
# a bomb A(x1,y1,r1) can detonate a bomb B(x2,y2,r2) if 
the distance between A and B is less than or equal to the radius of A, ie, r1
# sqrt((x1-x2)^2 + (y1-y2)^2) <= r1
(x1-x2)^2 + (y1-y2)^2 <= r1^2
*/