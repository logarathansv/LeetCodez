class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int b = 0, w = 0;
        int mini = INT_MAX, l = 0;
        for(int i=0;i<blocks.size();i++){
            (blocks[i] == 'W') ? w++ : b++;
            if(w+b == k){
                cout<<w<<" ";
                mini = min(mini, w);
                blocks[l++] == 'W' ? w-- : b--;
            }
        }
        return mini;
    }
};