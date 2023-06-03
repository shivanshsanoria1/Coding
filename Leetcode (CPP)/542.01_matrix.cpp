class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) { // T.C= O(m*n) , S.C.=O(1)
        int m=mat.size(), n=mat[0].size(), max_dist=m*n;
        vector<vector<int>> dist(m,vector<int> (n,max_dist)); // dist is a m*n vector with each element as max_dist
        // check for left and top neighbours
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(mat[i][j]==0)
                    dist[i][j]=0;
                else
                {
                    if(i>0) // min. of current distance and distance from left neighbour +1
                        dist[i][j] = min(dist[i][j],dist[i-1][j]+1);
                    if(j>0) // min. of current distance and distance from top neighbour +1
                        dist[i][j] = min(dist[i][j],dist[i][j-1]+1);
                }
            }
        }
        // check for right and bottom neighbours
        for(int i=m-1; i>=0; i--)
        {
            for(int j=n-1; j>=0; j--)
            {
                if(i<m-1) // min. of current distance and distance from right neighbour +1
                    dist[i][j] = min(dist[i][j],dist[i+1][j]+1);
                if(j<n-1) // min. of current distance and distance from bottom neighbour +1
                    dist[i][j] = min(dist[i][j],dist[i][j+1]+1);
            }
        }
        return dist;
    }
};