class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long, vector<long>, greater<long>> pq;
        int ct = 0;
        for(auto num:nums){
            pq.push(num);
        }
        cout<<pq.size();
        while(pq.top() < k){
            long long topelement = pq.top();
            cout<<"top 1"<<topelement<<'\n';
            pq.pop();
            cout<<"size "<<pq.size();
            long long top2element = pq.top();
            cout<<"top 2"<<top2element<<'\n';
            pq.pop();
            cout<<"size "<<pq.size();
            long long newelement = (min(topelement, top2element) * 2) + max(topelement, top2element);
            pq.push(newelement);
            ct++;
        }
        return ct;
    }
};