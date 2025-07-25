class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int psum = 0, maxi = INT_MIN;

        for(auto g:gain) {maxi=max(psum, maxi);psum += g; }

        return maxi > psum ? maxi : psum;
    }
};