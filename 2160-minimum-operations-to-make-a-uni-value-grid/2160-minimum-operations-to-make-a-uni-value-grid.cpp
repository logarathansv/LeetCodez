class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> pts;
        for(auto item:grid){
            for(auto ele:item){
                pts.push_back(ele);
            }
        }
        sort(pts.begin(), pts.end());
        int ele = pts[pts.size()/2];
        int ct = 0;
        for(int i=0;i<pts.size();i++){
            if(i == pts.size()/2) continue;
            int maxi = max(ele, pts[i]);
            int mini = min(ele, pts[i]);

            if((maxi-mini)%x) return -1;
            ct += (maxi-mini)/x;
        }
        return ct;
    }
};