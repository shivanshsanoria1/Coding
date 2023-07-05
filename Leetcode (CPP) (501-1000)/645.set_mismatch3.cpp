class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) { //T.C.=O(n) , S.C.=O(n)
        vector<int> ans(2);
        int n=nums.size();
        vector<bool> vec(n+1,false); //to keep track of numbers visited in array nums
        int sum=0, sum_real=(n*(n+1))/2;
        for(int i=0; i<n; i++)
        {
            if(vec[nums[i]]==true) //found duplicate
                ans[0]=nums[i];
            else
                vec[nums[i]]=true;
            sum+=nums[i];
        }
        ans[1]=ans[0]+sum_real-sum;
        return ans;
    }
};