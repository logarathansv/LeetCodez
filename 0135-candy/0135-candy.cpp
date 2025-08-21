class Solution {
public:
    int candy(vector<int>& ratings) {
        int i = 1, n = ratings.size(), ct = n;

        while(i < n){
            if(ratings[i] == ratings[i-1]){
                i++; continue;
            }
            int peak = 0;
            while(i < n && ratings[i-1] < ratings[i]){
                peak++;ct += peak; 
                i++;
            }

            int down = 0;
            while(i < n && ratings[i-1] > ratings[i]){
                down++;ct += down; 
                i++;
            }

            ct -= min(down, peak);
        }

        return ct;
    }
};