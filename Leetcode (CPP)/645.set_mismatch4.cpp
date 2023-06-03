class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) { //T.C.=O(n) , S.C.=O(1)
        vector<int> ans(2);
        int n=nums.size();
        int sum=0, sum_real=(n*(n+1))/2, index;
        for(int i=0; i<n; i++)
        {
            sum+=abs(nums[i]);
            index=abs(nums[i]); // find index corresponding to each element, duplicate elements will have same index values
            nums[index-1] *= -1; // -ive means that element is visited once, +ive means that element is visited twice
            if(nums[index-1] > 0) //dupliacte found
                ans[0]=abs(nums[i]);
        }
        ans[1]=ans[0]+sum_real-sum;
        return ans;
    }
};