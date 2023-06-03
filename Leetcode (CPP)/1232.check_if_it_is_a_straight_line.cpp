class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n=coordinates.size();
        if(n==2) //2 points always form a straight line
            return true;
        for(int i=0; i<n-2; i++)
        {
            int x1=coordinates[i][0], y1=coordinates[i][1];     //(x1,y1)
            int x2=coordinates[i+1][0], y2=coordinates[i+1][1]; //(x2,y2)
            int x3=coordinates[i+2][0], y3=coordinates[i+2][1]; //(x3,y3)
            if((y2-y1)*(x3-x2) != (y3-y2)*(x2-x1)) //ith, (i+1)th, (i+2)th points don't form a straight line
                return false;
        }
        return true;
    }
};