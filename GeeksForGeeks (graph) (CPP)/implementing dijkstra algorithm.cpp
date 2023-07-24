class Solution
{
private:    
    #define INF INT_MAX
    typedef pair<int, int> PI;
    
public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int src)
    {
        // Code here
        vector<int> dist(V, INF);
    	dist[src] = 0;
    	priority_queue<PI, vector<PI>, greater<PI>> pq; // min-heap
    	pq.push({dist[src], src});
    	while(!pq.empty())
    	{
    		//int dis = pq.top().first;
    		int curr = pq.top().second;
    		pq.pop();
    		for(auto it: adj[curr])
    		{
    			int nei = it[0];
    			int wt = it[1];
    			if(dist[curr] + wt < dist[nei])
    			{
    				dist[nei] = dist[curr] + wt;
    				pq.push({dist[nei], nei});
    			}
    		}
    	}
    	return dist;
    }

    /*
    # T.C.=O(E*logV), S.C.=O(V^2)
    # may not work with -ive edge weights
    # definitely not work when there is a -ive weight cycle
    # based on Greedy approach
    */
};
