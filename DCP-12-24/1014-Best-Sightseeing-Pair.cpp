class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int maxprev = values[0];
        int maxi = INT_MIN;
        for(int i=1;i<values.size();i++){
            maxi = max(maxi, maxprev + (values[i]-i));
            maxprev = max(maxprev, values[i]+i);
        }

        return maxi;
    }
};