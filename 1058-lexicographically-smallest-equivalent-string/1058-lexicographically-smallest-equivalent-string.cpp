class Solution {
public:
    char dfs(char node, vector<int>& vis, unordered_map<char, vector<char>>& mp){
        vis[node - 'a'] = 1;

        char minc = node;
        for(auto neigh : mp[node]){
            if(!vis[neigh - 'a']) minc = min(minc, dfs(neigh, vis, mp));
        }

        return minc;
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        unordered_map<char, vector<char>> mp;

        for(int i=0;i<s1.size();i++){
            char u = s1[i];
            char v = s2[i];

            mp[u].push_back(v);
            mp[v].push_back(u);
        }

        string ans = "";


        for(int i=0;i<baseStr.size();i++){
            vector<int> vis(26, 0);

            ans += dfs(baseStr[i], vis, mp);
        }

        return ans;
    }
};