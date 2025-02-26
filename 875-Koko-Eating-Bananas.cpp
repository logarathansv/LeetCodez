class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = 1000000000;
        int mid;
        while(low <= high){
            mid = (low+high)/2;
            if(canEat(piles, mid, h)) high = mid - 1;
            else low = mid+1;
        }
        return low;
    }
    bool canEat(vector<int>& piles, int k, int h){
        long hr = 0;
        for(auto pile : piles){
            int div = pile / k;
            hr += div;
            if(pile % k) hr++;
        }
        return hr <= h;
    }
};