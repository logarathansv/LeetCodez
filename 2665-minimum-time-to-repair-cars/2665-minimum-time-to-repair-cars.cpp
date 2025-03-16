class Solution {
public:
    long long isPossible(vector<int>& ranks, int cars, long long time){
        long long ct = 0;
        for(int i=0;i<ranks.size();i++){
            ct += sqrt(time / ranks[i]);
        }
        return ct;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        long long l = 1;
        long long r = 1LL * *min_element(ranks.begin(), ranks.end()) * cars * cars;
        while(l < r){
            long long mid = (l + r)/2;
            if(isPossible(ranks, cars, mid) >= cars) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};