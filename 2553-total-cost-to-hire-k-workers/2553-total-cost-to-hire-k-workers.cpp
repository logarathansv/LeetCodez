class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long sum = 0;

        priority_queue<int, vector<int>, greater<int>> pq, pq2;
        int l, r;
        int n = costs.size();

        for(l = 0;l<candidates;l++) pq.push(costs[l]);
        for(r = max(candidates, n - candidates);r < costs.size();r++) pq2.push(costs[r]);

        r = costs.size() - candidates - 1;

        for(int i=0;i<k;i++){
            if(pq2.empty() || !pq.empty() && pq.top() <= pq2.top()) {
                sum += pq.top();
                pq.pop();
                if(l <= r) pq.push(costs[l++]);
            }
            else {
                sum += pq2.top();
                pq2.pop();
                if(l <= r) pq2.push(costs[r--]);
            }

            cout<<sum<<" ";
        }

        return sum;
    }
};