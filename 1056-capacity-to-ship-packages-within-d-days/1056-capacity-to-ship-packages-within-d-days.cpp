class Solution {
public:
    int canship(vector<int>& weights, int days, int cap){
        int d = 1;
        int sum = 0;

        for(auto w : weights){
            if(sum + w > cap){
                sum = 0;
                d++;
            }
            sum += w;
        }

        return d;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int sum = 0;

        for(auto weigh : weights) sum += weigh;

        int l = *max_element(weights.begin(), weights.end()), h = sum;

        while(l <= h){
            int mid = (l + h)/2;

            int pos = canship(weights, days, mid);
            if(pos <= days){
                h = mid - 1;
            }
            else l = mid + 1;
        }

        return l;
    }
};