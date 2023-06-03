class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) { // T.C.=O(n) , S.C.=O(1)
        int n=nums.size(), start=0, end=n-1, temp;
        while(start<end)
        {
            if(nums[start]%2!=0) // nums[start] is odd
            {
                temp=nums[start];
                nums[start]=nums[end];
                nums[end]=temp;
                end--;
            }
            else // nums[start] is even
                start++;
        }
        return nums;
    }
};