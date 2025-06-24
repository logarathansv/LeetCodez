class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        unordered_set<int> st;

        vector<int> ans;
        int r = 0;

        for(int i=0;i<nums.size();i++){
            if(nums[i] == key){
                int num = i;
                int l = max(r, num-k);
                r = min((int)num+k, (int)nums.size()-1) + 1;
                for(int j=l;j<r;j++){
                    ans.push_back(j);
                }
            }
        }

        return ans;
    }
};