class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;
        long long score = 0;

        for(auto ele:nums){
            pq.push(ele);
        }

        for(int j=0;j<k;j++){
            int temp = pq.top();
            pq.pop();
            score += temp;
            
            pq.push((temp+2)/3);
        }

        return score;
    }
};