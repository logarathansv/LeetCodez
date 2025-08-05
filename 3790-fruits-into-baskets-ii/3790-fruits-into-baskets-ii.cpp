class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int ans = 0;
        if(fruits.size() == 1 && baskets.size() == 1) {
            if(fruits[0] <= baskets[0]) return 0;
            return 1;
        }
        for(int i=0;i<fruits.size();i++){
            for(int j=0;j<baskets.size();j++){
                if(fruits[i] <= baskets[j]){
                    fruits[i] -= fruits[i];
                    baskets[j] -= baskets[j];
                    break;
                }
            }
        }
        int j=0;
        for(int i=0;i<fruits.size();i++){
            if(fruits[i] != 0) {
                ans++;
            }
        }
        return ans;
    }
};