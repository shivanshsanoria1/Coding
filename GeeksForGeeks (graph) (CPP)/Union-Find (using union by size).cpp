class Solution
{
private:
    int findUltParent(int parent[], int curr){ // find ultimate parent
        if(curr == parent[curr])
            return curr;
        parent[curr] = findUltParent(parent, parent[curr]);
        return parent[curr];
    }

public:
    //Function to merge two nodes a and b.
    void union_(int a, int b, int parent[], int size[]) 
    {
        //code here
        int ultPar_a = findUltParent(parent, a);
        int ultPar_b = findUltParent(parent, b);
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
    
    //Function to check whether 2 nodes are connected or not.
    bool isConnected(int a, int b, int parent[], int size[])
    {
        //code here
        return findUltParent(parent, a) == findUltParent(parent, b);
    }
};