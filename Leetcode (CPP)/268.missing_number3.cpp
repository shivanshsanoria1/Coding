class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0; i<n; i++)
            sum=sum + (i+1)-nums[i];
        return sum;
    }
};