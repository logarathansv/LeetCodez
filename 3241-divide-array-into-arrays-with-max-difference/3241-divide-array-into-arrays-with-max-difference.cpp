class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> res;

        for(int i=0;i<nums.size();i++){
            if(i != 0 && i % 3 == 0){
                if(res[2] - res[0] > k) return {};
                ans.push_back(res);
                res.clear();
            }
            res.push_back(nums[i]); 
        }
        if(res[2] - res[0] > k) return {};
        ans.push_back(res);

        return ans;
    }
};