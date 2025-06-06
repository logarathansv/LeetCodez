class Solution {
public:
    bool isOneLetterDiff(const string& a, const string& b) {
        int diff = 0;
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] != b[i])
                diff++;
            if (diff > 1)
                return false;
        }
        return diff == 1;
    }

    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        int ct = 0;
        vector<vector<int>> adj(wordList.size() + 1);

        for (int i = 0; i < wordList.size(); i++) {
            if (isOneLetterDiff(beginWord, wordList[i])){
                // cout<<"first"<<i+1<<'\n';
                adj[0].push_back(i+1);
                adj[i+1].push_back(0);
            }
        }

        for (int i = 0; i < wordList.size(); i++) {
            for (int j=i+1;j<wordList.size();j++) {
                if (isOneLetterDiff(wordList[j], wordList[i])){
                    // cout<<"then"<<i+1<<" "<<j+1<<'\n';
                    adj[j+1].push_back(i+1);
                    adj[i+1].push_back(j+1);
                }
            }
        }

        queue<pair<int, int>> q;
        q.push({0,0});

        vector<bool> vis(wordList.size() + 1, false);
        vis[0] = true;

        while(!q.empty()){
            auto tp = q.front();
            q.pop();
            int ele = tp.first;
            int dep = tp.second;   

            string currentWord = (ele == 0) ? beginWord : wordList[ele - 1];
            if (currentWord == endWord)
                return dep + 1;

            for(auto neigh: adj[ele]){
                if(!vis[neigh]){
                    vis[neigh] = 1;
                    q.push({neigh, dep + 1});
                }
            }
        }

        return 0;
    }
};