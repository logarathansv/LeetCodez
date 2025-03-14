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
        int maxi = INT_MIN;
        for(auto candy : candies){
            sum += candy;
            maxi = max(maxi, candy);
        }
        if(sum < k) return 0;
        int l = 1, r = sum/k;
        while(l<=r){
            int mid = (l + r)/2;
            if(isPossible(candies, k, mid)) l = mid + 1;
            else r = mid - 1;
        }
        return r;
    }
};