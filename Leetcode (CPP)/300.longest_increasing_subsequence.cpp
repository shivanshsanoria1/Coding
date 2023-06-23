class Solution {
public:
    int lengthOfLIS(vector<int>& nums) { // DP, T.C.=O(n^2), S.C.=O(n)
        int n=nums.size();
        // stores the longest increasing subarray starting from ith index
        vector<int> lis(n, 1); 
        int ans = lis[n-1];
        for(int i=n-2; i>=0; i--)
        {
            for(int j=i+1; j<n; j++)
                if(nums[i] < nums[j])
                    lis[i] = max(lis[i], 1 + lis[j]);
            ans = max(ans, lis[i]);
        }
        return ans;
    }
};