class Solution {
public:
    long long solve(int ind, vector<vector<int>>& questions, vector<long long> &memo){
        if(ind >= questions.size()) {
            return 0;
        }
        if(memo[ind] != -1){
            return memo[ind];
        }

        memo[ind] = max(solve(ind + 1, questions, memo),
                        questions[ind][0] + solve(ind + questions[ind][1] + 1, questions, memo));

        return memo[ind];
    }
    long long mostPoints(vector<vector<int>>& questions) {
        vector<long long> memo(questions.size(), -1);
        return solve(0, questions, memo);
    }
};