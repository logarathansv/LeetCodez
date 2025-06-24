class Solution {
public:
    int maxDepth(string s) {
        int maxi = 0, ct = 0;

        for(auto ch:s) {
            if(ch == '(') ct++;
            else if(ch ==')') ct--;

            maxi = max(ct, maxi);
        }

        return maxi;
    }
};