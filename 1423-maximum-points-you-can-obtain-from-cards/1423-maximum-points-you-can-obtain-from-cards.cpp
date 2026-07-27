class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        if(k == cardPoints.size()) return accumulate(cardPoints.begin(), cardPoints.end(), 0);
        int maxi = INT_MIN;
        int sum = accumulate( cardPoints.begin(), cardPoints.begin()+k, 0);
        int n = cardPoints.size();
        for(int i=0;i<k;i++){
            maxi = max(maxi, sum);
            sum -= cardPoints[k-i-1];
            sum += cardPoints[n-i-1];
        }

        return max(sum, maxi);
    }
};