class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> d(nums.size()+1, 0);
        for(int i=0;i<queries.size();i++){
            d[queries[i][0]] ++;
            d[queries[i][1]+1] --;

        }
        for(int i=1;i<d.size();i++){
            d[i] += d[i-1];

        }
        for(int i=0;i<nums.size();i++){
            if(nums[i] > d[i]) return false;
        }
        return true;
    }
};