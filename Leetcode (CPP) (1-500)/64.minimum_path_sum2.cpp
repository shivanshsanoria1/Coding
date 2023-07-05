class Solution {
public:
    int solve(vector<vector<int>>& grid, int m, int n, int i, int j, vector<vector<int>>& dp)
    {
        if(i>=m || j>=n) //index out of bounds
            return INT_MAX;
        if(i==m-1 && j==n-1) //last element in dp
        {
            dp[i][j] = grid[i][j];
            return dp[i][j];
        }
        if(dp[i][j] != -1) //solution already exists in dp
            return dp[i][j];
        int down = solve(grid,m,n,i+1,j,dp); //down
        int right = solve(grid,m,n,i,j+1,dp); //right
        dp[i][j] = grid[i][j] + min(down,right);
        return dp[i][j];
    }
    
    int minPathSum(vector<vector<int>>& grid) { //DFS + memoization
        int m= grid.size(), n=grid[0].size();
        vector<vector<int>> dp(m, vector<int> (n,-1)); //m*n dp filled with -1's
        return solve(grid,m,n,0,0,dp);
    }
};