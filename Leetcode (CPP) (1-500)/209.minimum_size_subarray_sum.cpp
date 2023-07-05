class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) { //window sliding technique
        int left=0, right=0;
        int sum=0, min_len=INT_MAX; //curr sum of subarray, min length of valid subarray (subarray whose sum >= target)
        while(right < nums.size())
        {
            sum+=nums[right];
            if(sum >= target) //valid subarray found
                min_len=min(min_len,right-left+1);
            while(sum >= target) //while the subarray is valid increment the left
            {
                sum-=nums[left];
                left++;
                if(sum>=target) //valid subarray found
                    min_len=min(min_len,right-left+1);
            }
            right++;
        }
        return min_len==INT_MAX ? 0 : min_len;
    }
};