class Solution {
public:
    int trailingZeroes(int n) { //Math soln.
        if(n < 5) //no zeros for n! less than 5
            return 0;
        int ans=0, x=5, i=1;
        while(i<=5) //given max value of n=10^4 so max value of i is 5 (since 5^5 < 10^4 < 5^6)
        {
            ans += n/x; //formula to calculate trailing zeros in n!
            x=x*5;
            i++;
        }
        return ans;
    }
};