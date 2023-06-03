class Solution {
public:
    vector<vector<int>> res;
    int n;
    vector<vector<int>> subsets(vector<int>& nums) {
        n=nums.size();
        vector<int> subset;
        solve(nums,0,subset);
        return res;
    }
    
    void solve(vector<int>& nums, int i, vector<int> subset)
    {
        if(i==n)
        {
            res.push_back(subset);
            return;
        }
        solve(nums,i+1,subset); // not including nums[i] in subset
        subset.push_back(nums[i]);
        solve(nums,i+1,subset); // including nums[i] in subset
    }
};