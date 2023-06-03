class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) { // Bit manipulation
        int n=nums.size();
        vector<vector<int>> res;
        int i=0, max=pow(2,n);
        while(i<max) // each iteration generates a subset
        {
            vector<int> subset;
            for(int j=0; j<n; j++)
            {
                if(i & 1<<j)
                    subset.push_back(nums[j]);
            }
            res.push_back(subset);
            i++;
        }
        return res;
    }
};