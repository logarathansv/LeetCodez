class Solution {
public:
    bool dist(int mini, vector<int>& pos, int m){
        int ct=1;
        int prev = pos[0];

        for(int i=1;i<pos.size() && ct < m;i++){
            int curr = pos[i];
            if(curr - prev >= mini){
                ct++;
                prev = curr;
            }
        }

        return ct == m;
    }
    int maxDistance(vector<int>& position, int m) {
        int ans = 0;
        sort(position.begin(), position.end());
        int l = 1, h = ceil(position[position.size() - 1] / (m - 1.0));

        while(l <= h){
            int mid = (l+h)/2;

            if(dist(mid, position, m)) {ans = mid;l = mid+1;}
            else h = mid - 1;
        }

        return ans;
    }
};