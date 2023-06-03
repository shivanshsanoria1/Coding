class Solution {
public:
    string convertToTitle(int columnNumber) {
        string ans;
        while(columnNumber > 0) //rem in range [0,25] matches with char [A,Z]
        {
            columnNumber--;
            int rem= columnNumber%26;
            ans+= (char)(65+rem);
            columnNumber/=26;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};