class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string s1="", s2="";
        for(int i=0; i<word1.size(); i++)
            for(auto it: word1[i])
                s1+=it;
        for(int i=0; i<word2.size(); i++)
            for(auto it: word2[i])
                s2+=it;
        if(s1.length() != s2.length())
            return false;
        for(int i=0; i<s1.length(); i++)
            if(s1[i] != s2[i])
                return false;
        return true;
    }
};