class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) { //T.C.=O(n) , S.C.=O(n) , single pass
        int ans=0;
        unordered_map<int,int> mp; //stores the freq of each num of the input array
        for(int i=0; i<nums.size(); i++)
        {
            if(mp.find(nums[i]) != mp.end()) //curr element found in map
                ans += mp[nums[i]]; //add the prev freq of curr element to ans
            mp[nums[i]]++; //update the freq of curr element
        }
        return ans;
    }
};