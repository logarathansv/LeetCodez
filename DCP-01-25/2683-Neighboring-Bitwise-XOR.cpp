class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int x_or = 0;
        for(int i=0;i<derived.size();i++){
            x_or = x_or^derived[i];
        }
        return !x_or;
    }
};