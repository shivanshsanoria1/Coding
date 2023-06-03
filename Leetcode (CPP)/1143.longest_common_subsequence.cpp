class Solution {
public:
    int lcs(string& s1, string& s2, vector<vector<int>>& dp, int i, int j)
    {
        if(i==s1.length() || j==s2.length()) //for any string index is out of bounds
            return 0;
        if(dp[i][j] != -1) //solution already exists in dp
            return dp[i][j];
        if(s1[i] == s2[j]) //ith char of s1 matches with jth char of s2
        {
            dp[i][j] = 1 + lcs(s1,s2,dp,i+1,j+1);;
            return dp[i][j];
        }
        int a = lcs(s1,s2,dp,i+1,j); //move forward in s1
        int b = lcs(s1,s2,dp,i,j+1); //move forward in s2
        dp[i][j] = max(a,b);
        return dp[i][j];
    }
    
    int longestCommonSubsequence(string s1, string s2) { //T.C.=O(n1*n2) , S.C.=O(n1*n2) ; memoization
        int n1= s1.length(), n2= s2.length();
        vector<vector<int>> dp(n1, vector<int> (n2,-1)); //dp of n1*n2 filled with -1's
        return lcs(s1,s2,dp,0,0);
    }
};