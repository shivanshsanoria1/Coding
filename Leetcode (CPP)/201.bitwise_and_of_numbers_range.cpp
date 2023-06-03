class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int c=0;
        while(left != right) //keep on right shifting left and right until they become equal
        {
            left=left>>1;
            right=right>>1;
            c++;
        }
        //now left==right
        return left<<c;
    }
};