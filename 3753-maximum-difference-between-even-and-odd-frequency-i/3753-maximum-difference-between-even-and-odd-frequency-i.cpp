class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int> mp;

        for(auto ch : s){
            mp[ch]++;
        }

        int mineven = INT_MAX, maxodd = INT_MIN;

        for(auto ch : mp){
            if(ch.second % 2 == 0) {
                mineven = min(mineven, ch.second);
            }
            else {
                maxodd = max(maxodd, ch.second);
            }
        } 

        return maxodd - mineven;
    }
};