class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int, int> indmap;
        int i=0;
        for(auto num:arr) indmap[num] = i++;
        int maxres = INT_MIN;
        int minres1 = INT_MAX, minres2 = INT_MAX;
        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                maxres = max(indmap[mat[i][j]], maxres);
                cout<<"max"<<maxres;
            }
            minres1 = min(maxres, minres1);
            cout<<'\n'<<minres1;
            maxres = INT_MIN;
        }
        for(int i=0;i<mat[0].size();i++){
            for(int j=0;j<mat.size();j++){
                maxres = max(indmap[mat[j][i]], maxres);
                cout<<"max"<<maxres;
            }
            minres2 = min(maxres, minres2);
            cout<<'\n'<<minres2;
            maxres = INT_MIN;
        }
        return min(minres1, minres2);
    }
};