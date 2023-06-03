class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) { //T.C.=O(n) , S.C.=O(n) , single pass
        int ans=0;
        vector<int> vec(101,0); //stores the freq of each num of the input array
        for(int i=0; i<nums.size(); i++)
        {
            ans+= vec[nums[i]]; //add the prev freq of curr element to ans
            vec[nums[i]]++; //update the freq of curr element
        }
        return ans;
    }
};