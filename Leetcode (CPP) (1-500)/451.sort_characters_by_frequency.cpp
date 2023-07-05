class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        priority_queue<pair<int,char>> pq;
        string ans="";
        for(int i=0; i<s.length(); i++)
            mp[s[i]]++;
        for(auto it:mp)
            pq.push({it.second,it.first});
        while(!pq.empty())
        {
            pair<int,char> curr=pq.top();
            pq.pop();
            int freq=curr.first;
            while(freq)
            {
                ans += curr.second;
                freq--;
            }
        }
        return ans;
    }
};