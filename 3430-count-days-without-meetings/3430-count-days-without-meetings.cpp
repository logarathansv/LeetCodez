class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        vector<vector<int>> ans;

        for(int i=0;i<meetings.size();i++){
            if(ans.empty() || ans.back()[1] < meetings[i][0]){
                ans.push_back(meetings[i]);
            }
            else{
                ans.back()[1] = max(meetings[i][1], ans.back()[1]);
            }
        }
        int res = 0;
        for(int i=0;i<ans.size();i++){
            res += (ans[i][1] - ans[i][0] + 1);
        }
        return days-res;
    }
};