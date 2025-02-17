class Solution {
public:
    void findsubsetsdup(int ind, vector<int> &temp, vector<vector<int>>& ans, map<vector<int>, int>& track, vector<int> nums){
        //map contains the subsets if found, it wont push to ans
        //if not found, adds to map and when dup found it wont push it
        if(track.find(temp) == track.end()){
            track[temp]++;
            ans.push_back(temp);
        }
        if(ind == nums.size()) {
            return ;
        }
        temp.push_back(nums[ind]);
        findsubsetsdup(ind+1, temp, ans, track, nums);
        temp.pop_back();
        findsubsetsdup(ind+1, temp, ans, track, nums);
    }   
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        map<vector<int>, int> track;
        vector<int> temp;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        findsubsetsdup(0, temp, ans, track, nums);

        return ans;
    }
};