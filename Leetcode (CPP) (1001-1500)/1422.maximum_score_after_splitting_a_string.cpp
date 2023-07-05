class Solution {
public:
    int maxScore(string s) {
        int n=s.length(), ones=0;
        for(int i=0; i<n; i++)
            if(s[i]=='1')
                ones++;
        int left_zeros=0, right_ones=ones, ans=INT_MIN;
        for(int i=0; i<n-1; i++)
        {
            if(s[i]=='0')
                left_zeros++;
            else
                right_ones--;
            ans=max(ans,left_zeros+right_ones);
        }
        return ans;
    }
};