class Solution {
public:
    void solve(vector<vector<int>>& grid, int m, int n, int i, int j, int sum, vector<vector<int>>& dp)
    {
        if(i>=m || j>=n) //index out of bounds
            return;
        sum += grid[i][j];
        if(sum < dp[i][j]) //curr sum < sum stored in dp[i][j]
            dp[i][j]= sum; //update the sum stored in dp[i][j]
        else //no need to go in next recursive call
            return;
        solve(grid,m,n,i+1,j,sum,dp); //down
        solve(grid,m,n,i,j+1,sum,dp); //right
    }
    
    int minPathSum(vector<vector<int>>& grid) { //DFS + memoization
        int m= grid.size(), n=grid[0].size();
        vector<vector<int>> dp(m, vector<int> (n,INT_MAX)); //m*n dp filled with INT_MAX's
        solve(grid,m,n,0,0,0,dp);
        return dp[m-1][n-1]; //return the last element in dp
    }
};