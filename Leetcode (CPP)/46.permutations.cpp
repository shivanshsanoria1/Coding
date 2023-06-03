class Solution {
public:
    void solve(vector<int>& nums, int left, int right, vector<vector<int>>& ans)
    {
        if(left == right)
        {
            ans.push_back(nums);
            return;
        }
        for(int i=left; i<=right; i++)
        {
            swap(nums[left],nums[i]);
            solve(nums,left+1,right,ans);
            swap(nums[left],nums[i]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int n=nums.size();
        solve(nums,0,n-1,ans); //initially left=0, right= n-1
        return ans;
    }
};