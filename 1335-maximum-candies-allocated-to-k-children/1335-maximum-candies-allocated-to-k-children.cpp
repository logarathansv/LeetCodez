class Solution {
public:
    bool isPossible(vector<int> candies, long long k, int mid){
        for(int i=0;i<candies.size() && k > 0;i++){
            int div = candies[i] / mid;
            k -= div;
            candies[i] -= (long long)div*candies[i];
        }
        return k <= 0;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        long long sum = 0;
        for(auto candy : candies){
            sum += candy;
        }
        if(sum < k) return 0;
        int maxi = *max_element(candies.begin(), candies.end());
        int l = 1, r = maxi;
        while(l<=r){
            int mid = (l + r)/2;
            if(isPossible(candies, k, mid)) l = mid + 1;
            else r = mid - 1;
        }
        return r;
    }
};