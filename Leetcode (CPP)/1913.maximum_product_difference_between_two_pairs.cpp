class Solution {
public:
    int maxProductDifference(vector<int>& nums) { //T.C.=O(n)
        int max1=INT_MIN, max2=INT_MIN; //largest and 2nd largest
        int min1=INT_MAX, min2=INT_MAX; //smallest and 2nd smallest
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] >= max1) //new max1 found
            {
                max2=max1; //save max1 in max2
                max1=nums[i]; //update max1
            }
            else if(nums[i] > max2) //new max2 found
                max2=nums[i]; //update max2
            
            if(nums[i] <= min1) //new min1 found
            {
                min2=min1; //save min1 in min2
                min1=nums[i]; //update min1
            }
            else if(nums[i] < min2) //new min2 found
                min2=nums[i]; //update min2
        }
        return max1*max2-min1*min2;
    }
};