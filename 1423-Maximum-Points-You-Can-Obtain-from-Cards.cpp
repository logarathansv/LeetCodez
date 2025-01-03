class Solution {
public:
    // void findmax(int find, int lind,int ct, vector<int>& cardPoints, int k, int& maxi, int sum){
    //     if(ct == k){
    //         maxi = max(sum, maxi);
    //         return;
    //     }
    //     findmax(find + 1, lind, ct+1, cardPoints, k, maxi, sum + cardPoints[find]);
    //     findmax(find, lind-1, ct+1, cardPoints, k, maxi , sum + cardPoints[lind]);
    // }
    int maxScore(vector<int>& cardPoints, int k) {
        int maxi = 0;
        // findmax(0, cardPoints.size()-1, 0, cardPoints, k, maxi, 0);
        int lsum = 0;
        for(int i=0;i<k;i++) lsum += cardPoints[i];
        maxi = lsum;
        for(int i=0;i<k;i++){
            lsum -= cardPoints[k-i-1];
            lsum += cardPoints[cardPoints.size()-i-1];

            maxi = max(maxi, lsum);
        }
        return maxi;
    }
};