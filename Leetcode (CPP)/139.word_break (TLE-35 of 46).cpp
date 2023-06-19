class Solution {
public:
    bool solve(unordered_set<string>& dict, string& s, int idx){
        if(idx == s.length())
            return true;
        for(string word: dict)
            if(s.substr(idx, word.length()) == word && solve(dict, s, idx + word.length()))
                return true;
        return false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        return solve(dict, s, 0);
    }
};