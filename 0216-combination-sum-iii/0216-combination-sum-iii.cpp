class Solution {
public:
    vector<vector<int>> ans;
    vector<int> lev;

    void findcombisum(int ind, int ct, int sum, int k){
        if(ct == k && sum == 0) {ans.push_back(lev);return;}
        else if(ct > k || ind > 9) return;

        lev.push_back(ind);
        findcombisum(ind+1, ct+1, sum - ind, k);
        lev.pop_back();

        findcombisum(ind+1, ct, sum, k);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        findcombisum(1, 0, n, k);

        return ans;
    }
};