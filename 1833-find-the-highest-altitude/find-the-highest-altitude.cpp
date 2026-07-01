class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ini = 0;
        int maxheight = 0;
        for(int i=0; i<gain.size(); i++){
            ini += gain[i];
            maxheight = max(maxheight, ini);
        }
        return maxheight;
    }
};