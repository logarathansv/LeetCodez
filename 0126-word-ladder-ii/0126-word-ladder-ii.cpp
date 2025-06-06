class Solution {
public:
    void dfs(vector<string>& sq, unordered_map<string, int>& mp, string beginWord,
             string word, vector<vector<string>>& ans) {
        if (word == beginWord) {
            reverse(sq.begin(), sq.end());
            ans.push_back(sq);
            reverse(sq.begin(), sq.end());
            return;
        }
        
        int step = mp[word];
        for (int i = 0; i < word.size(); i++) {
            char ch = word[i];
            for (char j = 'a'; j <= 'z'; j++) {
                word[i] = j;
                if (mp.count(word) && mp[word] + 1 == step) {
                    sq.push_back(word);
                    dfs(sq, mp, beginWord, word, ans);
                    sq.pop_back();
                }
            }
            word[i] = ch;
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord,
                                       vector<string>& wordList) {
        vector<bool> vis(wordList.size() + 1, false);
        unordered_set<string> st(wordList.begin(), wordList.end());
        unordered_map<string, int> mp;

        queue<string> q;
        q.push(beginWord);
        mp[beginWord] = 1;
        st.erase(beginWord);

        vector<vector<string>> ans;

        while (!q.empty()) {
            string word = q.front();
            q.pop();
            int stp = mp[word];

            if (word == endWord)
                break;

            for (int i = 0; i < word.size(); i++) {
                char ch = word[i];
                for (char j = 'a'; j <= 'z'; j++) {
                    word[i] = j;
                    if (st.find(word) != st.end()) {
                        q.push(word);
                        st.erase(word);
                        mp[word] = stp + 1;
                    }
                }
                word[i] = ch;
            }
        }

        if (mp.count(endWord)) {
            vector<string> sq = {endWord};
            dfs(sq, mp, beginWord, endWord, ans);
        }

        return ans;
    }
};