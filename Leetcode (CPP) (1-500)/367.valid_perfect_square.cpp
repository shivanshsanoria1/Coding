class Solution {
public:
    bool isPerfectSquare(int num) {
        long int i=1;
        while(i*i < num)
            i++;
        if(i*i==num)
            return true;
        return false;
    }
};