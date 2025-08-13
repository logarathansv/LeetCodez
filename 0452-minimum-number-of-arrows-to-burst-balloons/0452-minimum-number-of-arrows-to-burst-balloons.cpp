class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b){
        return a[1]<b[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), cmp);
        int ct = 1;
        int prev = points[0][1]; 
        for(int i=1;i<points.size();i++){
            if(prev < points[i][0]){
                ct++;
                prev = points[i][1];   
            }
        }
        return ct;
    }
};