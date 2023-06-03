class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) { //T.C.=O(n) , S.C.=O(n) , double pass
        int ans=0;
        unordered_map<int,int> mp; //num -> freq
        for(int i=0; i<nums.size(); i++)
            mp[nums[i]]++;
        for(auto it: mp)
        {
            int freq= it.second; //for a num with frequency 'freq', number of good pairs is the sum
            ans+= ((freq-1)*freq)/2; //1+2+3+...+(freq-1)= ((freq-1)*freq)/2
        }
        return ans;
    }
};