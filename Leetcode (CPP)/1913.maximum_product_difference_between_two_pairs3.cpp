class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int n=nums.size();
        nth_element(nums.begin(),nums.begin()+1,nums.end()); //index 1 is sorted
        int min_pro=nums[0]*nums[1];
        nth_element(nums.begin(),nums.end()-2,nums.end()); //2nd last index is sorted
        int max_pro=nums[n-1]*nums[n-2];
        return max_pro-min_pro;
    }
};