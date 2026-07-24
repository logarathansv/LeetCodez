class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        unordered_map<int, int> mp;
        int l = 0, len = 0;

        for(int i=0;i<fruits.size();i++){
            mp[fruits[i]]++;
            if(mp.size() > 2){
                mp[fruits[l]]--;
                if(mp[fruits[l]] == 0){
                    mp.erase(fruits[l]);
                } 
                l++;
            }

            len = max(len, i-l+1);
        }

        return len;
    }
};