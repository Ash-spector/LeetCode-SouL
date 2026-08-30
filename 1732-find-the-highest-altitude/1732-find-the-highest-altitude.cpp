class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int alt = 0;
        int maxalt = 0;
        for (int i = 0; i<gain.size(); i++)
        {
            alt = alt + gain[i];
            maxalt = max(maxalt, alt);
        }
        return maxalt;
    }
};