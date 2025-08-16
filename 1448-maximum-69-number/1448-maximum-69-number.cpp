class Solution {
public:
    int maximum69Number (int num) {
        vector<int> ans;

        while(num > 0){
            ans.push_back(num%10);
            num /= 10;
        }

        for(int i=ans.size()-1;i>=0;i--){
            if(ans[i] == 6) {ans[i] += 3;break;}
        }

        reverse(ans.begin(), ans.end());

        num = 0;    
        for(auto n : ans) num = num*10 + n;

        return num;
    }
};