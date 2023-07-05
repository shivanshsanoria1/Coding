class Solution {
public:
    int totalMoney(int n) {
        int row=n/7, col=n%7; //row:num of completely filled rows ; col:col of the last element
        int rows_sum= 28*row + 7*((row-1)*row)/2; //sum of completely filled rows
        int last_row_sum= (row+1)*col + ((col-1)*col)/2; //sum of the last row
        return rows_sum + last_row_sum;
    }
};