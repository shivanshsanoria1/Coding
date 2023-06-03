class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int max_height=0, height=0;
        for(int i=0; i<gain.size(); i++)
        {
            height+=gain[i];
            max_height= max(max_height,height);
        }
        return max_height;
    }
};