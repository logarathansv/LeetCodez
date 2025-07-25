class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        int sum = accumulate(skill.begin(), skill.end(), 0);
        int n = skill.size();int sum2 = sum, check = 0;

        sum = sum / (n/2);
        unordered_map<int, int> mp;
        vector<pair<int, int>> pairs;

        for(auto num:skill){
            if(mp.find(sum - num) != mp.end()){
                int tar = sum - num;

                pairs.push_back({num, tar});
                mp[tar]--;
                if(mp[tar] == 0) mp.erase(tar);
            }
            else mp[num]++;
        }

        long long ans = 0;

        for(auto pair:pairs) {ans += (pair.first * pair.second);check++;}

        return n/2 == check ? ans : -1;
    }
};