class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> pr;

        for(int i=0;i<position.size();i++) pr.push_back({position[i], speed[i]});

        sort(pr.rbegin(), pr.rend());

        int ans = 0;
        double curr = 0, dest;
        for(int i=0;i<pr.size();i++){
            dest = (double)(target-pr[i].first)/pr[i].second;
            if(curr < dest) {
                ans++;
                curr= dest;
            }
        }

        return ans;
    }
};