class Solution {
public:
    int trailingZeroes(int n) { //Math soln.
        return n/5 + n/25 + n/125 + n/625 + n/3125;
    }
};
//here max value of n is 10^4
//since 5^5 < 10^4 < 5^6
//max power of 5 needed is 5
//5^5 = 3125