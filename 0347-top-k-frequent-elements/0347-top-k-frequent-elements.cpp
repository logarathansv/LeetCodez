class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int ,int> mp;

        for(auto ele:nums) mp[ele]++;

        priority_queue<pair<int, int>> pq;

        for(auto ele: mp){
            pq.push({ele.second, ele.first});
        }
            

        vector<int> ans;

        for(int i=0;i<k;i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};