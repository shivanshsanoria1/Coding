class Solution {
public:
    int numDecodings(string s) {
        int n=s.length();
        if(n==0 || s[0]=='0')
            return 0;
        else if(n==1)
            return 1;
        int d,dd;
        int c,c1=1,c2=1; // c1: count upto current (digit-1), c2: count upto current (digit-2)
        for(int i=1; i<n; i++)
        {
            d = s[i]-'0'; // current digit is taken as single digit
            dd = (s[i-1]-'0')*10 + d; // current digit and previous digit is taken as double digit
            c=0;
            if(d>0)
                c=c+c1;
            if(dd>=10 && dd<=26)
                c=c+c2;
            c2=c1;
            c1=c;
        }
        return c1;
    }
};