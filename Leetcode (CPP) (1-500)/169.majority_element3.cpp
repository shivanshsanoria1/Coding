class Solution {
public:
    int majorityElement(vector<int>& nums) { // MOORE'S VOTING algo., T.C.=O(n), S.C.=O(1)
        int count = 1;
        int majority = nums[0]; // assume 1st element as majority element
        for(int num: nums)
        {
            if(num == majority) // curr element is majority element
                count++;
            else
                count--;
            if(count == 0)
            {
                majority = num; // set curr element as majority element
                count++;
            }
        }
        return majority;
    }
};