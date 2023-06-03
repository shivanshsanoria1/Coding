class Solution {
public:
    int countOdds(int low, int high) {
        int diff=high-low;
        if(low%2==0 && high%2==0) //both are even
            return diff/2;
        if(low%2!=0 && high%2!=0) //both are odd
            return (diff/2)+1;
        return (diff+1)/2; //one is even and other is odd
    }
};