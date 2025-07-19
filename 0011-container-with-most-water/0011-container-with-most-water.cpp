class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size()-1;
        int p = 0;

        while(l < r){
            p = max((r-l) * min(height[l], height[r]), p);
            if(height[l] < height[r]){
                l++;
            }
            else {
                r--;
            }
        }

        return p;
    }
};