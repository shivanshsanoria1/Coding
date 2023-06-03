class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) { //T.C.=O(nlogn) , S.C.=O(1)
        vector<int> ans(2);
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int sum=nums[0], sum_real=(n*(n+1))/2;
        for(int i=1; i<n; i++)
        {
            if(nums[i]==nums[i-1]) //found duplicate
                ans[0]=nums[i];
            sum+=nums[i];
        }
        ans[1]=ans[0]+sum_real-sum;
        return ans;
    }
};