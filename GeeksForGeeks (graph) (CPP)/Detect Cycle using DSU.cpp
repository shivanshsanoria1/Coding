class DisjointSet
{
private:
    vector<int> parent, size;
    
public:
    DisjointSet(int V){
        parent.resize(V);
        size.resize(V, 1);
        for(int i=0; i<V; i++)
            parent[i] = i;
    }
    
    int findUltParent(int curr){ // find ultimate parent
        if(curr == parent[curr])
            return curr;
        parent[curr] = findUltParent(parent[curr]);
        return parent[curr];
    }
    
    void unionBySize(int a, int b) 
    {
        //code here
        int ultPar_a = findUltParent(a);
        int ultPar_b = findUltParent(b);
        if(ultPar_a == ultPar_b)
            return;
        if(size[ultPar_a] <= size[ultPar_b])
        {
            parent[ultPar_a] = ultPar_b;
            size[ultPar_b] += size[ultPar_a];
        }
        else // size[ultPar_a] > size[ultPar_b]
        {
            parent[ultPar_b] = ultPar_a;
            size[ultPar_a] += size[ultPar_b];
        }
    }
};

class Solution
{
public:
    //Function to detect cycle using DSU in an undirected graph.
	int detectCycle(int V, vector<int>adj[])
	{
	    // Code here
	    DisjointSet ds = DisjointSet(V);
	    for(int a=0; a<V; a++)
	        for(int b: adj[a])
	        {
	            if(a >= b) // skip the double edges
	                continue;
	            if(ds.findUltParent(a) == ds.findUltParent(b))
                    return 1;
                ds.unionBySize(a, b);
	        }
	    return 0;
	}
};