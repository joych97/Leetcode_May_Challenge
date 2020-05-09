/*
Basic math implementation of straight line just using the formula y2-y1=m(x2-x1). And to be in the same straight line it
has to have the same m throughout.
*/
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& c) {
        double m;
        m=(double)(c[1][1]-c[0][1])/(c[1][0]-c[0][0]);
        for(int j=1;j<c.size()-1;j++){
            double m1=(double)(c[j+1][1]-c[j][1])/(c[j+1][0]-c[j][0]);
            if(m1!=m)
            return false;
        }
        return true;
}
};