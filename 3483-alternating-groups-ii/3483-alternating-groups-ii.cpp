class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int ct = 0, ans = 0;
        int flag = colors[0];
        int n = colors.size();
        for(int i=0;i<2*n;i++){
            if(flag == 0 && colors[i%n] == 1) flag = 1;
            else if(flag == 1 && colors[i%n] == 0) flag = 0;
            else {
                ct = 0;
                if(i == n) break;
            }
            if(i>=n+k-1) break;
            ct++;
            if(ct == k){
                ans++;
                ct--;
            }
            
        }
        return ans;
    }
};