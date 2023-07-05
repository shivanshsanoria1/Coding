class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result(numRows);
        for(int i=0; i<numRows; i++)
        {
            result[i].resize(i+1); // give size of column
            result[i][0]=1; // first element of each row is 1
            result[i][i]=1; // last element of each row is 1
            for(int j=1; j<=i-1; j++)
                result[i][j]=result[i-1][j]+result[i-1][j-1];
        }
        return result;
    }
};