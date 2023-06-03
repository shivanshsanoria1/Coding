class Solution {
public:
    int reverse(int x) {
        int max=INT_MAX/10; // max value for 32 bit int
        int n=x,digit,rev=0;
        do{
            if(abs(rev) > max) // absolute value of rev > max
                return 0;
            digit=n%10;
            rev=(rev*10)+digit;
            n=n/10;
        }while(n!=0);
        return rev;
    }
};