class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        unordered_map<int, int> mp;

        for(int top:tops) mp[top]++;
        for(int bottom:bottoms) mp[bottom]++;

        vector<int> tocheck;
        
        tocheck.push_back(tops[0]);
        tocheck.push_back(bottoms[0]);


        for(int ele:tocheck){
            bool f = 0;
            int rep1 = 0;
            int rep2 = 0;

            for(int i=0;i<tops.size();i++){
                if(tops[i] != ele && bottoms[i] == ele) {
                    rep1++;
                }
                else if(!(tops[i] == ele || bottoms[i] == ele)){
                    f=1;break;
                }
            }
            for(int i=0;i<tops.size();i++){
                if(bottoms[i] != ele && tops[i] == ele) {
                    rep2++;
                }
                else if(!(tops[i] == ele || bottoms[i] == ele)){
                    f=1;break;
                }
            }
            if(f == 0) return min(rep1, rep2);
        }

        return -1;
    }
};