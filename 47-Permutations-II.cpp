class Solution {
public:
    void findpermutation(vector<int>& combo, vector<vector<int>>& answer, unordered_map<int, int>& arrct, int n){
        if(combo.size() == n){
            answer.push_back(combo);
            return ;
        }
        for(auto& ct:arrct){
            int num = ct.first;
            int count = ct.second;
            if(count == 0) continue;
            combo.push_back(num);
            arrct[num]--;
            
            findpermutation(combo, answer, arrct, n);

            combo.pop_back();
            arrct[num]++;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> combo;
        vector<vector<int>> answer;
        unordered_map<int, int> arrct;

        for(auto num:nums) arrct[num]++;

        findpermutation(combo, answer, arrct, nums.size());

        return answer;
    }
};