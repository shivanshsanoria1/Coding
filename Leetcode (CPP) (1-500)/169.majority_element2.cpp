class Solution {
public:
    int majorityElement(vector<int>& nums) { // MOORE'S VOTING algo.
        int n=nums.size();
        int c=1; // count
        int majority=nums[0]; // assume first element as majority element
        for(int i=1; i<n; i++)
        {
            if(nums[i]==majority) // current element = majority element
                c++;
            else // current element != majority element
            {
                c--;
                if(c==0) // if count=0
                {
                    majority=nums[i]; // set current element as majority element
                    c++;
                }
            }
        }
        return majority;
    }
};