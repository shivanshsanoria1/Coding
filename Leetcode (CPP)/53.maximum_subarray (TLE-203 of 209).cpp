class Solution {
public:
    int maxSubArray(vector<int>& nums) { //T.C.=O(n^2) , S.C.=O(1)
        int n= nums.size(), max_sum= nums[0];
        for(int i=0; i<n; i++)
        {
            int sum=0;
            for(int j=i; j<n; j++)
            {
                sum += nums[j];
                if(sum > max_sum)
                    max_sum= sum;
            }
        }
        return max_sum;
    }
};