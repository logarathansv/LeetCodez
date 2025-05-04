class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<string, int> mp;

        for(auto domino : dominoes){
            mp[to_string(min(domino[0], domino[1])) + "+" + to_string(max(domino[0], domino[1]))]++;
        }

        int maxi = 0, res = 0;
        for(auto ele:mp){
            if(ele.second > 1){
                int ans = 1;
                maxi = ele.second;
                ans *= (maxi * (maxi-1))/2;
                res += ans;
            }
        }

        return res;
    }
};