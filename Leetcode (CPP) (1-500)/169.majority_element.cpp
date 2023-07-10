class Solution {
public:
    int majorityElement(vector<int>& nums) { // T.C.=O(n), S.C.=O(n)
        unordered_map<int, int> mp; // num -> freq
        int ans = -1;
        for(int num: nums)
        {
            mp[num]++;
            if(mp[num] > nums.size()/2)
            {
                ans = num;
                break;
            }
        }
        return ans;
    }
};