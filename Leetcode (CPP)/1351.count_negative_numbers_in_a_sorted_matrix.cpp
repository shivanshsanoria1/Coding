class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) { //T.C.=O(m+n)
        int m=grid.size(), n=grid[0].size(), count=0;
        int row=0, col=n-1; //start at first row and last col
        while(row<m && col>=0)
        {
            if(grid[row][col]<0)
            {
                count+=(m-row);
                col--;
            }
            else
                row++;
        }
        return count;
    }
};