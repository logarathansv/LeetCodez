class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int i = 0, j = 0;
        int ct = 0;

        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());

        for(int i=0;i<players.size();i++){
            while(j < trainers.size()){
                if(players[i] <= trainers[j++]) {ct++;break;}
                
            }
        }

        return ct;
    }
};