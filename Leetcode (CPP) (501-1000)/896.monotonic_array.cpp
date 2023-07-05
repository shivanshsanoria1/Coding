class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return true;
        bool inc=false, dec=false;
        for(int i=1; i<n; i++)
        {
            if(nums[i]-nums[i-1] > 0)
                inc=true;
            else if(nums[i]-nums[i-1] < 0)
                dec=true;
            if(inc==true && dec==true) //array should not be monotonically increasing and decreasing
                return false;
        }
        return true;
    }
};