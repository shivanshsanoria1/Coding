class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size(), max, ans;
        vector<int> lis(n); // stores the longest increasing subarray starting from ith index
        for(int i=n-1; i>=0; i--)
        {
            max=1;
            for(int j=i+1; j<n; j++)
            {
                if(nums[j] > nums[i])
                {
                    if(1+lis[j] > max)
                        max=1+lis[j];
                }
            }
            lis[i]=max;
        }
        ans=lis[0];
        for(int i=1; i<n; i++)
            if(lis[i] > ans)
                ans=lis[i];
        return ans;
    }
};