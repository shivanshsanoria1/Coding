class Solution {
public:
    int lis(vector<int>& nums, vector<vector<int>>& dp, int prevIdx, int i){
        if(i >= nums.size())
            return 0;
        if(dp[i][prevIdx + 1] != -1)
            return dp[i][prevIdx + 1];
        int include = (prevIdx == -1 || nums[i] > nums[prevIdx]) ? 1 + lis(nums, dp, i, i+1) : 0;
        int exclude = lis(nums, dp, prevIdx, i+1);
        dp[i][prevIdx + 1] = max(include, exclude);
        return dp[i][prevIdx + 1]; 
    }

    int lengthOfLIS(vector<int>& nums) { // Memoization, T.C.=O(n^2), S.C.=O(n^2)
        int n=nums.size();
        // dp of size n*(n+1) filled with -1's
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return lis(nums, dp, -1, 0);
    }
};