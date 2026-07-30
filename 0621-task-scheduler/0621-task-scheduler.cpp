class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        priority_queue<int> pq;
        int time=0;

        unordered_map<char, int> freq;
        for(auto i:tasks){
            freq[i]++;
        }

        for(auto i:freq){
            pq.push(i.second);
        }

        while(!pq.empty()){
            int cycle = n+1;
            int taskct = 0;
            vector<int> store;

            while(!pq.empty() && cycle--){
                if(pq.top() > 1){
                    store.push_back(pq.top() - 1);
                }
                pq.pop();
                taskct++;
            }

            for(auto i:store) pq.push(i);
            time += (pq.empty() ? taskct : n+1);
        }

        return time;
    }
};