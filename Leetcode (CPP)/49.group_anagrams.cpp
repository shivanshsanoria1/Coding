class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> mp;
        string str="";
        for(int i=0; i<strs.size(); i++)
        {
            str= strs[i];
            sort(str.begin(), str.end());
            mp[str].push_back(strs[i]);
        }
        for(auto it: mp)
            ans.push_back(it.second);
        return ans;
    }
};