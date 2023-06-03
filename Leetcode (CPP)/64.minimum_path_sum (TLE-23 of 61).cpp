class Solution {
public:
    int ans=INT_MAX;
    void solve(vector<vector<int>>& grid, int m, int n, int i, int j, int sum)
    {
        if(i>=m || j>=n) //index out of bounds
            return;
        sum += grid[i][j];
        if(i==m-1 && j==n-1) //reached the last elemnt in grid
            ans= min(ans,sum);
        solve(grid,m,n,i+1,j,sum); //down
        solve(grid,m,n,i,j+1,sum); //right
    }
    
    int minPathSum(vector<vector<int>>& grid) { //DFS
        int m= grid.size(), n=grid[0].size();
        solve(grid,m,n,0,0,0);
        return ans;
    }
};