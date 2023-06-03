class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int count[n+1];
        for(int i=0; i<n+1; i++)
            count[i]=0;
        for(int i=0; i<n; i++)
            count[nums[i]]++;
        for(int i=0; i<n+1; i++)
            if(count[i]==0)
                return i;
        return -1;
    }
};