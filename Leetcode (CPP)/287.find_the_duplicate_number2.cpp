class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int index;
        for(int i=0; i<nums.size(); i++)
        {
            // find index corresponding to each element, duplicate elements will have same index values
            index = abs(nums[i]);
            // -ive means that element is visited once, +ive means that element is visited twice
            nums[index] *= -1;
            if(nums[index]>0) // nums[index] is visited twice
                return abs(nums[i]); // so return the element corresponding to that index
        }
        return -1;
    }
};