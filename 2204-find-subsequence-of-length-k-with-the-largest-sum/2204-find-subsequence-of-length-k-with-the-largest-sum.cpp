class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<int> pq;

        for(auto num : nums) pq.push(num);

        vector<int> ans;
        unordered_map<int, int> mp;

        for(int i=0;i<k;i++){
            mp[pq.top()]++;
            pq.pop();
        }

        for(auto num : nums) {
            if(mp.find(num) != mp.end()){
                ans.push_back(num);
                mp[num]--;
                if(mp[num] == 0) mp.erase(num);
            }
        }

        return ans;
    }
};