class Solution {
public:
    int Dist(int a1, int b1, int a2, int b2) //returns square of the distance between the points (a1,b1) and (a2,b2)
    {
        return (a1-a2)*(a1-a2) + (b1-b2)*(b1-b2);
    }
    
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        int x1=p1[0], y1=p1[1]; //point A (x1,y1)
        int x2=p2[0], y2=p2[1]; //point B (x2,y2)
        int x3=p3[0], y3=p3[1]; //point C (x3,y3)
        int x4=p4[0], y4=p4[1]; //point D (x4,y4)
        int ab=Dist(x1,y1,x2,y2); //square of side AB
        int bc=Dist(x2,y2,x3,y3); //square of side BC
        int cd=Dist(x3,y3,x4,y4); //square of side CD
        int da=Dist(x4,y4,x1,y1); //square of side DA
        int ac=Dist(x1,y1,x3,y3); //square of side AC
        int bd=Dist(x2,y2,x4,y4); //square of side BD
        if(ab==0 || bc==0 || cd==0 || da==0 || ac==0 || bd==0) //if any 2 points coincide then square is not poosible
            return false;
        unordered_set<int> s({ab,bc,cd,da,ac,bd}); //add all possible sides to set
        if(s.size()==2) //only 2 different lengths are possible in square ,ie, side and diagonal
            return true;
        return false;
    }
};