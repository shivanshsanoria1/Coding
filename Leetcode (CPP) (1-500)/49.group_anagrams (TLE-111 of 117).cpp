class Solution {
public:
    bool checkAnagram(string s1, string s2)
    {
        int n1=s1.length(), n2=s2.length();
        if(n1!=n2)
            return false;
        vector<int> count(26,0); //vector of size 26 initialized with all 0's
        for(int i=0; i<n1; i++)
        {
            count[s1[i]-'a']++; //increment the count of corresponding letter of string s1 in count[] 
            count[s2[i]-'a']--; //decrement the count of corresponding letter of string s2 in count[] 
        }
        for(int i=0; i<26; i++) //check if count[] consists of all 0's
            if(count[i]!=0)
                return false;
        return true;
    }
    
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        vector<vector<string>> ans;
        vector<bool> check(n,false); //to check if the string is included in ans. or not
        for(int i=0; i<n; i++)
        {
            if(check[i]==true) //string already included in ans.
                continue;
            vector<string> anag;
            for(int j=i; j<n; j++)
            {
                if(checkAnagram(strs[i],strs[j]))
                {
                    anag.push_back(strs[j]);
                    check[j]=true;
                }
            }
            if(!anag.empty()) //only push the anagram vector if it is non empty
                ans.push_back(anag);
        }
        return ans;
    }
};