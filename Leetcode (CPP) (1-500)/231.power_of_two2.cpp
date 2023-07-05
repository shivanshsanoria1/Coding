class Solution {
public:
    bool isPowerOfTwo(int n) {
        int x=1;
        if(n>0)
        {
            for(int i=0; i<32-1; i++)
            {
                if(n == x)
                    return true;
                x = x << 1;
            }
        }
        return false;
    }
};