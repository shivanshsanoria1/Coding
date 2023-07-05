class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) { //T.C.=O(n) , S.C.=O(n)
        vector<int> ans(2);
        int n=nums.size();
        unordered_map<int,bool> mp;
        int sum=0, sum_real=(n*(n+1))/2;
        for(int i=0; i<n; i++)
        {
            if(mp.find(nums[i]) != mp.end()) //nums[i] present in map
                ans[0]=nums[i]; //found duplicate
            else
                mp[nums[i]]=true;
            sum+=nums[i];
        }
        ans[1]=ans[0]+sum_real-sum;
        return ans;
    }
};