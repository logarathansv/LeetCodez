class Solution {
public:
    bool canReach(int unit, vector<int>& stones, int res, int ind,
                    unordered_map<int, int>& mp, unordered_map<string, bool> &memo){
        string key = to_string(ind)+to_string(unit);

        if(memo.find(key) != memo.end()) 
            return memo[key];

        int newe = stones[ind] + unit;

        if(newe == res) return true;
        int newi;

        for(int u = unit-1;u<unit+2;u++){
            if(u <= 0) continue;
            if(mp.find(newe) != mp.end()){
                newi = mp[newe];
                if(canReach(u, stones, res, newi, mp, memo))
                    return memo[key] = true;
            }
        }

        return memo[key] = (stones[ind] == res);
    }
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        int last = stones[n-1];

        unordered_map<int, int> mp;
        unordered_map<string, bool> memo;

        for(int i=0;i<n;i++) mp[stones[i]] = i;

        return canReach(0, stones, last, 0, mp, memo);
    }
};