class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m=mat.size(), n=mat[0].size();
        vector<int> rows, cols; //stores row and col sums
        for(int i=0; i<m; i++) //find row sum
        {
            int row_sum=0;
            for(int j=0; j<n; j++)
                row_sum+=mat[i][j];
            rows.push_back(row_sum);
        }
        for(int j=0; j<n; j++) //find col sum
        {
            int col_sum=0;
            for(int i=0; i<m; i++)
                col_sum+=mat[i][j];
            cols.push_back(col_sum);
        }
        int c=0;
        for(int i=0; i<m; i++)
            if(rows[i]==1)
                for(int j=0; j<n; j++)
                    if(mat[i][j]==1 && cols[j]==1)
                    {
                        c++;
                        break;
                    }
        return c;
    }
};