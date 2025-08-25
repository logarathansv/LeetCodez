class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> count;
        for (char task : tasks) {
            count[task]++;
        }
        
        priority_queue<int> maxHeap;
        for (auto& entry : count) {
            maxHeap.push(entry.second);
        }
        
        int time = 0;
        queue<pair<int, int>> q; // {count, idleTime}
        
        while (!maxHeap.empty() || !q.empty()) {
            time++;
            
            if (!maxHeap.empty()) {
                int cnt = maxHeap.top();
                maxHeap.pop();
                cnt--;
                if (cnt > 0) {
                    q.push({cnt, time + n});
                }
            }
            
            if (!q.empty() && q.front().second == time) {
                maxHeap.push(q.front().first);
                q.pop();
            }
        }
        
        return time;
    }
};
