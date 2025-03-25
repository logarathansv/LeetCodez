class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<vector<int>> x;
        vector<vector<int>> y;

        for(auto rect : rectangles){
            x.push_back({rect[0], rect[2]});
            y.push_back({rect[1], rect[3]});
        }

        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        
        vector<vector<int>> xm;
        vector<vector<int>> ym;

        for(int i=0;i<x.size();i++){
            if(xm.empty() || xm.back()[1] <= x[i][0]){
                xm.push_back(x[i]);
            }
            else{
                xm.back()[1] = max(xm.back()[1], x[i][1]);
            }
            if(xm.size() > 2) return true;
        }
        cout<<xm.size();
        if(xm.size() > 2) return true;
        for(int i=0;i<y.size();i++){
            if(ym.empty() || ym.back()[1] <= y[i][0]){
                ym.push_back(y[i]);
            }
            else{
                ym.back()[1] = max(ym.back()[1], y[i][1]);
            }
            if(ym.size() > 2) return true;
        }
        cout<<ym.size();
        if(ym.size() > 2) return true;
        return false;
    }
};