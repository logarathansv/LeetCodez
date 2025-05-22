class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        priority_queue<int> pq;
        sort(queries.begin(), queries.end(),
            [](const vector<int>& a, const vector<int>& b){
                return a[0] < b[0];
            });
        vector<int> d(nums.size() + 1, 0);

        int op = 0, j = 0;

        for(int i=0;i<nums.size();i++){
            op += d[i];
            while(j < queries.size() && queries[j][0] == i){
                pq.push(queries[j][1]);
                j++;
            }
            while(op < nums[i] && !pq.empty() && pq.top() >= i){
                op ++;
                d[pq.top() + 1] -= 1;
                pq.pop();
            }
            if(op < nums[i]) return -1;

        }
        return pq.size();
    }
};