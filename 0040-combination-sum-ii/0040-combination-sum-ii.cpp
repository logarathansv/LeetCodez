class Solution {
public:
    void findcombo(int ind, int sum, vector<vector<int>> &ans, vector<int> &result, vector<int>& candidates){
        if(sum == 0){
            ans.push_back(result);
            return ;
        }
        if(ind >= candidates.size()) return;
            if(candidates[ind] > sum) return;
            result.push_back(candidates[ind]);
            findcombo(ind+1, sum - candidates[ind], ans, result, candidates);
            while(ind+1 < candidates.size() && candidates[ind] == candidates[ind+1]) ind++;
            result.pop_back();
            findcombo(ind+1, sum , ans, result, candidates);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> result;
        sort(candidates.begin(), candidates.end());
        findcombo(0, target, ans, result, candidates);
        return ans;
    }
};