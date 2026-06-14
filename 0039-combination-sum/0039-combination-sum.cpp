class Solution {
public:
    void findcombo(int ind, int sum, int target, vector<vector<int>>& ans, vector<int>& result, vector<int>& candidates){
        if(sum == 0){
            ans.push_back(result);
            return ;
        }
        else if(sum < 0 || ind > candidates.size()-1){
            return ;
        }
        result.push_back(candidates[ind]);
        findcombo(ind, sum-candidates[ind], target, ans, result, candidates);
        result.pop_back();
        findcombo(ind+1, sum, target, ans, result, candidates);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> result;
        vector<vector<int>> ans;
        findcombo(0, target, target, ans, result, candidates);
        return ans;
    }
};