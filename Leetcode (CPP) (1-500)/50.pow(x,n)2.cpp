class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) // n is 0
            return 1;
        if(n>0) // n is +ive
            return solve(x,n);
        long int n2=n; // to prevent edge case while converting from -ive to +ive
        return 1/solve(x,-n2); // n is -ivw
    }
    
    double solve(double x, long int n)
    {
        if(n==0) // base case
            return 1;
        double temp=solve(x,n/2);
        if(n%2==0) // n is even
            return temp*temp;
        else // n is odd
            return temp*temp*x;
    }
};