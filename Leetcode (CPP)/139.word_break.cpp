class Solution {
public:
    bool solve(unordered_set<string>& dict, vector<int>& dp, string& s, int i){
        if(i == s.length())
            return true;
        if(dp[i] != -1) // solution already exists in dp
            return dp[i];
        for(string word: dict)
            // check if the substring starting at index i and of the same length as 'word' matches with 'word'
            // if yes, move to the next recursive call starting at index i + word.length()
            if(s.substr(i, word.length()) == word && solve(dict, dp, s, i + word.length()))
            {
                dp[i] = 1; // store true in dp
                return dp[i];
            }
        dp[i] = 0; // store false in dp
        return dp[i];
    }

    bool wordBreak(string s, vector<string>& wordDict) { // Memoization
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<int> dp(s.length(), -1);
        return solve(dict, dp, s, 0);
    }
};