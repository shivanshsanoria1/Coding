class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) { //DP
        int m= grid.size(), n=grid[0].size();
        vector<vector<int>> dp(m+1, vector<int> (n+1,INT_MAX)); //(m+1)*(n+1) dp filled with INT_MAX's
        for(int i=1; i<m+1; i++)
            for(int j=1; j<n+1; j++)
            {
                if(dp[i-1][j]==INT_MAX && dp[i][j-1]==INT_MAX)
                    dp[i][j] = grid[i-1][j-1];
                else
                    dp[i][j] = grid[i-1][j-1] + min(dp[i-1][j],dp[i][j-1]);
            }
        return dp[m][n]; //return the last element in dp
    }
};
// dp[i][j] is mapped with grid[i-1][j-1]
